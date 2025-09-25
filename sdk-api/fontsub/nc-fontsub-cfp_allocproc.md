## Description

Client-provided callback function, used by [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) and [MergeFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-mergefontpackage) to allocate memory.

## Parameters

### `unnamedParam1`

Number of bytes to allocate.

## Return value

Returns a void pointer to the allocated space, or **NULL** if there is insufficient memory available.

## Remarks

[malloc](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/6ewkz86d(v=vs.100)) conforms to this type; the application can either use **malloc** or a more specialized function for memory allocation. Whatever function is chosen, there must also be appropriate functions to reallocate and to free this memory.

## See also

[CFP_FREEPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_freeproc)

[CFP_REALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_reallocproc)

[CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage)

[MergeFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-mergefontpackage)