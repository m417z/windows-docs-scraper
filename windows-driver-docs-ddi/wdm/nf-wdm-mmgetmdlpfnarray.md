## Description

The **MmGetMdlPfnArray** macro returns a pointer to the beginning of the array of physical page numbers that are associated with a memory descriptor list (MDL).

## Parameters

### `Mdl`

A pointer to an MDL.

## Return value

**MmGetMdlPfnArray** returns a pointer to the beginning of the array of physical page numbers that are associated with the MDL.

## Remarks

**MmGetMdlPfnArray** returns a pointer to the beginning of the array of physical page numbers that are associated with the MDL.

Macro definition:

```cpp
#define MmGetMdlPfnArray(Mdl) ((PPFN_NUMBER)(Mdl + 1))
```

The number of entries in the array is **ADDRESS_AND_SIZE_TO_SPAN_PAGES**(**MmGetMdlVirtualAddress**(*Mdl*), **MmGetMdlByteCount**(*Mdl*)).

Each array element is an integer value of type PFN_NUMBER, which is defined in the Wdm.h header file as follows:

```cpp
typedef ULONG PFN_NUMBER, *PPFN_NUMBER;
```

Changing the contents of the array can cause subtle system problems that are difficult to diagnose. We recommend that you do not read or change the contents of this array.

For pageable memory, the contents of the array are valid only for a buffer locked with [**MmProbeAndLockPages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages).

For nonpaged pool, the contents of the array are valid only for an MDL updated with [**MmBuildMdlForNonPagedPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool), [**MmAllocatePagesForMdlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdlex), or [**MmAllocatePagesForMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatepagesformdl).

For more information about MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## Syntax

```cpp
PPFN_NUMBER MmGetMdlPfnArray(
  _In_ PMDL Mdl
);
```