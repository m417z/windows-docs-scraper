# IKeywordDetectorOemAdapter::ComputeAndAddUserModelData

## Description

The **ComputeAndAddUserModelData** method is used by the training user experience to compute the user-specific information relative to the user-independent keyword. The DLL updates the *ModelData* parameter with the results.

## Parameters

### `ModelData` [in]

A pointer to the **IStream** object bound to model data. It is modified by this call.

### `KeywordSelector` [in]

A [KEYWORDSELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/ns-keyworddetectoroemadapter-__midl_ikeyworddetectoroemadapter_0003) struct that uniquely identifies this model.

### `KeywordEndBytePos` [in]

Indicates the end of the keyword in the UserRecording.

### `UserRecordings` [in]

A pointer to an array of pointers to the previously verified user recordings of the keyword.

### `NumUserRecordings` [in]

The number of recordings.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The function exited successfully. |
| E_NOTIMPL | User keyword training is not supported by the device. |
| E_INVALIDARG | Either the *KeywordId* or *LangId* parameters are invalid. |
| HRESULT_FROM_WIN32(ERROR_GEN_FAILURE) | The processing was unable to complete. |

## See also

[IKeywordDetectorOemAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nn-keyworddetectoroemadapter-ikeyworddetectoroemadapter)

[KEYWORDSELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/ns-keyworddetectoroemadapter-__midl_ikeyworddetectoroemadapter_0003)