# IUIImage::GetBitmap

## Description

Retrieves a bitmap to display as an icon in the ribbon and context popup UI of the Windows Ribbon framework.

## Parameters

### `bitmap` [out]

Type: **HBITMAP***

When this method returns, contains a pointer to the handle to the requested bitmap.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IUIImage::GetBitmap** is called on image property callback triggered by [InvalidateUICommand](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-invalidateuicommand).

## See also

[IUIImage](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimage)

[IUIImageFromBitmap](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimagefrombitmap)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)