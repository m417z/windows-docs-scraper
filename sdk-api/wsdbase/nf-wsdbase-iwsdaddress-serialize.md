# IWSDAddress::Serialize

## Description

Assembles the component parts of the address into a string.

## Parameters

### `pszBuffer` [out]

Buffer to receive the assembled address.

### `cchLength` [in]

Length of *pszBuffer*, in bytes.

### `fSafe` [in]

If **TRUE**, the resulting string will be network safe. For example, if you used [IWSDTransportAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdtransportaddress) to build an IPv6 address, the serialized string will not contain the IPv6 scope identifier. However, if *fSafe* is **FALSE**, then the resulting string will contain the IPv6 scope identifier. For all other [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) derived objects, there is no specific meaning for this parameter (other than ensuring that the method generate portable addresses).

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pszBuffer* is **NULL**. |
| **E_ABORT** | The method could not be completed. |

## See also

[IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress)