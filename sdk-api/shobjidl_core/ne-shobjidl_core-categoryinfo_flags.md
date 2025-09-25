# CATEGORYINFO_FLAGS enumeration

## Description

Provides a set of flags for use with the [CATEGORY_INFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-category_info) structure.

## Constants

### `CATINFO_NORMAL:0`

0x00000000. Applies default properties for the category.

### `CATINFO_COLLAPSED:0x1`

0x00000001. The category should appear as collapsed

### `CATINFO_HIDDEN:0x2`

0x00000002. The category should appear as hidden.

### `CATINFO_EXPANDED:0x4`

0x00000004. The category should appear as expanded.

### `CATINFO_NOHEADER:0x8`

0x00000008. The category has no header.

### `CATINFO_NOTCOLLAPSIBLE:0x10`

0x00000010. The category cannot be collapsed.

### `CATINFO_NOHEADERCOUNT:0x20`

0x00000020. The count of items in the category should not be displayed in the header.

### `CATINFO_SUBSETTED:0x40`

0x00000040. **Windows 7 and later**. The category should appear subsetted.

### `CATINFO_SEPARATE_IMAGES:0x80`

### `CATINFO_SHOWEMPTY:0x100`