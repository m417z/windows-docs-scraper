# ICreateWithLocalTransaction::CreateInstanceWithSysTx

## Description

Creates a COM+ object that executes within the scope of the specified local transaction.

## Parameters

### `pTransaction` [in]

The transaction in which the requested object participates.

### `rclsid` [in]

The CLSID of the class from which to create the requested object.

### `riid` [in]

A reference to the interface identifier (IID) of the interface that is used to communicate with the request object.

### `pObject` [out, retval]

The address of the pointer variable that receives the interface pointer specified with *riid*.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## See also

[ICreateWithLocalTransaction](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icreatewithlocaltransaction)