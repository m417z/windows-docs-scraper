# _CDROM_WRITE_SPEED_DESCRIPTOR structure

## Description

The **CDROM_WRITE_SPEED_DESCRIPTOR** structure is returned for the [IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) IOCTL when the request type is **CdromWriteSpeedRequest**. The IOCTL returns the [CDROM_PERFORMANCE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header) followed by one or more descriptors of type **CDROM_WRITE_SPEED_DESCRIPTOR**.

## Members

### `MixedReadWrite`

The MixedReadWrite (MRW) field corresponds to the MRW bit of the Write Speed Descriptor in the MultiMedia Command Set - 6 (MMC-6)
specification. This field indicates that it is suitable for a mixture of streaming read and write requests (overwrite mode). The [STREAMING_CONTROL_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_streaming_control_request_type) enumeration specifies the type of request.

### `Exact`

The Exact field indicates whether the logical unit can perform the recording operation specified by CDM_WRITE_SPEED_DESCRIPTOR
on the whole medium mounted. This field corresponds to the Exact bit of the Write Speed Descriptor.

### `Reserved1`

Reserved fields.

### `WriteRotationControl`

The WriteRotationControl (WRC) field specifies the type of the rotation control for the medium.

### `Reserved2`

Reserved fields.

### `Reserved3`

Reserved fields.

### `EndLba`

The End Logical Block Address (EndLBA) field indicates the capacity of the medium if a medium is mounted. It corresponds to the EndLBA field of the Write Speed Descriptor.

### `ReadSpeed`

The ReadSpeed field indicates the lowest read performance data of all blocks (in kilobytes per second).

### `WriteSpeed`

The WriteSpeed field indicates the lowest write performance data of all blocks (in kilobytes per second).

## Remarks

The fields in the **CDROM_WRITE_SPEED_DESCRIPTOR** structure correspond to the fields defined in the MultiMedia Command Set - 6 (MMC-6)
specification for the Write Speed Descriptor.

## See also

[IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)

[STREAMING_CONTROL_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_streaming_control_request_type)