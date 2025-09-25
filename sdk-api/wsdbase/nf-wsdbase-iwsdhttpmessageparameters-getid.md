# IWSDHttpMessageParameters::GetID

## Description

Retrieves the transport ID for the current transaction.

## Parameters

### `ppszId` [out]

Pointer used to return the transport ID for the current transaction. Do not deallocate this pointer.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *ppszId* is **NULL**. |
| **E_FAIL** | The transport ID is not available. |

## See also

[IWSDHttpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpmessageparameters)