# _SICHINTF enumeration

## Description

Used to determine how to compare two Shell items. [IShellItem::Compare](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-compare) uses this enumerated type.

## Constants

### `SICHINT_DISPLAY:0`

0x00000000. This relates to the *iOrder* parameter of the [IShellItem::Compare](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-compare) interface and indicates that the comparison is based on the display in a folder view.

### `SICHINT_ALLFIELDS`

(int)0x80000000. Exact comparison of two instances of a Shell item.

### `SICHINT_CANONICAL:0x10000000`

0x10000000. This relates to the *iOrder* parameter of the [IShellItem::Compare](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-compare) interface and indicates that the comparison is based on a canonical name.

### `SICHINT_TEST_FILESYSPATH_IF_NOT_EQUAL:0x20000000`

0x20000000. **Windows 7 and later**. If the Shell items are not the same, test the file system paths.