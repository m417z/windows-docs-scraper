# DMOGetTypes function

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DMOGetTypes** function retrieves the name of a DMO from the registry.

## Parameters

### `clsidDMO`

Class identifier (CLSID) of the DMO.

### `ulInputTypesRequested`

Size of the array passed in the *pInputTypes* parameter.

### `pulInputTypesSupplied`

Pointer to a variable that receives the number of [DMO_PARTIAL_MEDIATYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dmoreg/ns-dmoreg-dmo_partial_mediatype) structures in *pInputTypes* that the function fills in.

### `pInputTypes`

Pointer to a caller-allocated array of DMO_PARTIAL_MEDIATYPE structures. The size of the array is given in the ulInputTypesRequested parameter. The function fills the array with the input types registered for the DMO.

### `ulOutputTypesRequested`

Size of the array passed in the *pOutputTypes* parameter.

### `pulOutputTypesSupplied`

Pointer to a variable that receives the number of [DMO_PARTIAL_MEDIATYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dmoreg/ns-dmoreg-dmo_partial_mediatype) structures in *pOutputTypes* that the function fills in.

### `pOutputTypes`

Pointer to a caller-allocated array of [DMO_PARTIAL_MEDIATYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dmoreg/ns-dmoreg-dmo_partial_mediatype) structures. The size of the array is given in the *ulOutputTypesRequested* parameter. The function fills the array with the DMO output types registered for the DMO.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **S_FALSE** | Array too small. |
| **S_OK** | Success |

## Remarks

If one of the arrays is too small to hold all of the registered types, the function fills the array but returns S_FALSE.

If the DMO did not register any media types, the function returns S_OK and sets **pulInputTypesSupplied* and **pulOutputTypesSupplied* to zero.

## See also

[DMO Functions](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-functions)