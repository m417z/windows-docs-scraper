## Description

Concatenates a media sample onto another sample if their combined duration does not exceed the specified duration.

## Parameters

### `pSample`

A pointer to an [IMFSample](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfsample) to which the sample provided in the *pSampleToAdd* parameter is appended.

### `pSampleToAdd`

A pointer to an [IMFSample](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfsample) to append to the sample provided in the *pSample* parameter.

### `dwMaxMergedDurationInMS`

The maximum duration in milliseconds that the combined sample can fill for the operation to be successful.

### `pMerged`

Output parameter that receives a BOOL indicating whether the sample was successfully appended.

## Return value

Returns HRESULT.

## Remarks

Split combined samples by calling [MFSplitSample](https://learn.microsoft.com/windows/win32/api/mfapi/nf-mfapi-mfsplitsample)

## See also