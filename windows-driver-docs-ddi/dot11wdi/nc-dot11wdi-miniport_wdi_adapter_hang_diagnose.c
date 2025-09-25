MINIPORT_WDI_ADAPTER_HANG_DIAGNOSE MiniportWdiAdapterHangDiagnose;

NDIS_STATUS MiniportWdiAdapterHangDiagnose(
  [in]  NDIS_HANDLE MiniportDriverContext,
  [in]  eDiagnoseLevel DiagnoseLevel,
  [in]  UINT32 BufferSize,
  [out] UINT8 *FirmwareBlob,
  [out] UINT32 *pOutputSize
)
{...}