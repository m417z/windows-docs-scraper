# IOCTL_BTHHFP_DEVICE_GET_CONTAINERID IOCTL

## Description

The **IOCTL_BTHHFP_DEVICE_GET_CONTAINERID**
IOCTL Gets the PnP Container ID of the Bluetooth device.

**Note** This IOCTL has been deprecated for Windows 8.1, so you should use [IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor) instead.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

A GUID that is the Container ID.

### Output buffer length

The size of a GUID.

### Input/output buffer

### Input/output buffer length

### Status block

N/A

## Remarks

This request completes immediately.

The audio driver stores this container ID in appropriate context data and returns it in the driver's implementation of the [KSPROPERTY_JACK_CONTAINERID](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-containerid) KS property.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor)

[KSPROPERTY_JACK_CONTAINERID](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-containerid)