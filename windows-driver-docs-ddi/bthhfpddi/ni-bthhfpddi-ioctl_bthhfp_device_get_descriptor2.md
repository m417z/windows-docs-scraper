# IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR2 IOCTL

## Description

The **IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR2**
IOCTL Gets descriptive information about the paired Handsfree profile (HFP) device.

This IOCTL is available in Windows 8.1 and later operating systems, and it supersedes [IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor).

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

A buffer containing a [BTHHFP_DESCRIPTOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ns-bthhfpddi-_bthhfp_descriptor2) structure followed by any other data that is referenced by the structure. This is true, if the output buffer size is sufficient and the request succeeds. In particular, the buffer includes storage for the string that is referenced by the *FriendlyName* field of the **BTHHFP_DESCRIPTOR2** structure.

### Output buffer length

The size of a **BTHHFP_DESCRIPTOR2** structure and referenced data.

### Input/output buffer

### Input/output buffer length

### Status block

If the routine succeeds, then Status is set to STATUS_SUCCESS and the *Information* member is the number of bytes that the routine writes to the output buffer. Note this can be larger than the size of the **BTHHFP_DESCRIPTOR2** structure, as the output buffer may contain other data referenced by the **BTHHFP_DESCRIPTOR2** structure.

If Status is set to STATUS_BUFFER_TOO_SMALL, then *Information* is the size of the buffer that the caller should allocate for this request.

## Remarks

The audio driver sends this request to obtain information about an enabled GUID_DEVINTERFACE_BLUETOOTH_HFP_SCO_HCIBYPASS device interface. The information does not change while the interface is enabled, but can change while the interface is disabled. Therefore the audio driver sends this request shortly after discovering an enabled device interface and uses the information to build an appropriate KSFILTER_DESCRIPTOR structure.

The audio driver sends this request once with an output buffer size of zero (0) in order to determine the required output buffer size. In this case, the request will complete with Status STATUS_BUFFER_TOO_SMALL and the *Information* parameter will contain the required buffer size. The audio driver then allocates the necessary storage and sends the request again. Typically an audio driver will keep a pointer to this storage location in its device context for reference during later activity.

## See also

[BTHHFP_DESCRIPTOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ns-bthhfpddi-_bthhfp_descriptor2)

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor)