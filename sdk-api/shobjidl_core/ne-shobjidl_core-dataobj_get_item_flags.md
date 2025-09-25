# DATAOBJ_GET_ITEM_FLAGS enumeration

## Description

Values used by the [SHGetItemFromDataObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shgetitemfromdataobject) function to specify options concerning the processing of the source object.

## Constants

### `DOGIF_DEFAULT:0`

0x0000. No special options.

### `DOGIF_TRAVERSE_LINK:0x1`

0x0001. If the source object is a link, base the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) on the link's target rather than the link file itself.

### `DOGIF_NO_HDROP:0x2`

0x0002. If the source data object does not contain data in the CFSTR_SHELLIDLIST format, which identifies the object through an IDList, do not revert to the [CF_HDROP](https://learn.microsoft.com/windows/desktop/shell/clipboard) format, which uses a file path, as an alternative in the transfer.

### `DOGIF_NO_URL:0x4`

0x0004. If the source data object does not contain data in the CFSTR_SHELLIDLIST format, which identifies the object through an IDList, do not revert to the [CFSTR_INETURL](https://learn.microsoft.com/windows/desktop/shell/clipboard) clipboard format, which uses a URL, as an alternative in the transfer.

### `DOGIF_ONLY_IF_ONE:0x8`

0x0008. If the source object is an array of items, use it only if the array contains just one item.