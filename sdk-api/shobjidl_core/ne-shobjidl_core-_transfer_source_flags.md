# _TRANSFER_SOURCE_FLAGS enumeration

## Description

Used by methods of the [ITransferSource](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransfersource) and [ITransferDestination](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransferdestination) interfaces to control their file operations.

## Constants

### `TSF_NORMAL:0`

Fail if the destination already exists, unless TSF_OVERWRITE_EXIST is specified. This is a default behavior.

### `TSF_FAIL_EXIST:0`

Fail if the destination already exists, unless TSF_OVERWRITE_EXIST is specified. This is a default behavior.

### `TSF_RENAME_EXIST:0x1`

Rename with auto-name generation if the destination already exists.

### `TSF_OVERWRITE_EXIST:0x2`

Overwrite or merge with the destination.

### `TSF_ALLOW_DECRYPTION:0x4`

Allow creation of a decrypted destination.

### `TSF_NO_SECURITY:0x8`

No discretionary access control list (DACL), system access control list (SACL), or owner.

### `TSF_COPY_CREATION_TIME:0x10`

Copy the creation time as part of the copy. This can be useful for a move operation that is being used as a copy and delete operation (TSF_MOVE_AS_COPY_DELETE).

### `TSF_COPY_WRITE_TIME:0x20`

Copy the last write time as part of the copy.

### `TSF_USE_FULL_ACCESS:0x40`

Assign write, read, and delete permissions as share mode.

### `TSF_DELETE_RECYCLE_IF_POSSIBLE:0x80`

Recycle on file delete, if possible.

### `TSF_COPY_HARD_LINK:0x100`

Hard link to the desired source (not required). This avoids a normal copy operation.

### `TSF_COPY_LOCALIZED_NAME:0x200`

Copy the localized name.

### `TSF_MOVE_AS_COPY_DELETE:0x400`

Move as a copy and delete operation.

### `TSF_SUSPEND_SHELLEVENTS:0x800`

Suspend Shell events.

## See also

[ITransferDestination::CreateItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransferdestination-createitem)

[ITransferSource::LinkItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-linkitem)

[ITransferSource::MoveItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-moveitem)

[ITransferSource::OpenItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-openitem)

[ITransferSource::RecycleItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-recycleitem)

[ITransferSource::RemoveItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-removeitem)

[ITransferSource::RenameItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-renameitem)