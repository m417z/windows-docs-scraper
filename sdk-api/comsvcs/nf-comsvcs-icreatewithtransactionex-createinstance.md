# ICreateWithTransactionEx::CreateInstance

## Description

Creates a COM+ object that executes within the scope of a manual transaction specified with a reference to an **ITransaction** interface.

## Parameters

### `pTransaction` [in]

An **ITransaction** interface pointer indicating the transaction in which you want to create the COM+ object.

### `rclsid` [in]

The CLSID of the type of object to instantiate.

### `riid` [in]

The ID of the interface to be returned by the *ppvObj* parameter.

### `pObject` [out]

A new object of the type specified by the *rclsid* argument through the interface specified by the *riid* argument.

## Return value

This method can return the following values:

## See also

[ICreateWithTransactionEx](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icreatewithtransactionex)