# IWICBitmapSource::CopyPixels

## Description

Instructs the object to produce pixels.

## Parameters

### `prc` [in]

Type: **const [WICRect](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrect)***

The rectangle to copy. A **NULL** value specifies the entire bitmap.

### `cbStride` [in]

Type: **UINT**

The stride of the bitmap

### `cbBufferSize` [in]

Type: **UINT**

The size of the buffer.

### `pbBuffer` [out]

Type: **BYTE***

A pointer to the buffer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**CopyPixels** is one of the two main image processing routines (the other being [Lock](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmap-lock)) triggering the actual processing.
It instructs the object to produce pixels according to its algorithm - this may involve decoding a portion of a JPEG stored on disk, copying a block of memory, or even analytically computing a complex gradient.
The algorithm is completely dependent on the object implementing the interface.

The caller can restrict the operation to a rectangle of interest (ROI) using the prc parameter.
The ROI sub-rectangle must be fully contained in the bounds of the bitmap.
Specifying a **NULL** ROI implies that the whole bitmap should be returned.

The caller controls the memory management and must provide an output buffer (*pbBuffer*) for the results of the copy along with the buffer's bounds (*cbBufferSize*).
The cbStride parameter defines the count of bytes between two vertically adjacent pixels in the output buffer.
The caller must ensure that there is sufficient buffer to complete the call based on the width, height and pixel format of the bitmap and the sub-rectangle provided to the copy method.

If the caller needs to perform numerous copies of an expensive [IWICBitmapSource](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapsource) such as a JPEG, it is recommended to create an in-memory [IWICBitmap](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmap) first.

### Codec Developer Remarks

The callee must only write to the first (prc->Width*bitsperpixel+7)/8 bytes of each line of the output buffer (in this case, a line is a consecutive string of *cbStride* bytes).