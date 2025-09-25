# IWSDUdpAddress::GetAlias

## Description

Gets the alias for the discovery address. This method is reserved for internal use and should not be called.

## Parameters

### `pAlias` [out]

Pointer to the alias of the discovery address.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pAlias* is **NULL**. |

## See also

[IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress)