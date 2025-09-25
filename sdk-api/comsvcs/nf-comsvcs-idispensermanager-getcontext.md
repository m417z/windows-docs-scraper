# IDispenserManager::GetContext

## Description

Determines the current context.

## Parameters

### `__MIDL__IDispenserManager0002` [out]

An internal unique identifier of the current object, or 0 if no current object. This may not be interpreted as an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer to the current object.

### `__MIDL__IDispenserManager0003` [out]

The transaction that the current object is running in, or 0 if none. This value may be cast to **ITransaction ***.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## See also

[IDispenserManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispensermanager)