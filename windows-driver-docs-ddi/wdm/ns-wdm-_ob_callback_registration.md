# _OB_CALLBACK_REGISTRATION structure

## Description

The **OB_CALLBACK_REGISTRATION** structure specifies the parameters when the [ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks) routine registers [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) and [ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback) callback routines.

## Members

### `Version`

The version of object callback registration that is requested. Drivers should specify OB_FLT_REGISTRATION_VERSION.

### `OperationRegistrationCount`

The number of entries in the **OperationRegistration** array.

### `Altitude`

A Unicode string that specifies the altitude of the driver. For more information about altitude, see [Load Order Groups and Altitudes for Minifilter Drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/load-order-groups-and-altitudes-for-minifilter-drivers).

### `RegistrationContext`

The system passes the **RegistrationContext** value to the callback routine when the callback routine is run. The meaning of this value is driver-defined.

### `OperationRegistration`

A pointer to an array of [OB_OPERATION_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_operation_registration) structures. Each structure specifies [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) and [ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback) callback routines and the types of operations that the routines are called for.

## Remarks

This structure is used by the [ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks) routine. The *CallBackRegistration* parameter to this routine is a pointer to a buffer that contains an **OB_CALLBACK_REGISTRATION** structure that is followed by an array of one or more [OB_OPERATION_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_operation_registration) structures.

## See also

[OB_OPERATION_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_operation_registration)

[ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks)

[ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback)

[ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback)