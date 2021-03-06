//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2012 EMC Corp.
//
//	@filename:
//		CPhysicalDynamicTableScan.h
//
//	@doc:
//		Dynamic Table scan operator
//---------------------------------------------------------------------------
#ifndef GPOPT_CPhysicalDynamicTableScan_H
#define GPOPT_CPhysicalDynamicTableScan_H

#include "gpos/base.h"
#include "gpopt/operators/CPhysicalDynamicScan.h"

namespace gpopt
{
//---------------------------------------------------------------------------
//	@class:
//		CPhysicalDynamicTableScan
//
//	@doc:
//		Dynamic Table scan operator
//
//---------------------------------------------------------------------------
class CPhysicalDynamicTableScan : public CPhysicalDynamicScan
{
private:
public:
	CPhysicalDynamicTableScan(const CPhysicalDynamicTableScan &) = delete;

	// ctors
	CPhysicalDynamicTableScan(CMemoryPool *mp, BOOL is_partial,
							  const CName *pname, CTableDescriptor *ptabdesc,
							  ULONG ulOriginOpId, ULONG scan_id,
							  CColRefArray *colref_array,
							  CColRef2dArray *pdrgpdrgpcrParts,
							  ULONG ulSecondaryScanId,
							  CPartConstraint *ppartcnstr,
							  CPartConstraint *ppartcnstrRel);

	// ident accessors
	EOperatorId
	Eopid() const override
	{
		return EopPhysicalDynamicTableScan;
	}

	// return a string for operator name
	const CHAR *
	SzId() const override
	{
		return "CPhysicalDynamicTableScan";
	}

	// match function
	BOOL Matches(COperator *) const override;

	// statistics derivation during costing
	IStatistics *PstatsDerive(CMemoryPool *mp, CExpressionHandle &exprhdl,
							  CReqdPropPlan *prpplan,
							  IStatisticsArray *stats_ctxt) const override;

	// conversion function
	static CPhysicalDynamicTableScan *
	PopConvert(COperator *pop)
	{
		GPOS_ASSERT(NULL != pop);
		GPOS_ASSERT(EopPhysicalDynamicTableScan == pop->Eopid());

		return dynamic_cast<CPhysicalDynamicTableScan *>(pop);
	}

};	// class CPhysicalDynamicTableScan

}  // namespace gpopt

#endif	// !GPOPT_CPhysicalDynamicTableScan_H

// EOF
