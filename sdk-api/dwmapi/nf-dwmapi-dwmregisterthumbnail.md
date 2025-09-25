# DwmRegisterThumbnail function

## Description

Creates a Desktop Window Manager (DWM) thumbnail relationship between the destination and source windows.

## Parameters

### `hwndDestination` [in]

The handle to the window that will use the DWM thumbnail. Setting the destination window handle to anything other than a top-level window type will result in a return value of E_INVALIDARG.

### `hwndSource` [in]

The handle to the window to use as the thumbnail source. Setting the source window handle to anything other than a top-level window type will result in a return value of E_INVALIDARG.

### `phThumbnailId` [out]

A pointer to a handle that, when this function returns successfully, represents the registration of the DWM thumbnail.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Registering a DWM thumbnail relationship will not modify desktop composition; for information about thumbnail positioning, see the documentation for the [DwmUpdateThumbnailProperties](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmupdatethumbnailproperties) function.

The window designated by *hwndDestination* must either be the desktop window itself or be owned by the process that is calling **DwmRegisterThumbnail**. This is required to prevent applications from affecting the content of other applications.

The thumbnail registration handle obtained by this function is not globally unique but is unique to the process. Call the [DwmUnregisterThumbnail](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmunregisterthumbnail) function to unregister the thumbnail. This must be done within the process that the relationship was registered in.

#### Examples

The following example demonstrates how to register the desktop thumbnail.

```cpp

HRESULT UpdateDesktop(HWND hwnd)
{
	HRESULT hr = S_OK;

	// Register the thumbnail
	HTHUMBNAIL thumbnail = NULL;

	hr = DwmRegisterThumbnail(hwnd, FindWindow(_T("Progman"), NULL), &thumbnail);
	if (SUCCEEDED(hr))
	{
		// Display the thumbnail using DwmUpdateThumbnailProperties
	}
	return hr;	
}
```

## See also

[DWM Thumbnail Overview](https://learn.microsoft.com/windows/desktop/dwm/thumbnail-ovw)

[Desktop Window Manager Overview](https://learn.microsoft.com/windows/desktop/dwm/dwm-overview)

[DwmQueryThumbnailSourceSize](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmquerythumbnailsourcesize)

[DwmUnregisterThumbnail](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmunregisterthumbnail)

[DwmUpdateThumbnailProperties](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmupdatethumbnailproperties)