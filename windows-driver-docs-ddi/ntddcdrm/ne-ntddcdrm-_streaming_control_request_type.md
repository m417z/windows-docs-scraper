# _STREAMING_CONTROL_REQUEST_TYPE enumeration

## Description

The STREAMING_CONTROL_REQUEST_TYPE enumeration defines the CDROM streaming modes. This enumeration is a member of the [CDROM_STREAMING_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_streaming_control) structure, the input parameter to the [IOCTL_CDROM_ENABLE_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_enable_streaming) I/O control code, which is used to enable or disable CDROM streaming.

## Constants

### `CdromStreamingDisable`

Streaming read and streaming write requests will be disabled for the requested file handle.

### `CdromStreamingEnableForReadOnly`

Streaming read requests will be enabled, and streaming write requests will be disabled, for the requested file handle.

### `CdromStreamingEnableForWriteOnly`

Streaming read requests will be disabled, and streaming write requests will be enabled, for the requested file handle.

### `CdromStreamingEnableForReadWrite`

Streaming read and streaming write requests will be enabled for the requested file handle.

## See also

[CDROM_STREAMING_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_streaming_control)

[IOCTL_CDROM_ENABLE_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_enable_streaming)