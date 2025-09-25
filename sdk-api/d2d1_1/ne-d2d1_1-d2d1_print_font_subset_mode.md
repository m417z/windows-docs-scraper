## Description

Defines when font resources should be subset during printing.

## Constants

### `D2D1_PRINT_FONT_SUBSET_MODE_DEFAULT:0`

Uses a heuristic strategy to decide when to subset fonts.

> [!NOTE]
> If the print driver has requested archive-optimized content, then Direct2D will subset fonts once, for the entire document.

### `D2D1_PRINT_FONT_SUBSET_MODE_EACHPAGE:1`

Subsets and embeds font resources in each page, then discards that font subset after the page is printed out.

### `D2D1_PRINT_FONT_SUBSET_MODE_NONE:2`

Sends out the original font resources without subsetting along with the page that first uses the font, and re-uses the font resources for later pages without resending them.

### `D2D1_PRINT_FONT_SUBSET_MODE_FORCE_DWORD:0xffffffff`

A value that's guaranteed to be a DWORD.

## See also

[D2D1_PRINT_CONTROL_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_print_control_properties)