# IAMCrossbar::get_CrossbarPinInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_CrossbarPinInfo` method retrieves information about a specified pin.

## Parameters

### `IsInputPin` [in]

Specifies the direction of the pin. Use one of the following values.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Input pin |
| ****FALSE**** | Output pin |

### `PinIndex` [in]

Specifies the index of the pin.

### `PinIndexRelated` [out]

Pointer to a variable that receives the index of the related pin, or –1 if no pin is related to this pin. The *related pin* is a pin on the same filter, with the same direction; it typically represents the same physical jack or connector. For example, a video tuner and an audio tuner might be related pins. Typically, if two pins are related, you should route them together.

### `PhysicalType` [out]

Pointer to a variable that receives a member of the [PhysicalConnectorType](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-physicalconnectortype) enumeration, indicating the pin's physical type.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Unknown physical type. |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

Output pins and input pins are both indexed from zero. To determine the number of output and input pins, call the [IAMCrossbar::get_PinCounts](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamcrossbar-get_pincounts) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMCrossbar Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcrossbar)

[Working with Crossbars](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-crossbars)