# IWiaDevMgr::GetImageDlg

## Description

The **IWiaDevMgr::GetImageDlg** method displays one or more dialog boxes that enable a user to acquire an image from a Windows Image Acquisition (WIA) device and write the image to a specified file. This method combines the functionality of [IWiaDevMgr::SelectDeviceDlg](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-selectdevicedlg) to completely encapsulate image acquisition within a single API call.

## Parameters

### `hwndParent` [in]

Type: **HWND**

Handle of the window that owns the **Get Image** dialog box.

### `lDeviceType` [in]

Type: **LONG**

Specifies which type of WIA device to use. Is set to **StiDeviceTypeDefault**, **StiDeviceTypeScanner**, or **StiDeviceTypeDigitalCamera**.

### `lFlags` [in]

Type: **LONG**

Specifies dialog box behavior. Can be set to the following values:

| Flag | Meaning |
| --- | --- |
| 0 | Default behavior. |
| WIA_SELECT_DEVICE_NODEFAULT | Force this method to display the **Select Device** dialog box. For more information, see the **Remarks** section of this reference page. |
| WIA_DEVICE_DIALOG_SINGLE_IMAGE | Restrict image selection to a single image in the device image acquisition dialog box. |
| WIA_DEVICE_DIALOG_USE_COMMON_UI | Use the system UI, if available, rather than the vendor-supplied UI. If the system UI is not available, the vendor UI is used. If neither UI is available, the function returns E_NOTIMPL. |

### `lIntent` [in]

Type: **LONG**

Specifies what type of data the image is intended to represent. For a list of image intent values, see [Image Intent Constants](https://learn.microsoft.com/windows/desktop/wia/-wia-imageintentconstants).

### `pItemRoot` [in]

Type: **[IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem)***

Pointer to the interface of the hierarchical tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects returned by [IWiaDevMgr::CreateDevice](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-createdevice).

### `bstrFilename` [in]

Type: **BSTR**

Specifies the name of the file to which the image data is written.

### `pguidFormat` [in, out]

Type: **GUID***

On input, contains a pointer to a GUID that specifies the format to use. On output, holds the format used. Pass IID_NULL to use the default format.

## Return value

Type: **HRESULT**

**IWiaDevMgr::GetImageDlg** returns S_FALSE if the user cancels the device selection or image acquisition dialog boxes, WIA_S_NO_DEVICE_AVAILABLE if no WIA device is currently available, E_NOTIMPL if no UI is available, and S_OK if the data is transferred successfully.

**IWiaDevMgr::GetImageDlg** returns a value specified in [Error Codes](https://learn.microsoft.com/windows/desktop/wia/-wia-error-codes), or a standard COM error if it fails for any reason other than those specified.

## Remarks

Invoking this method displays a dialog box that enables users to acquire images. It can also display the **Select Device** dialog box created by the [IWiaDevMgr::SelectDeviceDlg](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadevmgr-selectdevicedlg) method.

If the application passes **NULL** for the value of the *pItemRoot* parameter, **IWiaDevMgr::GetImageDlg** displays the **Select Device** dialog box that lets the user select the WIA input device. If the application specifies a WIA input device by passing a pointer to the device's item tree through the *pItemRoot* parameter, **IWiaDevMgr::GetImageDlg** does not display the **Select Device** dialog box. Instead, it will use the specified input device to acquire the image.

When using the **Select Device** dialog box, applications can specify types of WIA input devices. To do so, they must set the *pItemRoot* parameter to **NULL** and pass the appropriate constants through the *lDeviceType* parameter. If more than one device of the specified type is present, the **IWiaDevMgr::GetImageDlg** displays the **Select Device** dialog box to let the user select which device will be used.

If **IWiaDevMgr::GetImageDlg** finds only one matching device, it will not display the **Select Device** dialog box. Instead, it will select the matching device. You can override this behavior and force **IWiaDevMgr::GetImageDlg** to display the **Select Device** dialog box by passing WIA_SELECT_DEVICE_NODEFAULT as the value for the *lFlags* parameter.

It is recommended that applications make device and image selection available through a menu item named **From scanner or camera** on the **File** menu.

The dialog must have sufficient rights to the folder for *bstrFilename* that it can save the file with a unique file name. The folder should also be protected with an access control list (ACL) because it contains user data.