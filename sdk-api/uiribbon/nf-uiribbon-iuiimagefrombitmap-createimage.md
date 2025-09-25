# IUIImageFromBitmap::CreateImage

## Description

Creates an [IUIImage](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimage) object from a bitmap image.

## Parameters

### `bitmap` [in]

Type: **HBITMAP**

A handle to the bitmap that contains the image.

### `options` [in]

Type: **[UI_OWNERSHIP](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_ownership)**

The [ownership conditions](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_ownership) under which
an image is created.

| Value | Meaning |
| --- | --- |
| UI_OWNERSHIP_TRANSFER | If **UI_OWNERSHIP_TRANSFER** is specified as the value of *options*, then the Ribbon framework owns the handle to the bitmap (HBITMAP) through the [IUIImage](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimage) object and releases it when the framework no longer requires it.<br><br>**Note** This option prevents the Ribbon host application from safely referencing the same HBITMAP elsewhere in the application UI. |
| UI_OWNERSHIP_COPY | If **UI_OWNERSHIP_COPY** is specified as the value of *options*, then the host application owns the HBITMAP and is able to reference the same HBITMAP for use elsewhere in the UI.<br><br>**Note** This option places responsibility for releasing the HBITMAP on the host application. |

### `image` [out]

Type: **[IUIImage](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimage)****

When this method returns, contains the address of a pointer variable that receives the [IUIImage](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimage) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This factory method is useful when an application dynamically generates an image
resource and wants to pass the new HBITMAP to the Ribbon,
for example, loading a Portable Network Graphics (PNG) through the Windows Imaging Component (WIC) or using
[CreateDIBSection](https://learn.microsoft.com/previous-versions//ms532292(v=vs.85)) to create an image for a new style
in a styles gallery.

This method is also useful for applications that require a
pre-existing bitmap image that has not been rendered obsolete by the Ribbon,
for example, a legacy toolbar image strip.

Specify **UI_OWNERSHIP_COPY** as the value for *options* if the Ribbon is being implemented in an
existing application and minimal code changes are required. This method uses extra memory
for the additional image.

Specify **UI_OWNERSHIP_TRANSFER** as the value for *options* to minimize memory usage.

## See also

[IUIImageFromBitmap](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimagefrombitmap)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)