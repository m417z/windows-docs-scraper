# IAction::SetTarget

## Description

The **SetTarget** method is used internally by WDTF. Do not call this method directly.

## Parameters

### `pMainTarget` [in]

The main target for the implementation to use. This target is the one
that [IWDTFTarget2::GetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-getinterface) was called on.

### `MoreTargets` [in]

Optional additional targets for the implementation. Currently, the *MoreTargets* parameter will always be VT_EMPTY. You should fail the **SetTarget** call if this parameter is anything other than VT_EMPTY.

## Return value

**SetTarget** returns a standard **HRESULT** value

## Remarks

The **SetTarget** method is used when you are creating WDTF actions. Do not call this method from a WDTF scenario.

## See also

[Action interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[IAction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iaction)

[IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2)

[IWDTFTarget2::GetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-getinterface)

[IWDTFTargets2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftargets2)