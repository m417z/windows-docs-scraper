# KsSetPowerDispatch function

## Description

Sets the power dispatch function to be called when the driver object receives an **IRP_MJ_POWER** IRP. This is only effective if **KsDefaultDispatchPower** is called to dispatch or complete power IRPs.

This has the effect of adding this object header to a list of object headers that have power dispatch routines to execute. The head of this list is kept by the device header. Assumes that the caller has previously allocated a device header on the underlying Device Object with **KsAllocateDeviceHeader**.

## Parameters

### `Header` [in]

Points to a header previously allocated by **KsAllocateObjectHeader**.

### `PowerDispatch` [in, optional]

Optionally contains the power dispatch function that will be called, or **NULL** if the function is to be removed from the list of functions being called. This function must not complete the power IRP sent. The return value of this function must be STATUS_SUCCESS. **KsSetPowerDispatch** can be called while executing this power dispatch routine if the purpose is to manipulate this list entry only. Manipulating other list entries may confuse the current enumeration.

### `PowerContext` [in, optional]

Optionally contains the context parameter to pass to the power dispatch function.

## Return value

None

## See also

[KStrContextDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscontext_dispatch)