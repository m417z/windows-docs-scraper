# UI_OWNERSHIP enumeration

## Description

Specifies values that identify the ownership conditions under which an image is created by the Windows Ribbon framework.

## Constants

### `UI_OWNERSHIP_TRANSFER:0`

The handle to the bitmap (HBITMAP) is owned by the Ribbon framework
through the [IUIImage](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimage) object.

### `UI_OWNERSHIP_COPY:1`

A copy of the HBITMAP is created by the Ribbon framework through
the [IUIImage](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiimage) object. The host application still owns the HBITMAP.

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)

[IUIImageFromBitmap::CreateImage](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiimagefrombitmap-createimage)