# _CHANGER_PRODUCT_DATA structure

## Description

The CHANGER_PRODUCT_DATA structure is used in conjunction with the [IOCTL_CHANGER_GET_PRODUCT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_product_data) request to retrieve product data for a device.

## Members

### `VendorId`

Specifies the name of the device manufacturer.

### `ProductId`

Specifies the product identification as defined by the vendor.

### `Revision`

Specifies the product revision as defined by the vendor.

### `SerialNumber`

Specifies the value defined by the vendor to identify this device. Serial numbers are unique for all changers of a given type, but are not necessarily unique across vendor and product lines. For a SCSI changer, this value might be from Vital Product Data. If **SerialNumber** is not unique, the miniclass driver should not set the CHANGER_SERIAL_NUMBER_VALID flag in the **Features0** member of the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) structure.

### `DeviceType`

Specifies the device type of the changer. This member must be MEDIUM_CHANGER.

## See also

[ChangerGetProductData](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetproductdata)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_GET_PRODUCT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_product_data)