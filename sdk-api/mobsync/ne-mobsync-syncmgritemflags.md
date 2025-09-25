# SYNCMGRITEMFLAGS enumeration

## Description

Specifies information for the current item in the [SYNCMGRITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgritem) structure.

## Constants

### `SYNCMGRITEM_HASPROPERTIES:0x1`

The item has a properties dialog.

### `SYNCMGRITEM_TEMPORARY:0x2`

The item is temporary and any stored preferences can be removed. This value is defined but not used in Windows Vista.

### `SYNCMGRITEM_ROAMINGUSER:0x4`

The item roams with the user and is not specific to a machine. This value is defined but is ignored by both Windows XP and Windows Vista.

### `SYNCMGRITEM_LASTUPDATETIME:0x8`

The LastUpdateTime field is valid.

### `SYNCMGRITEM_MAYDELETEITEM:0x10`

The item may be deleted. This value has been deprecated for Windows Vista and later. This value is defined but is ignored by both Windows XP and Windows Vista.

### `SYNCMGRITEM_HIDDEN:0x20`

**Windows Vista and later**. Not supported.

## See also

[SYNCMGRITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgritem)