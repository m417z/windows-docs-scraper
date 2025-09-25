# IDirectManipulationManager2::CreateBehavior

## Description

Factory method to create a behavior.

## Parameters

### `clsid` [in]

CLSID of the behavior. The CLSID specifies the type of behavior.

### `riid` [in]

The IID of the behavior interface to create.

### `object` [out, retval]

The new behavior object that implements the specified interface.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirectManipulationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationmanager2)