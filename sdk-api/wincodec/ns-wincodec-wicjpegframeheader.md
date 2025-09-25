# WICJpegFrameHeader structure

## Description

Represents a JPEG frame header.

## Members

### `Width`

The width of the JPEG frame.

### `Height`

The height of the JPEG frame.

### `TransferMatrix`

The transfer matrix of the JPEG frame.

### `ScanType`

The scan type of the JPEG frame.

### `cComponents`

The number of components in the frame.

### `ComponentIdentifiers`

The component identifiers.

### `SampleFactors`

The sample factors. Use one of the following constants, described in [IWICJpegFrameDecode Constants](https://learn.microsoft.com/windows/desktop/wic/iwicjpegframedecode-constants).

* WIC_JPEG_SAMPLE_FACTORS_ONE
* WIC_JPEG_SAMPLE_FACTORS_THREE_420
* WIC_JPEG_SAMPLE_FACTORS_THREE_422
* WIC_JPEG_SAMPLE_FACTORS_THREE_440
* WIC_JPEG_SAMPLE_FACTORS_THREE_444

### `QuantizationTableIndices`

The format of the quantization table indices. Use one of the following constants, described in [IWICJpegFrameDecode Constants](https://learn.microsoft.com/windows/desktop/wic/iwicjpegframedecode-constants).

* WIC_JPEG_QUANTIZATION_BASELINE_ONE
* WIC_JPEG_QUANTIZATION_BASELINE_THREE

## Remarks

Get the frame header for an image by calling [IWICJpegFrameDecode::GetFrameHeader](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicjpegframedecode-getframeheader).

## See also

[IWICJpegFrameDecode::GetFrameHeader](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicjpegframedecode-getframeheader)