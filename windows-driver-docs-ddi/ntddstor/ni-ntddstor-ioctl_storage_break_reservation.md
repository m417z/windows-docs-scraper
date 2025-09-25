# IOCTL_STORAGE_BREAK_RESERVATION IOCTL

## Description

Breaks a disk reservation. In a multi-initiator ("clustered") system, a single computer can reserve a disk resource, so that no other computer can access the disk. If the computer does not or cannot free the resource in a timely fashion, a means is needed to remove the reservation of the disk by force.

One means of forcing the system to free a reserved disk resource is to reset the bus. In fact, for storage devices whose bus adapters are managed by the SCSI port driver, the IOCTL_STORAGE_BREAK_RESERVATION request is equivalent to [IOCTL_STORAGE_RESET_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_reset_bus), which simply does a reset of the bus, freeing all of its reserved resources.

For storage devices whose bus adapters are managed by the STOR port driver, this I/O control code offers a better technique of breaking a disk reservation. That technique is called a "hierarchical reset." Upon receiving an IOCTL_STORAGE_BREAK_RESERVATION request, the STOR port driver first attempts to remove the reserve on the logical unit by resetting the logical unit itself. If that fails, the STOR port driver attempts to reset the target device that is the parent of the logical unit. Only when resetting the target device fails will the port driver reset the bus.

Resetting the bus clears all device reservations and transfer speed settings, which must then be renegotiated. Because this is a time-consuming operation, IOCTL_STORAGE_BREAK_RESERVATION is always to be preferred to a simple bus reset.

The caller requires only read access to issue a bus reset.

The **SrbStatus** flag of pending SRBs is set to SRB_STATUS_BUS_RESET.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [STORAGE_BREAK_RESERVATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_break_reservation_request) structure that identifies the bus to reset.

### Input buffer length

The length of a [STORAGE_BREAK_RESERVATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_break_reservation_request) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES, STATUS_NOT_IMPLEMENTED, or STATUS_INVALID_DEVICE_REQUEST.

## See also

[IOCTL_STORAGE_RESET_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_reset_bus)

[STORAGE_BREAK_RESERVATION_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_break_reservation_request)