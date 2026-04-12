EVT_IDD_CX_MONITOR_I2C_TRANSMIT_AND_RECEIVE EvtIddCxMonitorI2cTransmitAndReceive;

NTSTATUS EvtIddCxMonitorI2cTransmitAndReceive(
  [in] IDDCX_MONITOR MonitorObject,
  [in] const IDARG_IN_I2C_TRANSMIT_AND_RECEIVE *pInArgs
)
{...}