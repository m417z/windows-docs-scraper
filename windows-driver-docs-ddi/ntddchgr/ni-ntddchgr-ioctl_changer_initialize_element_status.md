# IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS IOCTL

## Description

Initializes the status of all elements or of specified number of elements of a particular type.

## Parameters

### Major code

### Input buffer

 The buffer at **Irp->AssociatedIrp.SystemBuffer** contains an [CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_initialize_element_status) structure that indicates the element type and the number of elements to initialize. If the **BarCodeScan** member is **TRUE** and CHANGER_BAR_CODE_SCANNER_INSTALLED is also set in **Features0** of [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters), the elements should be initialized using a bar code scan.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(CHANGER_INITIALIZE_ELEMENT_STATUS).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(CHANGER_INITIALIZE_ELEMENT_STATUS). The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH, STATUS_INSUFFICIENT_RESOURCES, STATUS_INVALID_ELEMENT_ADDRESS, or STATUS_INVALID_PARAMETER.

## See also

[CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_initialize_element_status)

[ChangerInitializeElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitializeelementstatus)