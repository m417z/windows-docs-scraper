# ICreateWithTipTransactionEx::CreateInstance

## Description

[The TIP service feature are deprecated and might not be available in future versions of the operating system. Consider using the WS-AtomicTransaction (WS-AT) protocol as a replacement transaction coordination and propagation technology. For more information about WS-AT support in the .Net Framework, see [Transactions](https://learn.microsoft.com/dotnet/framework/wcf/feature-details/transactions-in-wcf).]

Creates a COM+ object that executes within the scope of the manual transaction specified by a TIP transaction URL.

## Parameters

### `bstrTipUrl` [in]

The Transaction Internet Protocol (TIP) URL of the existing transaction in which you want to create the COM+ object.

### `rclsid` [in]

The CLSID of the type of object to be instantiated.

### `riid` [in]

The ID of the interface to be returned by the *ppvObj* parameter.

### `pObject` [out]

A reference to a new object of the type specified by the *rclsid* argument, through the interface specified by the *riid* argument.

## Return value

This method can return the following values:

## See also

[ICreateWithTipTransactionEx](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icreatewithtiptransactionex)