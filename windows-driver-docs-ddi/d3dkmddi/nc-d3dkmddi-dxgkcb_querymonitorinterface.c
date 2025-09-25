DXGKCB_QUERYMONITORINTERFACE DxgkcbQuerymonitorinterface;

NTSTATUS DxgkcbQuerymonitorinterface(
  [in]  IN_CONST_HANDLE hAdapter,
  [in]  IN_CONST_DXGK_MONITOR_INTERFACE_VERSION MonitorInterfaceVersion,
  [out] DEREF_OUT_CONST_PPDXGK_MONITOR_INTERFACE ppMonitorInterface
)
{...}