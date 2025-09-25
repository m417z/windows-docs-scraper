# IOCTL_STORAGE_RESET_BUS IOCTL

## Description

Resets an I/O bus and, indirectly, each device on the bus. Resetting the bus clears all device reservations and transfer speed settings, which must then be renegotiated, making it a time-consuming operation that should be used very rarely. The caller requires only read access to issue a bus reset.

The **SrbStatus** flag of pending SRBs is set to SRB_STATUS_BUS_RESET.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [STORAGE_BUS_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_bus_reset_request) structure that specifies the path ID of the bus to reset.

### Input buffer length

The length of a [STORAGE_BUS_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_bus_reset_request) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES, STATUS_NOT_IMPLEMENTED, or STATUS_INVALID_DEVICE_REQUEST.

## See also

[STORAGE_BUS_RESET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_bus_reset_request)