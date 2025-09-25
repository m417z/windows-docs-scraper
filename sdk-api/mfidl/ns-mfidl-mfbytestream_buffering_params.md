# MFBYTESTREAM_BUFFERING_PARAMS structure

## Description

Specifies the buffering parameters for a network byte stream.

## Members

### `cbTotalFileSize`

Size of the file, in bytes. If the total size is unknown, set this member to -1.

### `cbPlayableDataSize`

Size of the playable media data in the file, excluding any trailing data that is not useful for playback. If this value is unknown, set this member to -1.

### `prgBuckets`

Pointer to an array of [MF_LEAKY_BUCKET_PAIR](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mf_leaky_bucket_pair) structures. Each member of the array gives the buffer window for a particular bit rate.

### `cBuckets`

The number of elements in the **prgBuckets** array.

### `qwNetBufferingTime`

Amount of data to buffer from the network, in 100-nanosecond units. This value is in addition to the buffer windows defined in the **prgBuckets** member.

### `qwExtraBufferingTimeDuringSeek`

Amount of additional data to buffer when seeking, in 100-nanosecond units. This value reflects the fact that downloading must start from the previous key frame before the seek point. If the value is unknown, set this member to zero.

### `qwPlayDuration`

The playback duration of the file, in 100-nanosecond units. If the duration is unknown, set this member to zero.

### `dRate`

Playback rate.

## See also

[IMFByteStreamBuffering](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreambuffering)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)