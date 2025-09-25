# SHCOLSTATE enumeration

## Description

Describes how a property should be treated. These values are defined in Shtypes.h.

## Constants

### `SHCOLSTATE_DEFAULT:0`

The value is displayed according to default settings for the column.

### `SHCOLSTATE_TYPE_STR:0x1`

The value is displayed as a string.

### `SHCOLSTATE_TYPE_INT:0x2`

The value is displayed as an integer.

### `SHCOLSTATE_TYPE_DATE:0x3`

The value is displayed as a date/time.

### `SHCOLSTATE_TYPEMASK:0xf`

A mask for display type values SHCOLSTATE_TYPE_STR, SHCOLSTATE_TYPE_INT, and SHCOLSTATE_TYPE_DATE.

### `SHCOLSTATE_ONBYDEFAULT:0x10`

The column should be on by default in Details view.

### `SHCOLSTATE_SLOW:0x20`

Will be slow to compute. Perform on a background thread.

### `SHCOLSTATE_EXTENDED:0x40`

Provided by a handler, not the folder.

### `SHCOLSTATE_SECONDARYUI:0x80`

Not displayed in the context menu, but is listed in the **More...** dialog.

### `SHCOLSTATE_HIDDEN:0x100`

Not displayed in the UI.

### `SHCOLSTATE_PREFER_VARCMP:0x200`

**VarCmp** produces same result as [IShellFolder::CompareIDs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-compareids).

### `SHCOLSTATE_PREFER_FMTCMP:0x400`

[PSFormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatfordisplay) produces same result as [IShellFolder::CompareIDs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-compareids).

### `SHCOLSTATE_NOSORTBYFOLDERNESS:0x800`

Do not sort folders separately.

### `SHCOLSTATE_VIEWONLY:0x10000`

Only displayed in the UI.

### `SHCOLSTATE_BATCHREAD:0x20000`

Marks columns with values that should be read in a batch.

### `SHCOLSTATE_NO_GROUPBY:0x40000`

Grouping is disabled for this column.

### `SHCOLSTATE_FIXED_WIDTH:0x1000`

Can't resize the column.

### `SHCOLSTATE_NODPISCALE:0x2000`

The width is the same in all dpi.

### `SHCOLSTATE_FIXED_RATIO:0x4000`

Fixed width and height ratio.

### `SHCOLSTATE_DISPLAYMASK:0xf000`

Filters out new display flags.