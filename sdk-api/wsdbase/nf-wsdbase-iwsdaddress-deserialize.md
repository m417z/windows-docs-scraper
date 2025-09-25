# IWSDAddress::Deserialize

## Description

Parses the address, validates its component parts and saves them in the object.

## Parameters

### `pszBuffer` [in]

Address to save in the object.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszBuffer* is **NULL**, its length in characters exceeds WSD_MAX_TEXT_LENGTH (8192), or it does not contain an address in a valid format. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress)