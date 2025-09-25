# IDARG_IN_GETDEFAULTDESCRIPTIONMODES structure

## Description

 Gives information about the default monitor modes passed into the driver.

## Members

### `DefaultMonitorModeBufferInputCount` [in]

The number of monitor modes the **pDefaultsMonitorModes** buffer being passed into the driver can hold. A value of zero indicates that the driver should not copy the monitor mode list into the provided buffer, but should set the output buffer size to the size required.

### `pDefaultMonitorModes` [out]

 Pointer to the buffer that the driver should copy the monitor modes to if the value is non-NULL. If value is NULL, then driver should not copy any data and should just set **DefaultMonitorModeBufferOutputCount** to indicate the size of buffer required to store the modes.