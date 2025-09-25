# KsCreateClock2 function

## Description

Creates a handle to a clock instance. Call this function after the Component Object Model (COM) is initialized.

Supported starting in Windows 8.

## Parameters

### `ConnectionHandle` [in]

Specifies the handle to the connection on which to create the clock.

### `ClockCreate` [in]

Specifies clock create parameters. This currently consists of a flag that must be set to zero.

### `ClockHandle` [out]

Specifies the new clock handle.

## Return value

Returns **NOERROR** if successful; otherwise, returns an error code.

## Remarks

This is a new version of the [KsCreateClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreateclock) function and uses the device broker to create the handle to the kernel streaming object. In addition, the COM [CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize) function must be called before this function is called.

## See also

[CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize)

[KsCreateClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreateclock)