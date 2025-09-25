# ICreateDevEnum::CreateClassEnumerator

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CreateClassEnumerator** method creates an enumerator for a specified device category.

## Parameters

### `clsidDeviceClass` [in]

Specifies the class identifier (CLSID) of the device category. See [Filter Categories](https://learn.microsoft.com/windows/desktop/DirectShow/filter-categories).

### `ppEnumMoniker` [out]

Receives a pointer to the [IEnumMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienummoniker) interface. The caller must release the interface.

### `dwFlags` [in]

Bitwise combination of zero or more flags. If zero, the method enumerates every filter in the category. If any flags are set, the enumeration includes only filters that match the specified flags. The following flags are defined:

| Flag | Description |
| --- | --- |
| CDEF_DEVMON_CMGR_DEVICE | Enumerate audio or video codecs, using the audio compression manager (ACM) or video compression manager (VCM). |
| CDEF_DEVMON_DMO | Enumerate DirectX Media Objects (DMOs). |
| CDEF_DEVMON_FILTER | Enumerate native DirectShow filters. |
| CDEF_DEVMON_PNP_DEVICE | Enumerate Plug and Play hardware devices. |

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Out of memory. |
| **S_FALSE** | The category specified by *clsidDeviceClass* does not exist or is empty. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

If the category does not exist or is empty, the return value is S_FALSE, and the *ppEnumMoniker* parameter receives the value **NULL**. Therefore, test for the return value S_OK instead of using the **SUCCEEDED** macro:

| C++ |
| --- |
| ``` IEnumMoniker *pEnum = NULL; hr = pSysDevEnum->CreateClassEnumerator(     CLSID_VideoCompressorCategory, &pEnum, 0); if (hr == S_OK)  {     // Safe to dereference pEnum.     pEnum->Release(); } ``` |

Use the **IEnumMoniker** interface to enumerate monikers that represent the filters in the device category. Monikers support the **IMoniker** interface. The monikers created by **CreateClassEnumerator** also support the [IGetCapabilitiesKey](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igetcapabilitieskey) interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICreateDevEnum Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icreatedevenum)