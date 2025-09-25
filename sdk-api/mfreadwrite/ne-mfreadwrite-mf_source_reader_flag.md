# MF_SOURCE_READER_FLAG enumeration

## Description

Contains flags that indicate the status of the [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample) method.

## Constants

### `MF_SOURCE_READERF_ERROR:0x1`

An error occurred. If you receive this flag, do not make any further calls to [IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader) methods.

### `MF_SOURCE_READERF_ENDOFSTREAM:0x2`

The source reader reached the end of the stream.

### `MF_SOURCE_READERF_NEWSTREAM:0x4`

One or more new streams were created. Respond to this flag by doing at least one of the following:

* Set the output types on the new streams.
* Update the stream selection by selecting or deselecting streams.

### `MF_SOURCE_READERF_NATIVEMEDIATYPECHANGED:0x10`

The *native format* has changed for one or more streams. The native format is the format delivered by the media source before any decoders are inserted.

### `MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED:0x20`

The current media has type changed for one or more streams. To get the current media type, call the [IMFSourceReader::GetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-getcurrentmediatype) method.

### `MF_SOURCE_READERF_STREAMTICK:0x100`

There is a gap in the stream. This flag corresponds to an [MEStreamTick](https://learn.microsoft.com/windows/desktop/medfound/mestreamtick) event from the media source.

### `MF_SOURCE_READERF_ALLEFFECTSREMOVED:0x200`

All transforms inserted by the application have been removed for a particular stream. This could be due to a dynamic format change from a source or decoder that prevents custom transforms from being used because they cannot handle the new media type.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)