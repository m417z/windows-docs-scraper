# UNCOMPRESSEDAUDIOFORMAT structure

## Description

The UNCOMPRESSEDAUDIOFORMAT structure specifies the frame rate, channel mask, and other attributes of the uncompressed audio data format.

## Members

### `guidFormatType`

Specifies the GUID of the data format type.

### `dwSamplesPerFrame`

Specifies the number of samples per frame.

### `dwBytesPerSampleContainer`

Specifies the number of bytes that make up a unit container of the sample.

### `dwValidBitsPerSample`

Specifies the number of valid bits per sample.

### `fFramesPerSecond`

Specifies the number of frames per second of streaming audio data.

### `dwChannelMask`

Specifies the channel mask that is used by the uncompressed audio data.

## Remarks

This structure provides access to the parameters that describe an uncompressed PCM audio format.