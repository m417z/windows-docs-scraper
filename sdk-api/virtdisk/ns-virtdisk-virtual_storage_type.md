# VIRTUAL_STORAGE_TYPE structure

## Description

Contains the type and provider (vendor) of the virtual storage device.

## Members

### `DeviceId`

Device type identifier.

| Value | Meaning |
| --- | --- |
| **VIRTUAL_STORAGE_TYPE_DEVICE_UNKNOWN**<br><br>0 | Device type is unknown or not valid. |
| **VIRTUAL_STORAGE_TYPE_DEVICE_ISO**<br><br>1 | CD or DVD image file device type. (.iso file)<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |
| **VIRTUAL_STORAGE_TYPE_DEVICE_VHD**<br><br>2 | Virtual hard disk device type. (.vhd file) |
| **VIRTUAL_STORAGE_TYPE_DEVICE_VHDX**<br><br>3 | VHDX format virtual hard disk device type. (.vhdx file)<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |

### `VendorId`

Vendor-unique identifier.

#### VIRTUAL_STORAGE_TYPE_VENDOR_MICROSOFT (EC984AEC-A0F9-47e9-901F-71415A66345B)

#### VIRTUAL_STORAGE_TYPE_VENDOR_UNKNOWN (0)

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[IVdsVdProvider::CreateVDisk](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvdprovider-createvdisk)

[VDS_VDISK_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_vdisk_properties)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))