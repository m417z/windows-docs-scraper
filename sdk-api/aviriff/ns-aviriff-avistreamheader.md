# AVISTREAMHEADER structure

## Description

The **AVISTREAMHEADER** structure contains information about one stream in an AVI file.

## Members

### `fcc`

Specifies a FOURCC code. The value must be 'strh'.

### `cb`

Specifies the size of the structure, not including the initial 8 bytes.

### `fccType`

Contains a FOURCC that specifies the type of the data contained in the stream. The following standard AVI values for video and audio are defined.

| FOURCC | Description |
| --- | --- |
| **'auds'** | Audio stream |
| **'mids'** | MIDI stream |
| **'txts'** | Text stream |
| **'vids'** | Video stream |

### `fccHandler`

Optionally, contains a FOURCC that identifies a specific data handler. The data handler is the preferred handler for the stream. For audio and video streams, this specifies the codec for decoding the stream.

### `dwFlags`

Contains any flags for the data stream. The bits in the high-order word of these flags are specific to the type of data contained in the stream. The following standard flags are defined.

| Value | Meaning |
| --- | --- |
| **AVISF_DISABLED** | Indicates this stream should not be enabled by default. |
| **AVISF_VIDEO_PALCHANGES** | Indicates this video stream contains palette changes. This flag warns the playback software that it will need to animate the palette. |

### `wPriority`

Specifies priority of a stream type. For example, in a file with multiple audio streams, the one with the highest priority might be the default stream.

### `wLanguage`

Language tag.

### `dwInitialFrames`

Specifies how far audio data is skewed ahead of the video frames in interleaved files. Typically, this is about 0.75 seconds. If you are creating interleaved files, specify the number of frames in the file prior to the initial frame of the AVI sequence in this member. For more information, see the remarks for the **dwInitialFrames** member of the [AVIMAINHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avimainheader) structure.

### `dwScale`

Used with **dwRate** to specify the time scale that this stream will use. Dividing **dwRate** by **dwScale** gives the number of samples per second. For video streams, this is the frame rate. For audio streams, this rate corresponds to the time needed to play **nBlockAlign** bytes of audio, which for PCM audio is the just the sample rate.

### `dwRate`

See **dwScale**.

### `dwStart`

Specifies the starting time for this stream. The units are defined by the **dwRate** and **dwScale** members in the main file header. Usually, this is zero, but it can specify a delay time for a stream that does not start concurrently with the file.

### `dwLength`

Specifies the length of this stream. The units are defined by the **dwRate** and **dwScale** members of the stream's header.

### `dwSuggestedBufferSize`

Specifies how large a buffer should be used to read this stream. Typically, this contains a value corresponding to the largest chunk present in the stream. Using the correct buffer size makes playback more efficient. Use zero if you do not know the correct buffer size.

### `dwQuality`

Specifies an indicator of the quality of the data in the stream. Quality is represented as a number between 0 and 10,000. For compressed data, this typically represents the value of the quality parameter passed to the compression software. If set to –1, drivers use the default quality value.

### `dwSampleSize`

Specifies the size of a single sample of data. This is set to zero if the samples can vary in size. If this number is nonzero, then multiple samples of data can be grouped into a single chunk within the file. If it is zero, each sample of data (such as a video frame) must be in a separate chunk. For video streams, this number is typically zero, although it can be nonzero if all video frames are the same size. For audio streams, this number should be the same as the **nBlockAlign** member of the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure describing the audio.

### `rcFrame`

Specifies the destination rectangle for a text or video stream within the movie rectangle specified by the **dwWidth** and **dwHeight** members of the AVI main header structure. The **rcFrame** member is typically used in support of multiple video streams. Set this rectangle to the coordinates corresponding to the movie rectangle to update the whole movie rectangle. Units for this member are pixels. The upper-left corner of the destination rectangle is relative to the upper-left corner of the movie rectangle.

### `rcFrame.left`

### `rcFrame.top`

### `rcFrame.right`

### `rcFrame.bottom`

## Remarks

Some of the members of this structure are also present in the [AVIMAINHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avimainheader) structure. The data in the **AVIMAINHEADER** structure applies to the whole file, while the data in the **AVISTREAMHEADER** structure applies to one stream.

The header file Vfw.h defines a **AVIStreamHeader** structure that is equivalent to this structure, but omits the **fcc** and **cb** members.

## See also

[AVI RIFF File Reference](https://learn.microsoft.com/windows/desktop/DirectShow/avi-riff-file-reference)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)