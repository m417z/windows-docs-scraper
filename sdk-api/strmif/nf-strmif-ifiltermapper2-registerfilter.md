# IFilterMapper2::RegisterFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RegisterFilter` method adds filter information to the registry.

## Parameters

### `clsidFilter` [in]

Class identifier (CLSID) of the filter.

### `Name` [in]

Descriptive name for the filter.

### `ppMoniker` [in, out]

Address of a pointer to a device moniker that determines where this filter's data will be written. Can be **NULL**.

### `pclsidCategory` [in]

Pointer to the filter category of the filter. If **NULL**, the default category is CLSID_ActiveMovieFilters. (See [Filter Categories](https://learn.microsoft.com/windows/desktop/DirectShow/filter-categories).)

### `szInstance` [in]

Instance data for constructing the device moniker's display name. Can be the friendly name, or the string representation of the filter CLSID. If **NULL**, defaults to the filter CLSID.

### `prf2` [in]

Pointer to a [REGFILTER2](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regfilter2) structure containing filter information.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_BAD_KEY** | Could not get registry key. |

## Remarks

This method adds information about the filter to the registry, under the registry entry for the specified filter category. It does not register the in-process server that creates the filter (usually a DLL). To register the server, you can call the [AMovieDllRegisterServer2](https://learn.microsoft.com/windows/desktop/DirectShow/amoviedllregisterserver2) function.

For the *ppMoniker* parameter, use one of the following:

* The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface pointer for an existing device moniker
* The address of a **NULL****IMoniker** interface pointer
* **NULL**

If you are registering a filter for a Windows Driver Model (WDM) or Plug and Play device, pass the address of the existing device moniker. The filter will be registered using this moniker. When the method returns, **ppMoniker* is set to **NULL**.

Otherwise, the method creates a new moniker. If *ppMoniker* is non-**NULL**, the method sets **ppMoniker* to point to the new moniker. The application can use this moniker to write additional private values in the property bag. Be sure to release the interface.

Set *ppMoniker* to **NULL** if you don't want to provide or receive the moniker.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterMapper2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2)