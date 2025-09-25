MINIPORT_WDI_ADAPTER_HANG_DIAGNOSE MiniportWdiAdapterHangDiagnose;

NDIS_STATUS MiniportWdiAdapterHangDiagnose(
  NDIS_HANDLE MiniportDriverContext,
  eDiagnoseLevel DiagnoseLevel,
  UINT32 BufferSize,
  UINT8 *FirmwareBlob,
  UINT32 *pOutputSize
)
{...}