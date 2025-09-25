# IOCTL_CDROM_GET_PERFORMANCE IOCTL

## Description

Retrieves the supported speeds from the device. The **IOCTL_CDROM_GET_PERFORMANCE**
I/O control request is a wrapper over the MMC command, GET PERFORMANCE.

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
function with **IOCTL_CDROM_GET_PERFORMANCE** as the *dwIoControlCode* parameter.

## Parameters

### Major code

### Input buffer

[CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request) requests performance data.
[CDROM_WRITE_SPEED_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_write_speed_request) requests write speed descriptor.

### Input buffer length

Length of a [CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request).

### Output buffer

For request type CdromWriteSpeedRequest, this IOCTL returns the [CDROM_PERFORMANCE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header) structure followed by a number of CDROM_WRITE_SPEED_DESCRIPTOR descriptors.

For request type CdromPerformanceRequest, this IOCTL returns the [CDROM_PERFORMANCE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header) structure followed by an optional descriptor. The descriptor following this header depends on the value in the **Except** field of the **CDROM_PERFORMANCE_HEADER** structure. If **Except** is false, CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR is used; otherwise, CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR is used.

### Output buffer length

Length of a [CDROM_PERFORMANCE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned.

Because of status code propagation from other APIs, the **Status** field can be set to (but is not limited to) the following:

**STATUS_BUFFER_TOO_SMALL**

The output buffer length is smaller than required.

**STATUS_INFO_LENGTH_MISMATCH**

The input buffer length is smaller than required.

**STATUS_INVALID_DEVICE_REQUEST**

The device does not support this request.

**STATUS_INVALID_PARAMETER**

The CDROM_PERFORMANCE_REQUEST header does not contain a valid combination of parameters specified by enumerations.

**STATUS_SUCCESS**

The request completed successfully.

## See also

[CDROM_PERFORMANCE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header)

[CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request)

[CDROM_WRITE_SPEED_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_write_speed_request)

[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)