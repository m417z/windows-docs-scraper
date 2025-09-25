# IWICJpegFrameDecode::GetScanHeader

## Description

Retrieves parameters from the Start Of Scan (SOS) marker for the scan with the specified index.

## Parameters

### `scanIndex`

Type: **UINT**

The index of the scan for which header data is retrieved.

### `pScanHeader` [out]

Type: **[WICJpegScanHeader](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicjpegscanheader)***

A pointer that receives the frame header data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on successful completion.

## See also

[IWICJpegFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicjpegframedecode)