# IDARG_OUT_PARSEMONITORDESCRIPTION structure

## Description

The **IDARG_OUT_PARSEMONITORDESCRIPTION** structures provides information about the number of monitor modes and preferred monitor mode of a monitor.

## Members

### `MonitorModeBufferOutputCount`

[out] If the **pMonitorModes** value of [**IDARG_IN_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription) - or [**IDARG_IN_PARSEMONITORDESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription2) for HDR support - is NULL, then the driver should set **MonitorModeBufferOutputCount** to the number of monitor modes the driver would generate for the specified monitor description. If **pMonitorModes** is non-NULL then **MonitorModeBufferOutputCount** specifies the count of the monitor modes that the driver copied to the buffer that **pMonitorModes** points to.

### `PreferredMonitorModeIdx`

[out] Index into the **pMonitorModes** array of the preferred mode monitor mode. The driver can set this value to **NO_PREFERRED_MODE** to indicate that there is no preferred monitor mode.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description)

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description2)

[**IDARG_IN_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription)

[**IDARG_IN_PARSEMONITORDESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription2)