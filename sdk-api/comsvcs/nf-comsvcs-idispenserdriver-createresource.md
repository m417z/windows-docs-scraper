# IDispenserDriver::CreateResource

## Description

Creates a resource.

## Parameters

### `ResTypId` [in]

The type of resource to be created.

### `pResId` [out]

A handle to the newly created resource.

### `pSecsFreeBeforeDestroy` [out]

The time-out of the new resource. This is the number of seconds that this resource is allowed to remain idle in the pool before it is destroyed.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

The **CreateResource** method is called by the Dispenser Manager in the following cases:

* When a resource is needed and there is no inventory to satisfy an [IHolder::AllocResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iholder-allocresource) call when none were found in inventory.
* When the Dispenser Manager is setting up initial inventory.

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)