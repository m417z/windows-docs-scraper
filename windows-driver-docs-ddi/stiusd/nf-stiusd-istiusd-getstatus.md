# IStiUSD::GetStatus

## Description

A still image minidriver's **IStiUSD::GetStatus** method returns the status of a still image device.

## Parameters

### `pDevStatus`

Caller-supplied pointer to an [STI_DEVICE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_status) structure.

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The caller supplies values for the **dwSize** and **StatusMask** members of the [STI_DEVICE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_status) structure, and the minidriver must supply values for the rest of the structure members.

If the driver has previously set the STI_GENCAP_POLLING_NEEDED flag in the device's [STI_DEV_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_dev_caps) structure, the minidriver's **IStiUSD::GetStatus** method is the means by which the event monitor determines if a [Still Image Device Events](https://learn.microsoft.com/windows-hardware/drivers/image/still-image-device-events) has occurred. The event monitor will call the method, specifying STI_DEVSTATUS_EVENT_STATE in the supplied [STI_DEVICE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_status) structure. The driver must poll the device and set STI_EVENTHANDLING_PENDING if an event has occurred.

If the caller specifies STI_DEVSTATUS_ONLINE_STATE in the supplied STI_DEVICE_STATUS structure, the minidriver should set the appropriate flag in the structure's **dwOnlineState** member.

## See also

[IStiDevice::GetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-getstatus)

[IStiUSD](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)