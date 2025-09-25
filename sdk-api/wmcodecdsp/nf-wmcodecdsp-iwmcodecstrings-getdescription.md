# IWMCodecStrings::GetDescription

## Description

Retrieves the description of an output format.

## Parameters

### `pmt` [in]

Pointer to the output media type. If **NULL**, the codec will use the media type that is currently set.

### `cchLength` [in]

Size of szDescription buffer, in wide characters.

### `szDescription` [out]

Address of the wide-character buffer that receives the description. If **NULL**, pcchLength receives the required length.

### `pcchLength` [out]

Pointer to the required buffer length in wide characters, including the null terminating character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMCodecStrings Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecstrings)