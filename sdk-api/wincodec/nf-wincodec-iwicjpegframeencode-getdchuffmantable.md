# IWICJpegFrameEncode::GetDcHuffmanTable

## Description

Retrieves a copy of the DC Huffman table for the specified scan and table.

## Parameters

### `scanIndex`

The zero-based index of the scan for which data is retrieved.

### `tableIndex`

The index of the DC Huffman table to retrieve.

### `pDcHuffmanTable` [out]

A pointer that receives the table data. This parameter must not be NULL.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The operation was successful. |
| WINCODEC_ERR_INVALIDJPEGSCANINDEX | The specified scan index is invalid. |
| WINCODEC_ERR_INVALIDPARAMETER | Can occur if *pTable* is NULL or if *tableIndex* does not point to a valid table slot. Check the scan header for valid table indices. |

## See also

[IWICJpegFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicjpegframeencode)