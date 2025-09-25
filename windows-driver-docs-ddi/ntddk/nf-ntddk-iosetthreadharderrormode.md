# IoSetThreadHardErrorMode function

## Description

The **IoSetThreadHardErrorMode** routine enables or disables hard error reporting for the current thread.

## Parameters

### `EnableHardErrors` [in]

Specifies whether hard error reporting to the user should be enabled or disabled for this thread. A value of **TRUE** enables hard error reporting. **FALSE** disables it.

## Return value

**IoSetThreadHardErrorMode** returns **TRUE** if hard errors were enabled from this thread before this routine completed execution. Otherwise, this routine returns **FALSE**.

## Remarks

If hard errors are disabled for a given thread, calls to **IoRaiseHardError** will not display a message to the user indicating that a serious error has occurred. In addition, the IRP that is passed to **IoRaiseHardError** is completed without any data being copied into user buffers. Calling **IoRaiseInformationalHardError** after disabling hard errors causes that routine to always return **FALSE** for this thread.

## See also

[IoRaiseHardError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioraiseharderror)

[IoRaiseInformationalHardError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioraiseinformationalharderror)