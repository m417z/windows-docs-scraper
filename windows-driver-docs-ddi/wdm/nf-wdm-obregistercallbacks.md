# ObRegisterCallbacks function

## Description

The **ObRegisterCallbacks** routine registers a list of callback routines for thread, process, and desktop handle operations.

## Parameters

### `CallbackRegistration` [in]

A pointer to an [OB_CALLBACK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_callback_registration) structure that specifies the list of callback routines and other registration information.

### `RegistrationHandle` [out]

A pointer to a variable that receives a value that identifies the set of registered callback routines. The caller passes this value to the [ObUnRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obunregistercallbacks) routine to unregister the set of callbacks.

## Return value

**ObRegisterCallbacks** returns an NTSTATUS value. This routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The specified callback routines are registered with the system. |
| **STATUS_FLT_INSTANCE_ALTITUDE_COLLISION** | The calling driver or another driver has already registered callback routines for the altitude that *CallBackRegistration*->**Altitude** specifies. For more information about this altitude, see the description of the **Altitude** member in [OB_CALLBACK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_callback_registration). |
| **STATUS_INVALID_PARAMETER** | One or more of the parameters that were specified in the registration was invalid. **ObRegisterCallbacks** might return this error, for example, if an invalid value for *CallBackRegistration*->**Version** is specified or if registration is attempted for object types that do not support callback routines. |
| **STATUS_ACCESS_DENIED** | The callback routines do not reside in a signed kernel binary image. |
| **STATUS_INSUFFICIENT_RESOURCES** | An attempt to allocate memory failed. |

## Remarks

A driver must unregister all callback routines before it unloads. You can unregister the callback routine by calling the **ObUnRegisterCallbacks** routine.

## See also

[OB_CALLBACK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_callback_registration)

[ObUnRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obunregistercallbacks)