# IDispenserManager::RegisterDispenser

## Description

Registers the resource dispenser with the dispenser manager.

## Parameters

### `__MIDL__IDispenserManager0000` [in]

The [IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver) interface the Resource Dispenser offers to the Dispenser Manager to use later to notify the Resource Dispenser.

### `szDispenserName` [in]

A friendly name of the Resource Dispenser for administrator display.

### `__MIDL__IDispenserManager0001` [out]

The [IHolder](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iholder) interface that has been instantiated for the resource dispenser.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

The Resource Dispenser notifies the Dispenser Manager that it has started and is prepared to accept notifications on this [IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver) interface. Then the Dispenser Manager creates the Holder for this new Resource Dispenser and returns it to the Resource Dispenser.

This method does not call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the *pDispenserDriver* object, but [IHolder::Close](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iholder-close) does perform a [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on *pDispenserDriver*. This can cause the Resource Dispenser object to be destroyed prematurely. To prevent this premature destruction, the caller of **IDispenserManager::RegisterDispenser** must explicitly call **AddRef** on the *pDispenserDriver* object.

## See also

[IDispenserManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispensermanager)