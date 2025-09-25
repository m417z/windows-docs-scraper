# D3DWDDM2_4DDIARG_VIDEODECODERBEGINFRAME_RS4_0 structure

## Description

A collection of histogram output buffers.

## Members

### `hOutputView`

A handle to the driver's private data for the video decoder output view. This handle was created through a call to the CreateVideoProcessorOutputView function.

### `pContentKey`

A pointer to a content key that was used to encrypt the video frame data. If no content key was used, set this member to NULL. If the caller provides a content key, the caller must use the session key to encrypt the content key.

### `ContentKeySize`

The size, in bytes, of the content key that is specified in the pContentKey member.

### `Histograms`

The array of component histograms. A disabled component has it’s struct members set to zero.

## Remarks

## See also