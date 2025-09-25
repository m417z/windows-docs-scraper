# IKeywordDetectorOemAdapter::VerifyUserKeyword

## Description

The **VerifyUserKeyword** method is used by the training user experience to verify that one instance of a spoken utterance, captured during training, matches a predefined keyword within some tolerance.

## Parameters

### `ModelData` [in]

A pointer to an **IStream** object bound to model data for a given stored model. On the initial call this will be empty.

### `KeywordId` [in]

The [KEYWORDID](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/ne-keyworddetectoroemadapter-__midl_ikeyworddetectoroemadapter_0002) in the *UserRecording* parameter.

### `LangId` [in]

The **LANGID** of the spoken language in the *UserRecording* parameter.

### `KeywordEndBytePos` [in]

Indicates the end of the keyword in the UserRecording.

### `UserRecording` [in]

A pointer to the buffer containing the raw data in the appropriate [IMFMediaType](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfmediatype) format.

The user recording must have the following attributes:

* Type = Audio
* Subtype = IEEE_FLOAT
* Sampling Rate = 16 kHz
* Bits = 32

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function exited successfully. |
| **E_NOTIMPL** | User keyword training is not supported for the device. |
| **E_INVALIDARG** | One or more of the following conditions are true:<br><br>* The *ModelData* pointer is **NULL**.<br>* The *KeywordId* parameter is invalid.<br>* The *LangId* parameter is invalid. |
| **E_NO_MATCH** | The user recording didn't contain the specified keyword. |

## Remarks

Note that audio is processed in a unique way for voice activation training. The following table summarizes the differences between voice activation training and the regular voice recognition usage.

|  |  |  |
| --- | --- | --- |
|  | **Training** | **Recognition** |
| Mode | Raw | Speech |
| Pin | Normal | Burst |
| Audio Format | 32-bit float (Type = Audio, Subtype = IEEE_FLOAT, Sampling Rate = 16 kHz, bits = 32) | Managed by OS audio stack |
| Mic | Mic 0 | All mics in array |

## See also

[IKeywordDetectorOemAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/nn-keyworddetectoroemadapter-ikeyworddetectoroemadapter)

[IMFMediaType](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfmediatype)

[KEYWORDID](https://learn.microsoft.com/windows-hardware/drivers/ddi/keyworddetectoroemadapter/ne-keyworddetectoroemadapter-__midl_ikeyworddetectoroemadapter_0002)