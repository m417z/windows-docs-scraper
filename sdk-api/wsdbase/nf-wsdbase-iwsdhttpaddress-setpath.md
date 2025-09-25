# IWSDHttpAddress::SetPath

## Description

Sets the URI path for this address.

## Parameters

### `pszPath` [in]

The URI path to use for this address.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The length in characters of *pszPath* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_FAIL** | The method failed. |

## See also

[IWSDHttpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpaddress)