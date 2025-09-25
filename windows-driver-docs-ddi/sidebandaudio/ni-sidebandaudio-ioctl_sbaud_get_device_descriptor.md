# IOCTL_SBAUD_GET_DEVICE_DESCRIPTOR

## Description

The audio driver issues the **IOCTL_SBAUD_GET_DEVICE_DESCRIPTOR** to get information about an enabled sideband audio device interface. Specifically this returns the number of Audio endpoints available on a device that supports Sideband. This information is returned in an [Audio device descriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_device_descriptor) structure.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

NULL.

### Input buffer length

0.

### Output buffer

A buffer containing a [SIDEBANDAUDIO_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_device_descriptor) structure.

### Output buffer length

The size of a **SIDEBANDAUDIO_DEVICE_DESCRIPTOR** structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the routine succeeds, then Status is set to STATUS_SUCCESS and the *Information* member is the number of bytes that the routine writes to the output buffer.

If Status is set to STATUS_BUFFER_TOO_SMALL, then the audio driver should read the *Information* member to get the size of the buffer that the caller should allocate for this request.

## Remarks

This IOCTL can only be called from kernel mode.

The audio driver sends this request to obtain information about an enabled Audio sideband device interface. The information does not change while the interface is enabled, but can change while the interface is disabled. The audio driver sends this request shortly after discovering an enabled sideband audio device interface and uses the information to determine how many sideband audio endpoints are available.

The audio driver sends this request once with an output buffer size of zero (0) in order to determine the required output buffer size. In this case, the request will complete with Status STATUS_BUFFER_TOO_SMALL and set the *Information* member to the required buffer size. The audio driver then allocates the necessary storage space and sends the request again. Typically an audio driver will store a pointer to this storage location in its device context for reference during later activity.

The audio driver can then iteratively determine each endpoints capability with the IOCTL [IOCTL_SBAUD_GET_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_endpoint_descriptor).

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)