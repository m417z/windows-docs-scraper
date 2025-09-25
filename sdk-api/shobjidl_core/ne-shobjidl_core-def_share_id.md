# DEF_SHARE_ID enumeration

## Description

Values that specify the folder being acted on by methods of the [ISharingConfigurationManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-isharingconfigurationmanager) interface.

## Constants

### `DEFSHAREID_USERS:1`

The **Users** folder ([FOLDERID_UserProfiles](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)). This folder is usually found at C:\Users.

### `DEFSHAREID_PUBLIC:2`

The **Public** folder ([FOLDERID_Public](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)). This folder is usually found at C:\Users\Public.

## Remarks

In Windows Vista, an Server Message Block (SMB) share is created for both the **Users** and **Public** folders. As of Windows 7, the Public share is accessed through the Users share, so only **Users** is given an SMB share.

When methods are called with the **DEFSHAREID_PUBLIC** value, the restrictions specified by the [SHARE_ROLE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-share_role) value in that call apply to the *Everyone* access control entry (ACE).

When methods are called with the **DEFSHAREID_USERS** value, the restrictions specified by the [SHARE_ROLE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-share_role) value in that call apply to the *Authenticated Users* ACE.