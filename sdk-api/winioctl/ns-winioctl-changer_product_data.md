# CHANGER_PRODUCT_DATA structure

## Description

Represents product data for a changer device. It is used by the
[IOCTL_CHANGER_GET_PRODUCT_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_get_product_data) control code.

## Members

### `VendorId`

The device manufacturer's name. This is acquired directly from the device inquiry data.

### `ProductId`

The product identification, as defined by the vendor. This is acquired directly from the device inquiry data.

### `Revision`

The product revision, as defined by the vendor.

### `SerialNumber`

A unique value used to globally identify this device, as defined by the vendor.

### `DeviceType`

The device type of data transports, as defined by SCSI-2. This member must be **FILE_DEVICE_CHANGER**.

## See also

[IOCTL_CHANGER_GET_PRODUCT_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_get_product_data)