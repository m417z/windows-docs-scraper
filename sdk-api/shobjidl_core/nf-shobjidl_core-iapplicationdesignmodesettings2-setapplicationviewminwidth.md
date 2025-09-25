# IApplicationDesignModeSettings2::SetApplicationViewMinWidth

## Description

Sets the desired minimum width of the application design mode window.

## Parameters

### `viewMinWidth` [in]

Type: **APPLICATION_VIEW_MIN_WIDTH**

The minimum width value.

#### AVMW_DEFAULT (0)

Uses the default minimum width.

#### AVMW_320 (1)

Sets the minimum width at 320 pixels.

#### AVMW_500 (2)

Sets the minimum width at 500 pixels.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationDesignModeSettings2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings2)