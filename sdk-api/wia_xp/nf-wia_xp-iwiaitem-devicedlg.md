# IWiaItem::DeviceDlg

## Description

The **IWiaItem::DeviceDlg** method is used by applications to display a dialog box to the user to prepare for image acquisition.

## Parameters

### `hwndParent` [in]

Type: **HWND**

Handle of the parent window of the dialog box.

### `lFlags` [in]

Type: **LONG**

Specifies a set of flags that control the dialog box's operation. Can be set to any of the following values:

| Flag | Meaning |
| --- | --- |
| 0 | Default behavior. |
| WIA_DEVICE_DIALOG_SINGLE_IMAGE | Restrict image selection to a single image in the device image acquisition dialog box. |
| WIA_DEVICE_DIALOG_USE_COMMON_UI | Use the system UI, if available, rather than the vendor-supplied UI. If the system UI is not available, the vendor UI is used. If neither UI is available, the function returns E_NOTIMPL. |

### `lIntent` [in]

Type: **LONG**

Specifies what type of data the image is intended to represent. For a list of image intent values, see [Image Intent Constants](https://learn.microsoft.com/windows/desktop/wia/-wia-imageintentconstants).

**Note** This method ignores all WIA_INTENT_IMAGE_* image intents.

### `plItemCount` [out]

Type: **LONG***

Receives the number of items in the array indicated by the *ppIWiaItem* parameter.

### `ppIWiaItem` [out]

Type: **IWiaItem*****

Receives the address of an array of pointers to [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interfaces.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method displays a dialog box to the user that an application uses to gather all the information required for image acquisition. For instance, this dialog box enables the user to select images to download from a camera. When using a scanner, it is also used to specify image scan properties such as brightness and contrast.

After this method returns, the application can use the [IWiaDataTransfer](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatatransfer) interface to acquire the image.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method for each element in the array of interface pointers they receive through the *ppIWiaItem* parameter. Applications must also free the array using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

It is recommended that applications make device and image selection available through a menu item named **From scanner or camera** on the **File** menu.