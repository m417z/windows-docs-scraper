# IOCTL_CHANGER_EXCHANGE_MEDIUM IOCTL

## Description

Moves a piece of media from a source element to one destination and the piece of media originally in the first destination to a second destination. The source and second destination are often the same, which essentially swaps the two pieces of media.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_exchange_medium) data, which indicates the source, both destinations, and whether either or both media should be flipped, assuming the device supports two-sided media.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(CHANGER_EXCHANGE_MEDIUM).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_DESTINATION_ELEMENT_FULL, STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_DEVICE_REQUEST, STATUS_INVALID_ELEMENT_ADDRESS, STATUS_INVALID_PARAMETER, or STATUS_SOURCE_ELEMENT_EMPTY.

## See also

[CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_exchange_medium)

[ChangerExchangeMedium](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerexchangemedium)