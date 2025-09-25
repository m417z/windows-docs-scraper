# ICaptureGraphBuilder2::FindPin

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FindPin` method retrieves a particular pin on a filter, or determines whether a given pin matches the specified criteria.

## Parameters

### `pSource` [in]

Pointer to an interface on a filter, or to an interface on a pin.

### `pindir` [in]

Member of the [PIN_DIRECTION](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-pin_direction) enumeration that specifies the pin direction (input or output).

### `pCategory` [in]

A pointer to a GUID that specifies one of the pin categories listed in [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set). To match any pin, regardless of category, set this parameter to **NULL**.

### `pType` [in]

Pointer to a major type GUID that specifies the media type. Use **NULL** to match any media type.

### `fUnconnected` [in]

Boolean value that specifies whether the pin must be unconnected. If **TRUE**, the pin must be unconnected. If **FALSE**, the pin can be connected or unconnected.

### `num` [in]

Zero-based index of the pin to retrieve, from the set of matching pins. If *pSource* is a pointer to a filter, and more than one pin matches the search criteria, this parameter specifies which pin to retrieve. If *pSource* is a pointer to a pin, this parameter is ignored.

### `ppPin` [out]

Address of a pointer to receive the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of the matching pin.

## Return value

Returns S_OK if a matching pin is found, or E_FAIL otherwise.

## Remarks

If *pSource* is a pointer to a filter, the method searches for the *n*th pin on that filter that matches the search criteria, where *n* is given by the *num* parameter. If the method finds a matching pin, it returns a pointer to the pin in the *ppPin* parameter.

If *pSource* is a pointer to a pin, the method tests that pin against the search criteria. If the pin matches the criteria, the method returns S_OK, and returns a pointer to the pin's **IPin** interface in the *ppPin* parameter. Otherwise, it returns E_FAIL.

In either case, if the method succeeds, the **IPin** interface returned in the *ppPin* parameter has an outstanding reference count. Be sure to release the interface when you are done using it.

Typically, an application will not need to use this method. It is provided for unusually complex tasks, when the [ICaptureGraphBuilder2::RenderStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder2-renderstream) method cannot build the filter graph. Use this method to retrieve a desired pin from a capture filter, and then build the rest of the graph manually.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2)