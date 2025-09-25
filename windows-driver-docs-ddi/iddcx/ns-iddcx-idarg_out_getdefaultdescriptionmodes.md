# IDARG_OUT_GETDEFAULTDESCRIPTIONMODES structure

## Description

Gives information about the default description modes for the monitor, as well as the preferred mode of the monitor.

## Members

### `DefaultMonitorModeBufferOutputCount`

 [out] If the [IDARG_IN_PARSEMONITORDESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription) value **pDefaultMonitorModes** was NULL, then the driver should set this to the number of monitor modes the driver would generate for the specified monitor description.

 If the [IDARG_IN_PARSEMONITORDESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription) value **pDefaultMonitorModes** was non-NULL, then this is the count of the monitor modes that the driver copied to that buffer.

### `PreferredMonitorModeIdx`

 [out] Index into the **pMonitorModes** array of the preferred monitor mode. A value of **NO_PREFERRED_MODE** indicates that there is no preferred monitor mode.

## See also

[IDARG_IN_PARSEMONITORDESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription)