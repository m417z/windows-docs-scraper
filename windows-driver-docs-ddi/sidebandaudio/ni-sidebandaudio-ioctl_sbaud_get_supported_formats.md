# IOCTL_SBAUD_GET_SUPPORTED_FORMATS IOCTL

## Description

The audio driver issues the **IOCTL_SBAUD_GET_SUPPORTED_FORMATS** control code to get information about the stream formats supported by sideband audio endpoint.

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

[SIDEBANDAUDIO_SUPPORTED_FORMATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_supported_formats) containing endpoint index, and array of formats supported by the Audio driver.

### Input buffer length

Size of [SIDEBANDAUDIO_SUPPORTED_FORMATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_supported_formats) including storage for array of formats.

### Output buffer

[SIDEBANDAUDIO_SUPPORTED_FORMATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_supported_formats). The sideband driver will return the intersection of the sideband audio formats with the formats supplied by the audio driver as an input parameter.

### Output buffer length

Size of [SIDEBANDAUDIO_SUPPORTED_FORMATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_supported_formats) including storage for array of formats.

### Input/output buffer

### Input/output buffer length

### Status block

If the routine succeeds, then Status is set to STATUS_SUCCESS and the *Information* member is the number of bytes that the routine writes to the output buffer.

If Status is set to STATUS_BUFFER_TOO_SMALL, then the audio driver should read the *Information* member to get the size of the buffer that the caller should allocate for this request.

## Remarks

This IOCTL can only be called from kernel mode.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[SIDEBANDAUDIO_SUPPORTED_FORMATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_supported_formats)

[Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)