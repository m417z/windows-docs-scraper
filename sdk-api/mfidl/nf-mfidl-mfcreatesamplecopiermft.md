# MFCreateSampleCopierMFT function

## Description

Creates an instance of the sample copier transform.

## Parameters

### `ppCopierMFT` [out]

Receives a pointer to the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The sample copier is a Media Foundation transform (MFT) that copies data from input samples to output samples without modifying the data. The following data is copied from the sample:

* All [Sample Attributes](https://learn.microsoft.com/windows/desktop/medfound/sample-attributes).
* The time stamp and duration.
* Sample flags (see [IMFSample::SetSampleFlags](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-setsampleflags)).
* The data in the media buffers. If the input sample contains multiple buffers, the data is copied into a single buffer on the output sample.

This MFT is useful in the following situation:

* One pipeline object, such as a media source, allocates media samples for output.
* Another pipeline object, such as a media sink, allocates its own media samples for input. For example, the object might require buffers allocated from a special memory pool, such as video memory.

The following diagram shows this situation with a media source and a media sink.

![Diagram: Media Source points to a Sample; Media Sink points to a second Sample; Sample Copier points to an arrow from the first sample to the second](https://learn.microsoft.com/windows/win32/api/mfidl/images/SampleCopierMFT.gif)

In order for the media sink to receive data from the media source, the data must be copied into the media samples owned by the media sink. The sample copier can be used for this purpose.

A specific example of such a media sink is the [Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer) (EVR). The EVR allocates samples that contain Direct3D surface buffers, so it cannot receive video samples directly from a media source. Starting in Windows 7, the topology loader automatically handles this case by inserting the sample copier between the media source and the EVR.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)