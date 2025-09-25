## Description

Stores Peak Signal-to-Noise Ratio (PSNR) values for the Y, U, and V planes of an encoded video frame. PSNR is calculated by comparing the reconstructed frame to the original input frame.

## Members

### `psnrY`

The PSNR for the Y plane.

### `psnrU`

The PSNR for the U plane.

### `psnrV`

The PSNR for the V plane.

## Remarks

Use [IMFAttributes::SetUnknown](https://learn.microsoft.com/windows/win32/api/mfobjects/nf-mfobjects-imfattributes-setunknown) to attach an [IMFMediaBuffer](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfmediabuffer) containing the PSNR values to an output sample. Use [IMFAttributes::GetUnknown](https://learn.microsoft.com/windows/win32/api/mfobjects/nf-mfobjects-imfattributes-getunknown) to retrieve the **IMFMediaBuffer** containing the PSNR values from an output sample. The **IMFMediaBuffer** contains memory that matches the size of the **MFSampleExtensionPsnrYuv** structure.

PSNR should only be reported when the entire frame has completed encoding. If the encoder uses multiple slices, the PSNR buffer should be attached to the [IMFSample](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfsample) of the last slice.

If the encoder only supports PSNR for the Y plane, the *psnrU* and *psnrV* fields shall be zero.

[MFCreateDXGISurfaceBuffer](https://learn.microsoft.com/windows/win32/api/mfapi/nf-mfapi-mfcreatedxgisurfacebuffer) can be used to convert a GPU resource into an **IMFMediaBuffer**.

## See also