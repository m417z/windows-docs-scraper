# WICJpegScanHeader structure

## Description

Represents a JPEG frame header.

## Members

### `cComponents`

The number of components in the scan.

### `RestartInterval`

The interval of reset markers within the scan.

### `ComponentSelectors`

The component identifiers.

### `HuffmanTableIndices`

The format of the quantization table indices. Use one of the following constants, described in [IWICJpegFrameDecode Constants](https://learn.microsoft.com/windows/desktop/wic/iwicjpegframedecode-constants).

* WIC_JPEG_HUFFMAN_BASELINE_ONE
* WIC_JPEG_HUFFMAN_BASELINE_THREE

### `StartSpectralSelection`

The start of the spectral selection.

### `EndSpectralSelection`

The end of the spectral selection.

### `SuccessiveApproximationHigh`

The successive approximation high.

### `SuccessiveApproximationLow`

The successive approximation low.

## Remarks

Get the scan header for an image by calling [IWICJpegFrameDecode::GetScanHeader](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicjpegframedecode-getscanheader).