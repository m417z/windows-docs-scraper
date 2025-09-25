# IWDTFTargets2::GetInterfacesIfExist

## Description

Returns a collection of actions that support the interface - one [IWDTFAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtfaction2) for each item
that has one.

## Parameters

### `WDTFInterfaceName` [in]

### `MoreTargets` [in, optional]

Optional extra arguments that you can use to define additional targets to attach to the returned interface.

This parameter is not currently implemented. Set *MoreTargets* to a **VARIANT**
that contains **VT_EMPTY**.

### `MonikerSuffix` [in, optional]

An optional moniker that defines more options about how the interface should be instantiated.

This parameter is not yet implemented. Set *MonikerSuffix* to a **VARIANT** that
contains **VT_EMPTY**.

### `ppInterface` [out, retval]

The address of a variable that will receive the collection of actions.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method will succeed even if one or more of the collection members do not return an action.

## See also

[IWDTFTargets2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftargets2)