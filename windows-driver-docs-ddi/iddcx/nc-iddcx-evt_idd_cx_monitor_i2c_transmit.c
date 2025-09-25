EVT_IDD_CX_MONITOR_I2C_TRANSMIT EvtIddCxMonitorI2cTransmit;

NTSTATUS EvtIddCxMonitorI2cTransmit(
  [in] IDDCX_MONITOR MonitorObject,
  [in] const IDARG_IN_I2C_TRANSMIT *pInArgs
)
{...}