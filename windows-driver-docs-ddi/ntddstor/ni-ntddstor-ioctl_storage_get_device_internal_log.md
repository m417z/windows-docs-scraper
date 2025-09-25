# IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG IOCTL

## Major Code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

## Description

A driver can use **IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG** to get the internal status data from the device.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A [**GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-get_device_internal_status_data_request) structure that identifies the type of data to be queried.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= **sizeof(GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST)**.

### Output buffer

The driver returns output to the buffer at **Irp->AssociatedIrp.SystemBuffer**. This buffer contains a [**DEVICE_INTERNAL_STATUS_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-device_internal_status_data) structure with the device's internal status.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof(DEVICE_INTERNAL_STATUS_DATA)**.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful.
Otherwise, Status is set to the appropriate error condition as a NTSTATUS code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG returns the host-initiated device telemetry log from any storage device. The following pseudocode shows how to request the telemetry data header:

```cpp
// Allocate a GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST structure, then
// initialize it with a data header request:
//   request.Version = sizeof(GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST);
//   request.Size = sizeof(GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST);
//   request.RequestDataType = DeviceCurrentInternalStatusDataHeader;

// Allocate a DEVICE_INTERNAL_STATUS_DATA structure in which
// to return the header data, with outputBufferLength set to
// (sizeof(DEVICE_INTERNAL_STATUS_DATA) + 512).

// Get the device internal status data.
BOOL result = TRUE;
ULONG returnedLength = 0;
result = DeviceIoControl(deviceHandle,
            IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG,
            &request,
            sizeof(GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST),
            &outputBuffer,
            outputBufferLength,
            &returnedLength,
            NULL);

```

## See also

[DEVICE_INTERNAL_STATUS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-device_internal_status_data)

[GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-get_device_internal_status_data_request)