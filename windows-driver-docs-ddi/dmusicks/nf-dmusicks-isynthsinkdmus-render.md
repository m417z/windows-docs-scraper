# ISynthSinkDMus::Render

## Description

The `Render` method renders wave data into a destination sink.

## Parameters

### `pBuffer` [in]

Pointer to the buffer that the synth sink wants data written to

### `dwLength` [in]

Specifies the length (in bytes) of the data to be rendered.

### `llPosition` [in]

Specifies the position (in bytes) in the PCM buffer at which to begin rendering. Rendering continues from this position for the number of bytes specified in *dwLength*.

## Remarks

The port driver's synth-sink object calls this method when the miniport driver needs to render more wave data into the destination buffer.