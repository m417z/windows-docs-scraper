# _POINTER_SEARCH_PHYSICAL structure

## Description

The IG_POINTER_SEARCH_PHYSICAL [Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation searches the target's physical memory for pointers lying within a specified range. When calling **Ioctl** with *IoctlType* set to IG_POINTER_SEARCH_PHYSICAL, *IpvData* should contain an instance of the POINTER_SEARCH_PHYSICAL structure.

## Members

### `Offset`

Specifies the address in the target's physical memory to start searching from.

### `Length`

Specifies the amount of the target's physical memory to search.

### `PointerMin`

Specifies the lower limit of the range of pointers to search for.

### `PointerMax`

Specifies the upper limit of the range of pointers to search for.

### `Flags`

Specifies bit flags that alter the behavior of this **Ioctl** operation. The following flags can be included.

| Flag | Behavior when set |
| --- | --- |
| PTR_SEARCH_PHYS_ALL_HITS | Return all pointers in the specified range. If this flag is not set, only one pointer per page is returned. |
| PTR_SEARCH_PHYS_PTE | The memory is searched for a page table entry (PTE) that matches the Page Frame Number specified in **PointerMin**. |
| PTR_SEARCH_PHYS_RANGE_CHECK_ONLY |  |
| PTR_SEARCH_NO_SYMBOL_CHECK | Do not check that the symbols used for the kernel are correct. |

### `MatchOffsets`

Receives the addresses of all the pointers that match the search criteria. **MatchOffsets** is an array that contains **MatchOffsetsSize** elements.

### `MatchOffsetsSize`

Specifies the number of entries in the array **MatchOffsets**.

### `MatchOffsetsCount`

Receives the number of pointers found that match the search criteria.

## Remarks

The parameters for the IG_POINTER_SEARCH_PHYSICAL [Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation are the members of the POINTER_SEARCH_PHYSICAL structure.

## See also

[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine)