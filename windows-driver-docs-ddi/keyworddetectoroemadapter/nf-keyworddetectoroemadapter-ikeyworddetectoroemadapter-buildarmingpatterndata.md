# IKeywordDetectorOemAdapter::BuildArmingPatternData

## Description

The **BuildArmingPatternData** method is called by the operating system to build OEM-specific pattern data that includes any keyword and user-specific model data for detection.

## Parameters

### `UserModelData` [in]

A pointer to **IStream** bound to model data for the [KEYWORDSELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/ns-keyworddetectoroemadapter-__midl_ikeyworddetectoroemadapter_0003) values in the *KeywordSelectors* parameter.

### `KeywordSelectors` [in]

An array of [KEYWORDSELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/ns-keyworddetectoroemadapter-__midl_ikeyworddetectoroemadapter_0003) structures identifying the desired set of matches for the keyword detector to arm.

### `NumKeywordSelectors` [in]

The number of items in the *KeywordSelectors* array. Only one key word selector is supported and this field must be set to one.

### `ppPatternData` [out]

The pattern data for the operating system to pass to the audio driver. The OEMDLL allocates the memory calling [CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc). The operating system will free the memory by calling [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The function exited successfully. |
| E_POINTER | The *ModelData* pointer is **NULL**. |
| E_INVALIDARG | The *KeywordId* or *LangId* parameters are invalid. |
| HRESULT_FROM_WIN32(ERROR_GEN_FAILURE) | The processing was unable to complete. |

## Remarks

The operating system may call this method at any time. The operating system may also store the returned pattern data to reuse later for the same set of keyword selectors.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc)

[CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree)

[IKeywordDetectorOemAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nn-keyworddetectoroemadapter-ikeyworddetectoroemadapter)

[KEYWORDSELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/ns-keyworddetectoroemadapter-__midl_ikeyworddetectoroemadapter_0003)