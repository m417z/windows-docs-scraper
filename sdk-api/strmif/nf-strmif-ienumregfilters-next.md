# IEnumRegFilters::Next

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IEnumRegFilters** interface is deprecated.

Fills the array with descriptions of the next set of filters (specified by the *cFilters* parameter) that meet the requirements specified upon creation of the enumerator.

## Parameters

### `cFilters` [in]

Number of filters.

### `apRegFilter` [out]

Address of a pointer to an array of **REGFILTER** pointers.

### `pcFetched` [out]

Pointer to the actual number of filters passed.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **E_UNEXPECTED** | Unexpected error. |
| **S_FALSE** | Fewer filters were retrieved than requested. |
| **S_OK** | Success. |
| **VFW_E_ENUM_OUT_OF_SYNC** | The enumerator has become invalid. For more information, see Remarks. |

## Remarks

The calling application must use the Microsoft Win32 **CoTaskMemFree** function to free each **REGFILTER** pointer returned in the array. Do not free the **Name** member of the **REGFILTER** structure separately, because `IEnumRegFilters::Next` allocates memory for this string as part of the **REGFILTER** structure.

If the number of registered filters changes, the state of the enumerator will no longer be consistent with the state of the registry. As a result, this method will return VFW_E_ENUM_OUT_OF_SYNC. You should discard any data obtained from previous calls to the enumerator, because it might be invalid, and update the enumerator by calling the [Reset](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ienumregfilters-reset) method. You can then call the `Next` method safely.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IEnumRegFilters Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienumregfilters)