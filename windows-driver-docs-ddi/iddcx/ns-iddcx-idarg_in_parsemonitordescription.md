# IDARG_IN_PARSEMONITORDESCRIPTION structure

## Description

 Gives information about the monitor description.

## Members

### `MonitorDescription`

 [in] Monitor description the driver should decode.

### `MonitorModeBufferInputCount`

 [in] The number of monitor modes the **pMonitorModes** buffer being passed into the driver can hold. A value of zero indicates that the driver should not copy the monitor mode list into the provided buffer, but should set the output buffer size to the size required.

### `pMonitorModes`

 [out] Pointer to buffer that the driver should copy the monitor modes to if the value is non-NULL. If value is NULL, then driver should not copy any data and should just set the [IDARG_OUT_PARSEMONITORDESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription) value **MonitorModeBufferOutputCount** to indicate the size of buffer required to store the modes.

## See also

[IDARG_OUT_PARSEMONITORDESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription)