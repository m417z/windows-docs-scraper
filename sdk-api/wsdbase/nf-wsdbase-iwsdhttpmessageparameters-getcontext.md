# IWSDHttpMessageParameters::GetContext

## Description

Retrieves the private transmission context for the current transaction.

## Parameters

### `ppContext` [out]

Pointer to the pointer used to retrieve the desired private transmission context for the current transaction.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *ppContext* is NULL. |
| **E_FAIL** | Could not retrieve the context. |

## See also

[IWSDHttpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpmessageparameters)