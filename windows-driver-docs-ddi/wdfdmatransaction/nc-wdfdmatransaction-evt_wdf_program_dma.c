EVT_WDF_PROGRAM_DMA EvtWdfProgramDma;

BOOLEAN EvtWdfProgramDma(
  [in] WDFDMATRANSACTION Transaction,
  [in] WDFDEVICE Device,
  [in] WDFCONTEXT Context,
  [in] WDF_DMA_DIRECTION Direction,
  [in] PSCATTER_GATHER_LIST SgList
)
{...}