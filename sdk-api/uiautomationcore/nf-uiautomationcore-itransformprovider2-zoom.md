# ITransformProvider2::Zoom

## Description

Zooms the viewport of the control.

## Parameters

### `zoom` [in]

Type: **double**

The amount to zoom the viewport, specified as a percentage. The provider should zoom the viewport to the nearest supported value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITransformProvider2](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itransformprovider2)