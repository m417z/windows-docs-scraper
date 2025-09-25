# IDvdInfo2::GetAllGPRMs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAllGPRMs** method retrieves the current contents of all general parameter registers (GPRMs).

## Parameters

### `pRegisterArray` [out]

Pointer to an array of type [GPRMARRAY](https://learn.microsoft.com/windows/desktop/DirectShow/gprmarray) that receives all 16 current GPRM values.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |

## Remarks

GPRMs are 16-bit registers that each disc can use in unique ways for temporary data storage.

**Note** A player application using the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter does not need to access these registers for any Annex J playback or navigation control. This method is provided for player applications implementing advanced functionality. Do not attempt to modify the GPRMs directly unless you have a thorough knowledge of the DVD specification, and the ways in which the GPRMs are used on the particular discs to be played.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)