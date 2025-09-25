# IWICJpegFrameDecode::GetQuantizationTable

## Description

Retrieves a copy of the quantization table.

## Parameters

### `scanIndex`

Type: **UINT**

The zero-based index of the scan for which data is retrieved.

### `tableIndex`

Type: **UINT**

The index of the quantization table to retrieve. Valid indices for a given scan can be determined by retrieving the scan header with [IWICJpegFrameDecode::GetScanHeader](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicjpegframedecode-getscanheader).

### `pQuantizationTable` [out]

Type: **[DXGI_JPEG_QUANTIZATION_TABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-jpeg-quantization-table)***

A pointer that receives the table data. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The operation was successful. |
| WINCODEC_ERR_INVALIDJPEGSCANINDEX | The specified scan index is invalid. |
| WINCODEC_ERR_INVALIDPARAMETER | Can occur if *pTable* is NULL or if *tableIndex* does not point to a valid table slot. Check the scan header for valid table indices. |

## See also

[IWICJpegFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicjpegframedecode)