# D3D11_1DDIARG_CREATEVIDEOPROCESSORINPUTVIEW structure

## Description

Describes the video processor's input view.

## Members

### `hDrvResource`

A handle to the video decoder input resource.

### `hDrvVideoProcessorEnum`

A handle to the video processor enumeration.

### `FourCC`

A FOURCC code that the application uses to override the surface format. A value of zero indicates that the application will not override the resource format.

For example, if a new video standard emerges that requires a new substream format, the application can create an equivalent surface using a standard format and then specify a FOURCC code when it creates a view to indicate that the data is laid out according to the new video standard.

For more information about FOURCC codes, see [Video FOURCCs](https://learn.microsoft.com/windows/win32/medfound/video-fourccs).

### `MipSlice`

The identifier of the MIP-map slice.

### `FirstArraySlice`

The identifier of the first array slice.

### `ArraySize`

The number of array slices for the texture.

## See also

[D3D11_1DDIARG_CREATEVIDEOPROCESSOROUTPUTVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createvideoprocessoroutputview)