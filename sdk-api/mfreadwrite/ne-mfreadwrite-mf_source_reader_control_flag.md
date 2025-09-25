# MF_SOURCE_READER_CONTROL_FLAG enumeration

## Description

Contains flags for the [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample) method.

## Constants

### `MF_SOURCE_READER_CONTROLF_DRAIN:0x1`

Retrieve any pending samples, but do not request any more samples from the media source. To get all of the pending samples, call [ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample) with this flag until the method returns a **NULL** media sample pointer.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)