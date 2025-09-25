## Description

Client-provided callback function, used by [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) and [MergeFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-mergefontpackage) to free memory.

## Parameters

### `unnamedParam1`

Previously allocated memory block to be freed.

## Return value

Deallocates a memory block (*memblock*) that was previously allocated by a call to a [CFP_ALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_allocproc) or [CFP_REALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_reallocproc) callback function. If memblock is **NULL**, the pointer should be ignored and the function should return immediately. The function is not required to correctly handle being passed an invalid pointer (a pointer to a memory block that was not allocated by the appropriate [CFP_ALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_allocproc) or [CFP_REALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_reallocproc) callback function).

## Remarks

[free](https://learn.microsoft.com/windows/desktop/DirectShow/cbaseallocator-free) conforms to this type; the application can either use **free** or a more specialized function. Whatever function is chosen, there must also be appropriate functions to allocate and to reallocate this memory.

## See also

[CFP_ALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_allocproc)

[CFP_REALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_reallocproc)

[CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage)

[MergeFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-mergefontpackage)