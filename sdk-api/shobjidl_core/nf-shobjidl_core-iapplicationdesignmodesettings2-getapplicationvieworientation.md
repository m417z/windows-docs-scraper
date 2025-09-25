# IApplicationDesignModeSettings2::GetApplicationViewOrientation

## Description

Gets the orientation of the application design mode window.

## Parameters

### `applicationSizePixels`

Type: **SIZE**

The application window size.

### `viewOrientation` [out]

Type: **[APPLICATION_VIEW_ORIENTATION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-application_view_orientation)***

When this method returns successfully, receives a pointer to an [APPLICATION_VIEW_ORIENTATION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-application_view_orientation) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationDesignModeSettings2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings2)