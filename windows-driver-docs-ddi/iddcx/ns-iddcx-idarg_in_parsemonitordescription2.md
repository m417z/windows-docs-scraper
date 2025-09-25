## Description

The **IDARG_IN_PARSEMONITORDESCRIPTION2** structure contains input arguments for the [**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description2) callback function, which allows a driver to report extra information needed for HDR10 or WCG monitor modes.

## Members

### `MonitorDescription`

[in] An [**IDDCX_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_description) structure that describes the monitor.

### `MonitorModeBufferInputCount`

[in] The number of monitor modes that the **pMonitorModes** buffer being passed into the driver can hold. A value of zero indicates that the driver shouldn't copy the monitor mode list into the buffer that **pMonitorModes** points to, and should instead set the [**MonitorModeBufferOutputCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription) output value to indicate the size of buffer required to store the modes.

### `pMonitorModes`

[out] Pointer to a buffer of [**IDDCX_MONITOR_MODE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_mode2) structures in which the driver should copy the monitor modes to if the value is non-NULL. If **pMonitorModes** is NULL, the driver shouldn't copy the monitor mode list, and should instead set the [**MonitorModeBufferOutputCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription) output value to indicate the size of buffer required to store the modes.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description2)

[**IDARG_OUT_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription)

[**IDDCX_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_description)

[**IDDCX_MONITOR_MODE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_mode2)