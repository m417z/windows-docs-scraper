## Description

The **MmGetMdlVirtualAddress** macro returns the base virtual address of a buffer described by an MDL.

## Syntax

```cpp
#define MmGetMdlVirtualAddress(Mdl) \
    ((PVOID) ((PCHAR) ((Mdl)->StartVa) + (Mdl)->ByteOffset))
```

## Parameters

### `Mdl` [in]

Pointer to an MDL that describes the buffer for which to return the initial virtual address.

## Return value

**MmGetMdlVirtualAddress** returns the base virtual address of the buffer described by the MDL.

## Remarks

**MmGetMdlVirtualAddress** returns the starting virtual address of the MDL.

**MmGetMdlVirtualAddress** returns a virtual address that is not necessarily valid in the current thread context. Lower-level drivers should not attempt to use the returned virtual address to access memory, particularly user memory space.

The returned address, used as an index to a physical address entry in the MDL, can be input to [**MapTransfer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer).

Callers of **MmGetMdlVirtualAddress** can be running at any IRQL. Usually, the caller is running at IRQL = DISPATCH_LEVEL because this routine is commonly called to obtain the _CurrentVa_ parameter to **MapTransfer**.