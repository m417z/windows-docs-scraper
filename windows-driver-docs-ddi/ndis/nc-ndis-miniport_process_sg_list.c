MINIPORT_PROCESS_SG_LIST MiniportProcessSgList;

VOID MiniportProcessSgList(
  [in] PDEVICE_OBJECT pDO,
  [in] PVOID Reserved,
  [in] PSCATTER_GATHER_LIST pSGL,
  [in] PVOID Context
)
{...}