# AVISTREAMINFOW structure

## Description

The **AVISTREAMINFO** structure contains information for a single stream.

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

Four-character code of the compressor handler that will compress this video stream when it is saved (for example, [mmioFOURCC](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mmiofourcc) ('M','S','V','C')). This member is not used for audio streams.

### `dwFlags`

Applicable flags for the stream. The bits in the high-order word of these flags are specific to the type of data contained in the stream. The following flags are defined:

| Name | Description |
| --- | --- |
| **AVISTREAMINFO_DISABLED** | Indicates this stream should be rendered when explicitly enabled by the user. |
| **AVISTREAMINFO_FORMATCHANGES** | Indicates this video stream contains palette changes. This flag warns the playback software that it will need to animate the palette. |

### `dwCaps`

Capability flags; currently unused.

### `wPriority`

Priority of the stream.

### `wLanguage`

Language of the stream.

### `dwScale`

Time scale applicable for the stream. Dividing **dwRate** by **dwScale** gives the playback rate in number of samples per second.

For video streams, this rate should be the frame rate. For audio streams, this rate should correspond to the audio block size (the **nBlockAlign** member of the [WAVEFORMAT](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveformatex) or [PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85)) structure), which for PCM (Pulse Code Modulation) audio reduces to the sample rate.

### `dwRate`

Rate in an integer format. To obtain the rate in samples per second, divide this value by the value in **dwScale**.

### `dwStart`

Sample number of the first frame of the AVI file. The units are defined by dwRate and **dwScale**. Normally, this is zero, but it can specify a delay time for a stream that does not start concurrently with the file.

The 1.0 release of the AVI tools does not support a nonzero starting time.

### `dwLength`

Length of this stream. The units are defined by **dwRate** and **dwScale**.

### `dwInitialFrames`

Audio skew. This member specifies how much to skew the audio data ahead of the video frames in interleaved files. Typically, this is about 0.75 seconds.

### `dwSuggestedBufferSize`

Recommended buffer size, in bytes, for the stream. Typically, this member contains a value corresponding to the largest chunk in the stream. Using the correct buffer size makes playback more efficient. Use zero if you do not know the correct buffer size.

### `dwQuality`

Quality indicator of the video data in the stream. Quality is represented as a number between 0 and 10,000. For compressed data, this typically represents the value of the quality parameter passed to the compression software. If set to –1, drivers use the default quality value.

### `dwSampleSize`

Size, in bytes, of a single data sample. If the value of this member is zero, the samples can vary in size and each data sample (such as a video frame) must be in a separate chunk. A nonzero value indicates that multiple samples of data can be grouped into a single chunk within the file.

For video streams, this number is typically zero, although it can be nonzero if all video frames are the same size. For audio streams, this number should be the same as the **nBlockAlign** member of the [WAVEFORMAT](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveformatex) or [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure describing the audio.

### `rcFrame`

Dimensions of the video destination rectangle. The values represent the coordinates of upper left corner, the height, and the width of the rectangle.

### `dwEditCount`

Number of times the stream has been edited. The stream handler maintains this count.

### `dwFormatChangeCount`

Number of times the stream format has changed. The stream handler maintains this count.

### `szName`

Null-terminated string containing a description of the stream.

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Structures](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-structures)

[PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85))

[WAVEFORMAT](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveformatex)

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))

[mmioFOURCC](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-mmiofourcc)

## Remarks

> [!NOTE]
> The vfw.h header defines AVISTREAMINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).