# IOCTL_EHSTOR_DEVICE_SILO_COMMAND IOCTL

## Description

This IOCTL issues a silo command to the targeted silo on the device. Both input and output data are structured according to the definition of silo commands, as found in the IEEE 1667 specification document.

## Parameters

### Major code

### Input buffer

The input buffer at Irp->AssociatedIrp.SystemBuffer must contain a structure of type [SILO_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-tagsilo_command).

### Input buffer length

The length of a [SILO_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-tagsilo_command) structure.

### Output buffer

The output buffer contains the output data returned directly from the device response to this silo command. The structure of this output data is assumed to be shared knowledge between the client issuing this IOCTL and the device.

### Output buffer length

The length of the buffer.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values may be returned in the Status field:

STATUS_SUCCESS - The silo command was successfully issued to the device.

STATUS_INVALID_BUFFER_SIZE - The input buffer length supplied is of incorrect size.

STATUS_BUFFER_TOO_SMALL - The output buffer length supplied is of insufficient size to hold the device response for this silo command.