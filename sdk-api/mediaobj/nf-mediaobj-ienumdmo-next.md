# IEnumDMO::Next

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Next` method retrieves a specified number of items in the enumeration sequence.

## Parameters

### `cItemsToFetch`

Number of items to retrieve.

### `pCLSID` [out]

Array of size *cItemsToFetch* that is filled with the CLSIDs of the enumerated DMOs.

### `Names` [out]

Array of size *cItemsToFetch* that is filled with the friendly names of the enumerated DMOs.

### `pcItemsFetched` [out]

Pointer to a variable that receives the actual number of items retrieved. Can be **NULL** if *cItemsToFetch* equals 1.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_FALSE** | Retrieved fewer items than requested. |
| **S_OK** | Retrieved the requested number of items. |

## Remarks

If the method succeeds, the arrays given by the *pCLSID* and *Names* parameters are filled with CLSIDs and wide-character strings. The value of **pcItemsFetched* specifies the number of items returned in these arrays.

The method returns S_OK if it retrieves the requested number of items (in other words, if **pcItemsFetched* equals *cItemsToFetch*). Otherwise, it returns S_FALSE or an error code.

The caller must free the memory allocated for each string returned in the *Names* parameter, using the **CoTaskMemFree** function.

## See also

[IEnumDMO Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-ienumdmo)