# IWSDHttpMessageParameters::SetID

## Description

Sets the transport ID for the current transaction.

## Parameters

### `pszId` [in]

Pointer to the desired transport ID for the current transaction.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszId* is **NULL** or the length in characters of *pszId* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[IWSDHttpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpmessageparameters)