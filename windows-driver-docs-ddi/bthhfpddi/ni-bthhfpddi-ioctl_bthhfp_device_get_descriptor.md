# IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR IOCTL

## Description

The audio driver issues the **IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR**
control code to get information about an enabled GUID_DEVINTERFACE_BLUETOOTH_HFP_SCO_HCIBYPASS device interface.

**Note** This IOCTL supersedes [IOCTL_BTHHFP_DEVICE_GET_KSNODETYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_ksnodetypes) and [IOCTL_BTHHFP_DEVICE_GET_CONTAINERID](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_containerid) which have now been deprecated.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

A buffer containing a [BTHHFP_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ns-bthhfpddi-_bthhfp_descriptor) structure followed by any other data referenced by the structure. This is true, if the output buffer size is sufficient and the request succeeds. In particular, the buffer includes storage for the string referenced by the *FriendlyName* field of the **BTHHFP_DESCRIPTOR** structure.

### Output buffer length

The size of a **BTHHFP_DESCRIPTOR** structure and referenced data.

### Input/output buffer

### Input/output buffer length

### Status block

If the routine succeeds, then Status is set to STATUS_SUCCESS and the *Information* member is the number of bytes that the routine writes to the output buffer.

**Note** This can be larger than the size of the **BTHHFP_DESCRIPTOR** structure, as the output buffer may contain other data referenced by the structure

If Status is set to STATUS_BUFFER_TOO_SMALL, then the audio driver should read the *Information* member to get the size of the buffer that the caller should allocate for this request.

## Remarks

The audio driver sends this request to obtain information about an enabled GUID_DEVINTERFACE_BLUETOOTH_HFP_SCO_HCIBYPASS device interface. The information does not change while the interface is enabled, but can change while the interface is disabled. Therefore the audio driver sends this request shortly after discovering an enabled device interface and uses the information to build an appropriate KSFILTER_DESCRIPTOR structure.

The audio driver sends this request once with an output buffer size of zero (0) in order to determine the required output buffer size. In this case, the request will complete with Status STATUS_BUFFER_TOO_SMALL and set the *Information* member to the required buffer size. The audio driver then allocates the necessary storage space and sends the request again. Typically an audio driver will store a pointer to this storage location in its device context for reference during later activity.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[IOCTL_BTHHFP_DEVICE_GET_CONTAINERID](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_containerid)

[IOCTL_BTHHFP_DEVICE_GET_KSNODETYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_ksnodetypes)