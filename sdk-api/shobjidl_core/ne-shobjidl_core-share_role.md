# SHARE_ROLE enumeration

## Description

Specifies the access permissions assigned to the **Users** or **Public** folder. Used in [CreateShare](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-isharingconfigurationmanager-createshare) and [GetSharePermissions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-isharingconfigurationmanager-getsharepermissions).

## Constants

### `SHARE_ROLE_INVALID:-1`

The folder is not shared.

### `SHARE_ROLE_READER:0`

The contents of the folder can be read, but not altered or added to.

### `SHARE_ROLE_CONTRIBUTOR:1`

The contents of the folder can be read and altered. New items can be added, however items can be deleted only by the user that contributed them.

### `SHARE_ROLE_CO_OWNER:2`

The contents of the folder can be read, changed, or added to.

### `SHARE_ROLE_OWNER:3`

Not normally used in the context of this interface.

### `SHARE_ROLE_CUSTOM:4`

The folder is shared, but the share role is neither SHARE_ROLE_READER, SHARE_ROLE_CONTRIBUTOR, or SHARE_ROLE_CO_OWNER.

### `SHARE_ROLE_MIXED:5`

Not used in the context of this interface.

## Remarks

[ISharingConfigurationManager::CreateShare](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-isharingconfigurationmanager-createshare) accepts only **SHARE_ROLE_READER** and **SHARE_ROLE_CO_OWNER**. All other values are seen only in the results of [ISharingConfigurationManager::GetSharePermissions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-isharingconfigurationmanager-getsharepermissions).