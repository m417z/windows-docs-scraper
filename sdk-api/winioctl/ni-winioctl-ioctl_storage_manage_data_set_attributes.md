# IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES IOCTL

## Description

The **IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES** control code communicates attribute information to the volume manager and storage system device.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                         // handle to device
  IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES, // dwIoControlCode
  (LPVOID) lpInBuffer,                      // input buffer
  (DWORD) nInBufferSize,                    // size of the input buffer
  (LPVOID) lpOutBuffer,                     // output buffer
  (DWORD) nOutBufferSize,                   // size of the input buffer
  (LPDWORD) lpBytesReturned,                // number of bytes returned
  (LPOVERLAPPED) lpOverlapped               // OVERLAPPED structure
);
```

## Parameters

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Use the **IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES** control code for sending storage system-specific information to the volume manager and storage system.

The input buffers passed through the *lpInBuffer* parameter start with a [DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes) structure but may contain additional parameters before the list of data set ranges depending on the value of the **Action** member of the **DEVICE_MANAGE_DATA_SET_ATTRIBUTES** structure. The output buffers returned through the *lpOutBuffer* parameter start with a [DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes) structure but then can contain additional data depending on the value of the **Action** member of the **DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT** structure pointed to by the *lpOutBuffer* parameter. These values are one of the values for the [DEVICE_DATA_MANAGEMENT_SET_ACTION](https://learn.microsoft.com/windows/desktop/DevIO/device-data-management-set-action) data type.

Value | Parameters structure | Output block structure
------|----------------------|-----------------------
**DeviceDsmAction_Trim** | None | None
**DeviceDsmAction_Notification** | [DEVICE_DSM_NOTIFICATION_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_dsm_notification_parameters) | None
**DeviceDsmAction_OffloadRead** | [DEVICE_DSM_OFFLOAD_READ_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_dsm_offload_read_parameters) | [STORAGE_OFFLOAD_READ_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_offload_read_output)
**DeviceDsmAction_OffloadWrite** | [DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_dsm_offload_write_parameters) | [STORAGE_OFFLOAD_WRITE_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_offload_write_output)
**DeviceDsmAction_Allocation** | None | [DEVICE_DATA_SET_LB_PROVISIONING_STATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_data_set_lb_provisioning_state)
**DeviceDsmAction_Repair** | [DEVICE_DATA_SET_REPAIR_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_data_set_repair_parameters) | None
**DeviceDsmAction_Scrub** | None | None
**DeviceDsmAction_Resiliency** | None | None

## See also

* [DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)