# MF_QUALITY_ADVISE_FLAGS enumeration

## Description

Contains flags for the [IMFQualityAdvise2::NotifyQualityEvent](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfqualityadvise2-notifyqualityevent) method.

## Constants

### `MF_QUALITY_CANNOT_KEEP_UP:0x1`

The decoder has done everything that it can to reduce sample latency, and samples are still late.

## Remarks

If the decoder sets the **MF_QUALITY_CANNOT_KEEP_UP** flag, the quality manager tries to reduce latency through the media source and the media sink. For example, it might request the [Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer) (EVR) to drop frames. During this period, the quality manager stops calling the decoder's [IMFQualityAdvise2::NotifyQualityEvent](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfqualityadvise2-notifyqualityevent) method, until samples are no longer arriving late at the sink. At that point, the quality manager resumes calling **NotifyQualityEvent** on the decoder.

## See also

[IMFQualityAdvise2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise2)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)