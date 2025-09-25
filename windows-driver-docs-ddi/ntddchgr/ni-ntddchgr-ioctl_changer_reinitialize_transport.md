# IOCTL_CHANGER_REINITIALIZE_TRANSPORT IOCTL

## Description

Physically recalibrates a transport element, typically after the changer has been powered on or a calling application has initiated a recovery operation. Recalibration may involve returning the transport to its "home" position.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** indicates the element to initialize.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**([CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(CHANGER_ELEMENT). The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_ELEMENT_ADDRESS, or STATUS_INVALID_PARAMETER.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element)