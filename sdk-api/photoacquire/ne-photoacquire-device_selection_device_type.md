# DEVICE_SELECTION_DEVICE_TYPE enumeration

## Description

The `DEVICE_SELECTION_DEVICE_TYPE` enumeration type indicates the type of a selected device.

## Constants

### `DST_UNKNOWN_DEVICE:0`

Specifies that the type of the selected device is unknown.

### `DST_WPD_DEVICE:0x1`

Specifies that the type of the selected device is Windows Portable Devices (WPD).

### `DST_WIA_DEVICE:0x2`

Specifies that the type of the selected device is Windows Image Acquisition (WIA).

### `DST_STI_DEVICE:0x3`

Specifies that the type of the selected device is Still Image Architecture (STI).

### `DSF_TWAIN_DEVICE:0x4`

Not supported.

### `DST_FS_DEVICE:0x5`

Specifies that the selected device is a removable drive in the file system.

### `DST_DV_DEVICE:0x6`

## Remarks

This enumeration type is pointed to by the *pnDeviceType* parameter of [IPhotoAcquireDeviceSelectionDialog::DoModal](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiredeviceselectiondialog-domodal).

## See also

[Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/acquisition/enumeration-types)

[IPhotoAcquireDeviceSelectionDialog::DoModal](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiredeviceselectiondialog-domodal)