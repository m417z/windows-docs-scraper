# MFCreateMediaBufferFromMediaType function

## Description

Allocates a system-memory buffer that is optimal for a specified media type.

## Parameters

### `pMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type.

### `llDuration` [in]

The sample duration. This value is required for audio formats.

### `dwMinLength` [in]

The minimum size of the buffer, in bytes. The actual buffer size might be larger. Specify zero to allocate the default buffer size for the media type.

### `dwMinAlignment` [in]

The minimum memory alignment for the buffer. Specify zero to use the default memory alignment.

### `ppBuffer` [out]

Receives a pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For video formats, if the format is recognized, the function creates a 2-D buffer that implements the [IMF2DBuffer2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer2) interface. Otherwise it creates a linear buffer. To get the **IMF2DBuffer2** interface, call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the pointer returned in *ppBuffer*. If the **QueryInterface** method fails, use the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface to access the buffer memory.

For audio formats, the function allocates a buffer that is large enough to contain *llDuration* audio samples, or *dwMinLength*, whichever is larger.

This function always allocates system memory. For Direct3D surfaces, use the [MFCreateDXGISurfaceBuffer](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatedxgisurfacebuffer) or [MFCreateDXSurfaceBuffer](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatedxsurfacebuffer) function.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)