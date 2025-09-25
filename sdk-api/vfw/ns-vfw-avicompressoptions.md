# AVICOMPRESSOPTIONS structure

## Description

The **AVICOMPRESSOPTIONS** structure contains information about a stream and how it is compressed and saved. This structure passes data to the [AVIMakeCompressedStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avimakecompressedstream) function (or the [AVISave](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avisavea) function, which uses **AVIMakeCompressedStream**).

## Members

### `fccType`

Four-character code indicating the stream type. The following constants have been defined for the data commonly found in AVI streams:

| Constant | Description |
| --- | --- |
| **streamtypeAUDIO** | Indicates an audio stream. |
| **streamtypeMIDI** | Indicates a MIDI stream. |
| **streamtypeTEXT** | Indicates a text stream. |
| **streamtypeVIDEO** | Indicates a video stream. |

### `fccHandler`

Four-character code for the compressor handler that will compress this video stream when it is saved (for example, [mmioFOURCC](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mmiofourcc) ('M','S','V','C')). This member is not used for audio streams.

### `dwKeyFrameEvery`

Maximum period between video key frames. This member is used only if the AVICOMPRESSF_KEYFRAMES flag is set; otherwise every video frame is a key frame.

### `dwQuality`

Quality value passed to a video compressor. This member is not used for an audio compressor.

### `dwBytesPerSecond`

Video compressor data rate. This member is used only if the AVICOMPRESSF_DATARATE flag is set.

### `dwFlags`

Flags used for compression. The following values are defined:

| Name | Description |
| --- | --- |
| **AVICOMPRESSF_DATARATE** | Compresses this video stream using the data rate specified in **dwBytesPerSecond**. |
| **AVICOMPRESSF_INTERLEAVE** | Interleaves this stream every **dwInterleaveEvery** frames with respect to the first stream. |
| **AVICOMPRESSF_KEYFRAMES** | Saves this video stream with key frames at least every **dwKeyFrameEvery** frames. By default, every frame will be a key frame. |
| **AVICOMPRESSF_VALID** | Uses the data in this structure to set the default compression values for [AVISaveOptions](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avisaveoptions). If an empty structure is passed and this flag is not set, some defaults will be chosen. |

### `lpFormat`

Pointer to a structure defining the data format. For an audio stream, this is an **LPWAVEFORMAT** structure.

### `cbFormat`

Size, in bytes, of the data referenced by **lpFormat**.

### `lpParms`

Video-compressor-specific data; used internally.

### `cbParms`

Size, in bytes, of the data referenced by **lpParms**

### `dwInterleaveEvery`

Interleave factor for interspersing stream data with data from the first stream. Used only if the AVICOMPRESSF_INTERLEAVE flag is set.

## See also

AVIFile Functions and Macros

[AVIFile Structures](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-structures)

[AVIMakeCompressedStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avimakecompressedstream)

[AVISave](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avisavea)

[AVISaveOptions](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avisaveoptions)

[mmioFOURCC](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mmiofourcc)