# IWDTFTarget2::GetInterface

## Description

Returns an action for the target.

## Parameters

### `WDTFInterfaceName`

### `Args`

### `MonikerSuffix` [in, optional]

An optional moniker that defines more options about how the interface should be instantiated.

This parameter is not yet implemented. Set *MonikerSuffix* to a **VARIANT** that contains **VT_EMPTY**.

### `ppInterface` [out, retval]

The address of a variable that will receive the action.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **GetInterface** method is the most useful method in the WDTF object model.
**GetInterface** enables you to simply locate a target-specific
implementation of an action interface without caring about the specifics of the target.

To write a WDTF scenario, you must understand both the syntax and the semantics of the
requested action interface.

For more information about the **GetInterface** method,
see [Controlling Targets](https://learn.microsoft.com/windows-hardware/drivers/wdtf/controlling-targets).

For detailed descriptions of the interfaces that WDTF includes,
see [Action Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2)