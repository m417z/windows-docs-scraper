# IWDTFActions2::Remove

## Description

Remove an action from the collection.

## Parameters

### `pAction` [in]

The action to remove from this collection.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The lifetime of [IWDTFAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtfaction2) interface
instances are tied to their creator. If you remove an item from a collection, the item is
not destroyed.