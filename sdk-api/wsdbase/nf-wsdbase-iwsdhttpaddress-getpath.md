# IWSDHttpAddress::GetPath

## Description

Gets the URI path for this address.

## Parameters

### `ppszPath` [out]

Pointer to the URI path for this address. Do not release this object.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppszPath* is **NULL**. |

## See also

[IWSDHttpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpaddress)