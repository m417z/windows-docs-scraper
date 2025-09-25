# IApplicationDesignModeSettings2::GetApplicationSizeBounds

## Description

This methods retrieves the size bounds supported by the application.

## Parameters

### `minApplicationSizePixels` [out]

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

When this method returns successfully, receives a pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that defines the minimum possible window size.

### `maxApplicationSizePixels` [out]

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

When this method returns successfully, receives a pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that defines the maximum possible window size.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationDesignModeSettings2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings2)