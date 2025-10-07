# CreatePosPassThru function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CreatePosPassThru` function creates a [**CPosPassThru**](https://learn.microsoft.com/windows/win32/directshow/cpospassthru) object or [**CRendererPosPassThru**](https://learn.microsoft.com/windows/win32/directshow/crendererpospassthru) object.

## Parameters

*pAgg*

Pointer to the owner of this object. If the object is aggregated, pass a pointer to the aggregating object's **IUnknown** interface. Otherwise, set this parameter to **NULL**.

*bRenderer*

Boolean value that specifies whether the filter is a renderer. Use the value **TRUE** if the filter is a renderer, or **FALSE** otherwise. If the value is **TRUE**, this method creates an instance of the [**CRendererPosPassThru**](https://learn.microsoft.com/windows/win32/directshow/crendererpospassthru) class. If the value is **FALSE**, the method creates an instance of the **CPosPassThru** class.

*pPin*

Pointer to the [**IPin**](https://learn.microsoft.com/windows/desktop/api/Strmif/nn-strmif-ipin) interface on the filter's input pin.

*ppPassThru*

Address of a variable that receives a pointer to the object's **IUnknown** interface.

## Return value

Returns S\_OK if successful. Otherwise, returns an **HRESULT** value indicating the cause of the error.

## Remarks

This method uses the [**ISeekingPassThru**](https://learn.microsoft.com/windows/desktop/api/Strmif/nn-strmif-iseekingpassthru) interface to create the object. The object is loaded dynamically from Quartz.dll.

If the function succeeds, the returned **IUnknown** interface has an outstanding reference count. The caller must release the interface.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Ctlutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [**CPosPassThru Class**](https://learn.microsoft.com/windows/win32/directshow/cpospassthru)