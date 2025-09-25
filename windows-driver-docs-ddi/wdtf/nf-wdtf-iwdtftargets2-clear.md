# IWDTFTargets2::Clear

## Description

Removes all items from the collection.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The lifetime of [IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2) interface
instances are tied to their creator. If you clear all items from a collection, the items are
not destroyed.

## See also

[IWDTFTargets2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftargets2)