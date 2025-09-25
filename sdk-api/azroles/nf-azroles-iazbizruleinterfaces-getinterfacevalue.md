# IAzBizRuleInterfaces::GetInterfaceValue

## Description

The **GetInterfaceValue** method gets the ID and flags of the interface that corresponds to the specified interface name.

## Parameters

### `bstrInterfaceName` [in]

A string that contains the interface name.

### `lInterfaceFlag` [out]

A pointer to the flags associated with the interface name.

### `varInterface` [out]

A pointer to the ID associated with the interface name.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[AddInterface](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazbizruleinterfaces-addinterface)

[IAzBizRuleInterfaces](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazbizruleinterfaces)