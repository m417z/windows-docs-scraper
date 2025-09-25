# IWICJpegFrameDecode::GetFrameHeader

## Description

Retrieves header data from the entire frame. The result includes parameters from the Start Of Frame (SOF) marker for the scan as well as parameters derived from other metadata such as the color model of the compressed data.

## Parameters

### `pFrameHeader` [out]

Type: **[WICJpegFrameHeader](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicjpegframeheader)***

A pointer that receives the frame header data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on successful completion.

## See also

[IWICJpegFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicjpegframedecode)

[WICJpegFrameHeader](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicjpegframeheader)