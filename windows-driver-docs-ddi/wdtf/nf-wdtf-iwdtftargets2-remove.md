# IWDTFTargets2::Remove

## Description

Removes an item from the collection.

## Parameters

### `pTarget` [in]

The item to remove from this collection.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The lifetime of [IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2) interface
instances are tied to their creator. If you remove an item from a collection, the item is
not destroyed.

## See also

[IWDTFTargets2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftargets2)