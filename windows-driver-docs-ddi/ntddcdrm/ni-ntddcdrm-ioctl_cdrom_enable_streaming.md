# IOCTL_CDROM_ENABLE_STREAMING IOCTL

## Description

Enables or disables CDROM streaming mode on a per-handle basis for raw read and write requests.

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
function and specify the **IOCTL_CDROM_ENABLE_STREAMING** I/O control request as the *dwIoControlCode* parameter.

## Parameters

### Major code

### Input buffer

[CDROM_STREAMING_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_streaming_control)

### Input buffer length

Length of a [CDROM_STREAMING_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_streaming_control).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned.

Because of status code propagation from other APIs, the **Status** field can be set to (but not limited to) the following:

**STATUS_INFO_LENGTH_MISMATCH**

The input buffer length is smaller than required.

**STATUS_INVALID_DEVICE_REQUEST**

The requested streaming mode is not supported.

**STATUS_INVALID_HANDLE**

Cannot find the file object context in the request.

**STATUS_INVALID_PARAMETER**

The request type is not one of the four in types defined in the **STREAMING_CONTROL_REQUEST_TYPE** enumeration.

**STATUS_SUCCESS**

The request completed successfully.

## Remarks

By default, streaming is disabled for all newly opened raw CDROM handles. A playback application that does not want to use the file system and prefers to work with raw data should open two file handles for the same device: a regular one for file system metadata and a streaming one for real-time files.

## See also

[CDROM_STREAMING_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_streaming_control)

[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)