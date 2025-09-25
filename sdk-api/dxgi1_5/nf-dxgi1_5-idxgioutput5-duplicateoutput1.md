# IDXGIOutput5::DuplicateOutput1

## Description

Allows specifying a list of supported formats for fullscreen surfaces that can be returned by the [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) object.

## Parameters

### `pDevice` [in]

Type: **IUnknown***

A pointer to the Direct3D device interface that you can use to process the desktop image. This device must be created from the adapter to which the output is connected.

### `Flags`

Type: **UINT**

A bitfield of **DXGI_OUTDUPL_FLAG** enumeration values describing the kind of capture surface to create.

### `SupportedFormatsCount` [in]

Type: **UINT**

Specifies the number of supported formats.

### `pSupportedFormats` [in]

Type: **const [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)***

Specifies an array, of length *SupportedFormatsCount* of [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) entries.

### `ppOutputDuplication` [out]

Type: **IDXGIOutputDuplication****

A pointer to a variable that receives the new [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

* S_OK if **DuplicateOutput1** successfully created the desktop duplication interface.
* E_INVALIDARG for one of the following reasons:
  + The specified device (*pDevice*) is invalid, was not created on the correct adapter, or was not created from [IDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory1) (or a later version of a DXGI factory interface that inherits from **IDXGIFactory1**).
  + The calling application is already duplicating this desktop output.
* E_ACCESSDENIED if the application does not have access privilege to the current desktop image. For example, only an application that runs at LOCAL_SYSTEM can access the secure desktop.
* DXGI_ERROR_UNSUPPORTED if the created [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface does not support the current desktop mode or scenario. For example, 8bpp and non-DWM desktop modes are not supported.

  If **DuplicateOutput1** fails with DXGI_ERROR_UNSUPPORTED, the application can wait for system notification of desktop switches and mode changes and then call **DuplicateOutput1** again after such a notification occurs. For more information, see the desktop switch ([EVENT_SYSTEM_DESKTOPSWITCH](https://learn.microsoft.com/windows/desktop/WinAuto/event-constants)) and mode change notification ([WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange)).
* DXGI_ERROR_NOT_CURRENTLY_AVAILABLE if DXGI reached the limit on the maximum number of concurrent duplication applications (default of four). Therefore, the calling application cannot create any desktop duplication interfaces until the other applications close.
* DXGI_ERROR_SESSION_DISCONNECTED if **DuplicateOutput1** failed because the session is currently disconnected.
* Other error codes are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

This method allows directly receiving the original back buffer format used by a running fullscreen application. For comparison, using the original [DuplicateOutput](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-duplicateoutput) function always converts the fullscreen surface to a 32-bit BGRA format. In cases where the current fullscreen application is using a different buffer format, a conversion to 32-bit BGRA incurs a performance penalty. Besides the performance benefit of being able to skip format conversion, using **DuplicateOutput1** also allows receiving the full gamut of colors in cases where a high-color format (such as R10G10B10A2) is being presented.

The *pSupportedFormats* array should only contain display scan-out formats. See [Format Support for Direct3D Feature Level 11.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-0-feature-level-hardware) for required scan-out formats at each feature level. If the current fullscreen buffer format is not contained in the *pSupportedFormats* array, DXGI will pick one of the supplied formats and convert the fullscreen buffer to that format before returning from [IDXGIOutputDuplication::AcquireNextFrame](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-acquirenextframe). The list of supported formats should always contain DXGI_FORMAT_B8G8R8A8_UNORM, as this is the most common format for the desktop.

## See also

[DuplicateOutput](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-duplicateoutput)

[IDXGIOutput5](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nn-dxgi1_5-idxgioutput5)