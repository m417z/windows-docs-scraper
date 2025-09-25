# _PEP_REGISTER_DEVICE_V2 structure (pepfx.h)

## Description

The **PEP_REGISTER_DEVICE_V2** structure describes a device whose driver stack has just registered with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx).

## Members

### `DeviceId` [in]

A string that uniquely identifies the device. This member is a pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a [device identification string](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

### `KernelHandle` [in]

A POHANDLE value that represents the registration of the device with PoFx. The platform extension plug-in (PEP) previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the device's driver stack registered the device with PoFx.

### `Register` [in]

A pointer to a [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that describes the power management attributes of all the components in the device. For more information, see Remarks.

### `DeviceHandle` [out]

A PEPHANDLE value that the PEP creates to identify this device. PoFx will use this handle to identify the device in future [Device power management (DPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications).

### `DeviceAccepted` [out]

A [PEP_DEVICE_ACCEPTANCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_device_acceptance_type) enumeration value that indicates whether the PEP claims ownership of the device. The PEP that claims ownership is responsible for handling DPM notifications for the device.

## Remarks

This structure is used by the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification. The first three members of this structure contain input values supplied by PoFx. The last two members contain output values that the PEP writes to the structure in response to this notification.

The **Register** member contains a pointer to an input buffer allocated by PoFx. PoFx writes the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure and associated data to this structure before sending the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification to the PEP. The contents of this buffer remain valid only until the PEP finishes handling the notification and returns from the [AcceptDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifydpm) callback.

## See also

[AcceptDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifydpm)

[PEP_DEVICE_ACCEPTANCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_device_acceptance_type)

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)