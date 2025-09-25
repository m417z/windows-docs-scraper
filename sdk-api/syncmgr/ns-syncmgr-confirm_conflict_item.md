# CONFIRM_CONFLICT_ITEM structure

## Description

Defines conflict item structure.

## Members

### `pShellItem`

Type: **[IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2)***

A pointer to [IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2) interface.

### `pszOriginalName`

Type: **LPWSTR**

A pointer to the original name. If set to **NULL** then IShellItem's display name will be used.

### `pszAlternateName`

Type: **LPWSTR**

A pointer to the alternate name. If multiple items are kept, then item must be renamed to this name. User may or may not have an ability to change the name.

### `pszLocationShort`

Type: **LPWSTR**

A pointer to the short location.

### `pszLocationFull`

Type: **LPWSTR**

A pointer to the full location.

### `nType`

Type: **[SYNCMGR_CONFLICT_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_conflict_item_type)**

The conflict item type. See [SYNCMGR_CONFLICT_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_conflict_item_type).