# IPhotoAcquireDeviceSelectionDialog::DoModal

## Description

The `DoModal` method displays a device selection dialog box. The function returns when the user selects a device using the modal dialog box.

## Parameters

### `hWndParent` [in]

Handle to a parent window.

### `dwDeviceFlags` [in]

Double word value containing a combination of device flags that indicate which type of devices to display. The device flags may be a combination of any of the following:

| Flag | Description |
| --- | --- |
| **DSF_WPD_DEVICES** | Show devices of type Windows Portable Devices (WPD). |
| **DSF_WIA_CAMERAS** | Show cameras of type Windows Image Acquisition (WIA). |
| **DSF_WIA_SCANNERS** | Show scanners of type Windows Image Acquisition (WIA). |
| **DSF_STI_DEVICES** | Show devices of type Still Image Architecture (STI). |
| **DSF_FS_DEVICES** | Show removable storage devices, such as CD drives or card readers. |
| **DSF_DV_DEVICES** | Show digital video camera devices. |
| **DSF_ALL_DEVICES** | Show all devices. |
| **DSF_SHOW_OFFLINE** | Show devices that are offline. Not supported by all device types. |

### `pbstrDeviceId` [out]

Pointer to a string containing the ID of the selected device.

### `pnDeviceType` [out]

Pointer to the [DEVICE_SELECTION_DEVICE_TYPE](https://learn.microsoft.com/windows/win32/api/photoacquire/ne-photoacquire-device_selection_device_type) of the selected device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[DEVICE_SELECTION_DEVICE_TYPE](https://learn.microsoft.com/windows/win32/api/photoacquire/ne-photoacquire-device_selection_device_type)

[IPhotoAcquireDeviceSelectionDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiredeviceselectiondialog)