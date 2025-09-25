# IKeywordDetectorOemAdapter::GetCapabilities

## Description

The **GetCapabilities** method returns the keywords and languages supported by the object.

## Parameters

### `SupportsUserModels` [in]

A Boolean value that indicates whether user specific training is supported.

### `KeywordIds` [out]

A pointer to an array of keyword IDs supported by the object. The object allocates the array by calling [CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc). The caller frees the memory by calling [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `NumKeywords` [out]

The number of keyword IDs in the *KeywordIds* array.

### `LangIds` [out]

A pointer to an array of language IDs supported by the object. The object allocates the array by calling [CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc). The caller frees the memory by calling [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `NumLanguages` [out]

The number of language IDs in the *LangIds* array.

### `ppMediaType` [out]

The audio format required by [IKeywordDetectorOemAdapter::VerifyUserKeyword](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nf-keyworddetectoroemadapter-ikeyworddetectoroemadapter-verifyuserkeyword) and [IKeywordDetectorOemAdapter::ComputeAndAddUserModelData](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nf-keyworddetectoroemadapter-ikeyworddetectoroemadapter-computeandaddusermodeldata).

The only valid values for the IMFMediaType are the following:

* Type = Audio
* Subtype = IEEE_FLOAT
* Sampling Rate = 16 kHz
* Bits = 32

Typically, the OEMDLL calls [MFCreateMediaType](https://learn.microsoft.com/windows/win32/api/mfapi/nf-mfapi-mfcreatemediatype) and [MFInitMediaTypeFromWaveFormatEx](https://learn.microsoft.com/windows/win32/api/mfapi/nf-mfapi-mfinitmediatypefromwaveformatex) to obtain an [IMFMediaType](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfmediatype) pointer to return to the caller.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The function exited successfully. |
| E_POINTER | The pointer for an output parameter is **NULL**. |
| E_INVALIDARG | The pointer to the model data is **NULL**. |

## Remarks

The information returned from this routine would normally not change for a given version of the OEMDLL or the user independent model data installed along with it.

The OEMDLL must have internal user independent models for the keywords and languages returned from this method.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree)

[IKeywordDetectorOemAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nn-keyworddetectoroemadapter-ikeyworddetectoroemadapter)

[IKeywordDetectorOemAdapter::ComputeAndAddUserModelData](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nf-keyworddetectoroemadapter-ikeyworddetectoroemadapter-computeandaddusermodeldata)

[IKeywordDetectorOemAdapter::VerifyUserKeyword](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nf-keyworddetectoroemadapter-ikeyworddetectoroemadapter-verifyuserkeyword)

[IMFMediaType](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfmediatype)

[MFCreateMediaType](https://learn.microsoft.com/windows/win32/api/mfapi/nf-mfapi-mfcreatemediatype)

[MFInitMediaTypeFromWaveFormatEx](https://learn.microsoft.com/windows/win32/api/mfapi/nf-mfapi-mfinitmediatypefromwaveformatex)