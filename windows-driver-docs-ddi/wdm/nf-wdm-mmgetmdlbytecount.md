## Description

The **MmGetMdlByteCount** macro returns the length, in bytes, of the buffer described by the specified MDL.

## Parameters

### `Mdl`

A pointer to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the layout of a virtual memory buffer in physical memory. For more information, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## Return value

**MmGetMdlByteCount** returns the length, in bytes, of the buffer described by Mdl.

## Remarks

Macro definition:

```cpp
#define MmGetMdlByteCount(Mdl)  ((Mdl)->ByteCount)
```

Callers of **MmGetMdlByteCount** can be running at any IRQL. Usually, callers are running at IRQL <= DISPATCH_LEVEL.

## See also

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[MmGetMdlByteOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlbyteoffset)

## Syntax

```cpp
ULONG MmGetMdlByteCount(
  [in] PMDL Mdl
);
```