# IAMPhysicalPinInfo::GetPhysicalType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The `IAMPhysicalPinInfo` interface is deprecated.

Retrieves the type and name of the physical pin.

## Parameters

### `pType` [out]

Pointer to a variable that receives a value indicating the pin's type. The [PhysicalConnectorType](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-physicalconnectortype) enumeration defines the pin type values.

### `ppszType` [out]

Address of a pointer to a buffer that receives a human-readable string identifying the pin type.

## Return value

Returns S_OK if a valid physical pin value is found. Otherwise, returns VFW_E_NO_ACCEPTABLE_TYPES.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMPhysicalPinInfo Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamphysicalpininfo)