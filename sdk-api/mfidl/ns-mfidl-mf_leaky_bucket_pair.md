# MF_LEAKY_BUCKET_PAIR structure

## Description

Specifies the buffering requirements of a file.

## Members

### `dwBitrate`

Bit rate, in bits per second.

### `msBufferWindow`

Size of the buffer window, in milliseconds.

## Remarks

This structure describes the buffering requirements for content encoded at the bit rate specified in the **dwBitrate**. The **msBufferWindow** member indicates how much data should be buffered before starting playback. The size of the buffer in bytes is **msBufferWinow**×**dwBitrate** / 8000.

## See also

[MFBYTESTREAM_BUFFERING_PARAMS](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfbytestream_buffering_params)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)