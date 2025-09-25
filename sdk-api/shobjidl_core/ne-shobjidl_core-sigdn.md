# SIGDN enumeration

## Description

Requests the form of an item's display name to retrieve through [IShellItem::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-getdisplayname) and [SHGetNameFromIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shgetnamefromidlist).

## Constants

### `SIGDN_NORMALDISPLAY:0`

0x00000000. Returns the display name relative to the parent folder. In UI this name is generally ideal for display to the user.

### `SIGDN_PARENTRELATIVEPARSING`

(int)0x80018001. Returns the parsing name relative to the parent folder. This name is not suitable for use in UI.

### `SIGDN_DESKTOPABSOLUTEPARSING`

(int)0x80028000. Returns the parsing name relative to the desktop. This name is not suitable for use in UI.

### `SIGDN_PARENTRELATIVEEDITING`

(int)0x80031001. Returns the editing name relative to the parent folder. In UI this name is suitable for display to the user.

### `SIGDN_DESKTOPABSOLUTEEDITING`

(int)0x8004c000. Returns the editing name relative to the desktop. In UI this name is suitable for display to the user.

### `SIGDN_FILESYSPATH`

(int)0x80058000. Returns the item's file system path, if it has one. Only items that report [SFGAO_FILESYSTEM](https://learn.microsoft.com/windows/desktop/shell/sfgao) have a file system path. When an item does not have a file system path, a call to [IShellItem::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-getdisplayname) on that item will fail. In UI this name is suitable for display to the user in some cases, but note that it might not be specified for all items.

### `SIGDN_URL`

(int)0x80068000. Returns the item's URL, if it has one. Some items do not have a URL, and in those cases a call to [IShellItem::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-getdisplayname) will fail. This name is suitable for display to the user in some cases, but note that it might not be specified for all items.

### `SIGDN_PARENTRELATIVEFORADDRESSBAR`

(int)0x8007c001. Returns the path relative to the parent folder in a friendly format as displayed in an address bar. This name is suitable for display to the user.

### `SIGDN_PARENTRELATIVE`

(int)0x80080001. Returns the path relative to the parent folder.

### `SIGDN_PARENTRELATIVEFORUI`

(int)0x80094001. **Introduced in Windows 8**.

## Remarks

Different forms of an item's name can be retrieved through the item's properties, including those listed here. Note that not all properties are present on all items, so only those appropriate to the item will appear.

* [PKEY_FileName](https://learn.microsoft.com/windows/desktop/properties/props-system-filename)
* [PKEY_ItemFolderNameDisplay](https://learn.microsoft.com/windows/desktop/properties/props-system-itemfoldernamedisplay)
* [PKEY_ItemFolderPathDisplay](https://learn.microsoft.com/windows/desktop/properties/props-system-itemfolderpathdisplay)
* [PKEY_ItemFolderPathDisplayNarrow](https://learn.microsoft.com/windows/desktop/properties/props-system-itemfolderpathdisplaynarrow)