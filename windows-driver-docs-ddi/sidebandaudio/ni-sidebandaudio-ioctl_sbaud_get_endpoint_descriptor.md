# IOCTL_SBAUD_GET_ENDPOINT_DESCRIPTOR IOCTL

## Description

The audio driver issues the **IOCTL_SBAUD_GET_ENDPOINT_DESCRIPTOR** control code to get information about an Audio endpoint exposed through sideband audio device interface.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

A 0 based endpoint index value based on the number of Audio endpoints as reported by the [IOCTL_SBAUD_GET_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_device_descriptor).

This is a ULONG value from 0 to (N-1) where N is the number of Endpoints for the device.

### Input buffer length

Size of ULONG.

### Output buffer

A buffer containing a [SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_endpoint_descriptor) structure followed by any other data referenced by the structure. This is returned, if the output buffer size is sufficient and the request succeeds. In particular, the buffer includes storage for the string referenced by the *FriendlyName* field of the **SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR** structure.

### Output buffer length

The size of a **SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR** structure and referenced data.

### Input/output buffer

### Input/output buffer length

### Status block

If the routine succeeds, then Status is set to STATUS_SUCCESS and the *Information* member is the number of bytes that the routine writes to the output buffer.

**Note** This can be larger than the size of the **SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR** structure, as the output buffer may contain other data referenced by the structure

If Status is set to STATUS_BUFFER_TOO_SMALL, then the audio driver should read the *Information* member to get the size of the buffer that the caller should allocate for this request.

## Remarks

This IOCTL can only be called from kernel mode.

The audio driver sends this request to obtain information about an enabled audio sideband endpoint. The information does not change while the interface is enabled, but can change while the interface is disabled. Therefore the audio driver sends this request shortly after discovering an enabled device interface and uses the information to build an appropriate KSFILTER_DESCRIPTOR structure.

The audio driver sends this request once with an output buffer size of zero (0) in order to determine the required output buffer size. In this case, the request will complete with Status STATUS_BUFFER_TOO_SMALL and set the *Information* member to the required buffer size. The audio driver then allocates the necessary storage space and sends the request again.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_endpoint_descriptor)

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)