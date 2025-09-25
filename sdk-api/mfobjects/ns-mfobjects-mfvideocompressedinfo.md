# MFVideoCompressedInfo structure

## Description

Contains information about a video compression format. This structure is used in the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

## Members

### `AvgBitrate`

Average bit rate of the encoded video stream, in bits per second.

### `AvgBitErrorRate`

Expected error rate, in bits per second.

### `MaxKeyFrameSpacing`

Number of frames between key frames.

## Remarks

For uncompressed video formats, set the structure members to zero.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)