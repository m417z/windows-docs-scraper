EVT_IDD_CX_MONITOR_I2C_RECEIVE EvtIddCxMonitorI2cReceive;

NTSTATUS EvtIddCxMonitorI2cReceive(
  [in] IDDCX_MONITOR MonitorObject,
  [in] const IDARG_IN_I2C_RECEIVE *pInArgs
)
{...}