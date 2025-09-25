# ChangerGetProductData function

## Description

**ChangerGetProductData** handles the device-specific aspects of a device-control IRP with the IOCTL code IOCTL_CHANGER_GET_PRODUCT_DATA.

## Parameters

### `DeviceObject` [in]

Pointer to the device object that represents the changer.

### `Irp` [in]

Pointer to the IRP.

## Return value

**ChangerGetProductData** always returns STATUS_SUCCESS.

## Remarks

This routine is required.

**ChangerGetProductData** returns product data for a changer.

The changer class driver checks the output buffer length in the I/O stack location before calling **ChangerGetProductData**. If output buffer length is smaller than **sizeof**(CHANGER_PRODUCT_DATA) then the changer class driver returns with a value of STATUS_INFO_LENGTH_MISMATCH

**ChangerGetProductData** fills in a [CHANGER_PRODUCT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_product_data) structure at *Irp***->AssociatedIrp.SystemBuffer** before returning to the changer class driver. If the miniclass driver cached inquiry data in the changer's device extension before returning from **ChangerInitialize**, all members except **DeviceType** can be filled in from this data.

## See also

[CHANGER_PRODUCT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_product_data)

[ChangerInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitialize)