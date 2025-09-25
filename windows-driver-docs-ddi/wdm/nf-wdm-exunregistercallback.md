# ExUnregisterCallback function

## Description

The **ExUnregisterCallback** routine removes a callback routine previously registered with a callback object from the list of routines to be called during the notification process.

## Parameters

### `CallbackRegistration` [in, out]

Specifies the callback routine to unregister. This must be the value returned by **ExRegisterCallback** when the callback was registered.

## Remarks

For more information about callback objects, see [Callback Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/callback-objects).

## See also

[ExCreateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatecallback)

[ExRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exregistercallback)