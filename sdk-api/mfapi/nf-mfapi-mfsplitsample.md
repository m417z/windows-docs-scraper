## Description

Split up a combined media sample back into individual samples.

## Parameters

### `pSample`

A pointer to an [IMFSample](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfsample) representing a combined sample to be split.

### `pOutputSamples`

Receives a pointer to an array of output samples from the split operation.

### `dwOutputSampleMaxCount`

The maximum output array size. Call [IMFSample::GetBufferCount](https://learn.microsoft.com/windows/win32/api/mfobjects/nf-mfobjects-imfsample-getbuffercount) on the sample provided in *pSample* to find out an upper bound.

### `pdwOutputSampleCount`

Output parameter that receives the number of samples contained in the pOutputSamples array.

## Return value

## Remarks

Combine samples by calling [MFCombineSamples](https://learn.microsoft.com/windows/win32/api/mfapi/nf-mfapi-mfsplitsample)

## See also