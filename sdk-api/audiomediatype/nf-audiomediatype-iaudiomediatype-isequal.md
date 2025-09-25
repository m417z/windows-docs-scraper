# IAudioMediaType::IsEqual

## Description

The `IsEqual` method compares two media types and determines whether they are identical.

## Parameters

### `pIAudioType` [in]

Specifies a pointer to an [IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype) interface of the media type to compare.

### `pdwFlags` [out]

Specifies a pointer to a DWORD variable that contains the bitwise OR result of zero or more flags. These flags indicate the degree of similarity between the two media types. The following table shows the supported flags.

| Flag | Meaning |
| --- | --- |
| AUDIOMEDIATYPE_EQUAL_FORMAT_TYPES | The audio format types are the same. |
| AUDIOMEDIATYPE_EQUAL_FORMAT_DATA | The format information matches, not including extra data beyond the base [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure. |
| AUDIOMEDIATYPE_EQUAL_FORMAT_USER_DATA | The extra data is identical, or neither media type contains extra data. |

## Return value

The `IsEqual` method returns S_OK if it is successful, otherwise it returns one of the HRESULT values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One media type is invalid or both media types are invalid. |
| **S_FALSE** | The media types are not equal. Examine the *pdwFlags* parameter to determine how the media types differ. |

## Remarks

Both media types must have a major type, otherwise the method returns E_INVALIDARG. For more information about media types, see [Media Types](https://learn.microsoft.com/previous-versions//aa390528(v=vs.85)).

The MF_MEDIATYPE_EQUAL_FORMAT_DATA flag indicates that both media types have compatible attributes, although one might be a superset of the other. This method of comparison means that you can compare a partially-specified media type against a complete media type. For example, you might have two video types that describe the same format, but one type includes attributes for extended color information (chroma siting, nominal range, and so forth).

If the method succeeds and all the comparison flags are set in *pdwFlags*, the return value is S_OK. If the method succeeds but some comparison flags are not set, the method returns S_FALSE.

## See also

[IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype)

[Media Types](https://learn.microsoft.com/previous-versions//aa390528(v=vs.85))

[WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex)