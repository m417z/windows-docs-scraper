# IOCTL_CHANGER_GET_PRODUCT_DATA IOCTL

## Description

Returns product data for the device.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [CHANGER_PRODUCT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_product_data) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**(CHANGER_PRODUCT_DATA).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH.

## See also

[CHANGER_PRODUCT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_product_data)

[ChangerGetProductData](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetproductdata)