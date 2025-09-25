## Description

The **MmPrepareMdlForReuse** macro releases the resources that are associated with a partial MDL so that the MDL can be reused.

## Parameters

### `MDL` [in]

A pointer to a partial MDL that is to be prepared for reuse.

## Remarks

This macro is used by drivers that repeatedly use the same allocated MDL for the _TargetMdl_ parameter in calls to the [**IoBuildPartialMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl) routine. If, in a call to **MmPrepareMdlForReuse**, the specified partial MDL has an associated mapping to system address space, **MmPrepareMdlForReuse** releases the mapping so that the MDL can be reused.

**MmPrepareMdlForReuse** accepts only partial MDLs that are built by **IoBuildPartialMdl**. If **MmPrepareMdlForReuse** receives an MDL that is mapped to the system address space but was not built by **IoBuildPartialMdl**, **MmPrepareMdlForReuse** does not release the mapping.

For more information about partial MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).