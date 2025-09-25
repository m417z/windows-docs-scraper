# IWICJpegFrameDecode::CopyScan

## Description

Retrieves a copy of the compressed JPEG scan directly from the WIC decoder frame's output stream.

## Parameters

### `scanIndex`

Type: **UINT**

The zero-based index of the scan for which data is retrieved.

### `scanOffset`

Type: **UINT**

The byte position in the scan data to begin copying. Use 0 on the first call. If the output buffer size is insufficient to store the entire scan, this offset allows you to resume copying from the end of the previous copy operation.

### `cbScanData`

Type: **UINT**

The size, in bytes, of the *pbScanData* array.

### `pbScanData` [out]

Type: **BYTE***

A pointer that receives the table data. This parameter must not be NULL.

### `pcbScanDataActual` [out]

Type: **UINT***

A pointer that receives the size of the scan data actually copied into *pbScanData*. The size returned may be smaller that the size of *cbScanData*. This parameter may be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The operation was successful. |
| WINCODEC_ERR_INVALIDJPEGSCANINDEX | The specified scan index is invalid. |

## See also

[IWICJpegFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicjpegframedecode)