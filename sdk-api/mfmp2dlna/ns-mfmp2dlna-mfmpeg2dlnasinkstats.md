# MFMPEG2DLNASINKSTATS structure

## Description

Contains encoding statistics from the Digital Living Network Alliance (DLNA) media sink.

This structure is used with the [MF_MP2DLNA_STATISTICS](https://learn.microsoft.com/windows/desktop/medfound/mf-mp2dlna-statistics) attribute.

## Members

### `cBytesWritten`

Total number of bytes written to the byte stream.

### `fPAL`

If **TRUE**, the video stream is a PAL format. Otherwise, the video stream is an NTSC format.

### `fccVideo`

A FOURCC code that specifies the video format.

### `dwVideoWidth`

The width of the video frame, in pixels.

### `dwVideoHeight`

The height of the video frame, in pixels.

### `cVideoFramesReceived`

The number of video frames received.

### `cVideoFramesEncoded`

The number of video frames that have been encoded.

### `cVideoFramesSkipped`

The number of video frames that have been skipped.

### `cBlackVideoFramesEncoded`

The number of black frames that have been encoded.

### `cVideoFramesDuplicated`

The number of duplicated video frames.

### `cAudioSamplesPerSec`

The audio sample rate, in samples per second.

### `cAudioChannels`

The number of audio channels.

### `cAudioBytesReceived`

The total amount of audio data received, in bytes.

### `cAudioFramesEncoded`

The number of audio frames that have been encoded.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)