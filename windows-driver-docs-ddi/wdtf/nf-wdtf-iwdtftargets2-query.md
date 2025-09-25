# IWDTFTargets2::Query

## Description

Returns a subset of the items in the collection.

## Parameters

### `SDEL` [in]

The SDEL query string.

### `ppTargets` [out, retval]

The collection of items.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **Query** method provides the *SDEL*
parameter in a call to the [IWDTFTarget2::Eval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-eval)
method for every instance of the [IWDTFTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftarget2) interface
in the [IWDTFTargets2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftargets2) collection.
Use the [Simple Data
Evaluation Language](https://learn.microsoft.com/windows-hardware/drivers/wdtf/simple-data-evaluation-language-overview) to specify this parameter.
Every target that returns **VARIANT_TRUE** is added to a new
instance of the **IWDTFTargets2** collection
interface.

## See also

[IWDTFTargets2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iwdtftargets2)