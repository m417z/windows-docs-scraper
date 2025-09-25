## Description

Client-provided callback function, used by [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) and [MergeFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-mergefontpackage) to reallocate memory when the size of an allocated buffer needs to change.

## Parameters

### `unnamedParam1`

Pointer to previously allocated memory block.

### `unnamedParam2`

New size in bytes.

## Return value

Returns a void pointer to the reallocated (and possibly moved) memory block. The return value should be **NULL** if the size is zero and the *memblock* argument is not **NULL**, or if there is not enough available memory to expand the block to the given size. In the first case, the original block should be freed. In the second, the original block should be unchanged.

## Remarks

[realloc](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/xbebcx7d(v=vs.100)) conforms to this type; the application can either use **realloc** or a more specialized function for memory reallocation. Whatever function is chosen, there must also be appropriate functions for initial allocation and to free this memory.

## See also

[CFP_ALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_allocproc)

[CFP_FREEPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_freeproc)

[CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage)

[MergeFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-mergefontpackage)