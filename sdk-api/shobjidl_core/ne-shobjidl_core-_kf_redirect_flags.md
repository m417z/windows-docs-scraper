# _KF_REDIRECT_FLAGS enumeration

## Description

Flags used by [IKnownFolderManager::Redirect](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-redirect) to specify details of a known folder redirection such as permissions and ownership for the redirected folder.

## Constants

### `KF_REDIRECT_USER_EXCLUSIVE:0x1`

Ensure that only the user has permission to access the redirected folder.

### `KF_REDIRECT_COPY_SOURCE_DACL:0x2`

Copy the DACL of the source folder to the target to maintain current access permissions.

### `KF_REDIRECT_OWNER_USER:0x4`

Sets the user as the owner of a newly created target folder unless the user is a member of the Administrator group, in which case Administrator is set as the owner. Must be called with KF_REDIRECT_SET_OWNER_EXPLICIT.

### `KF_REDIRECT_SET_OWNER_EXPLICIT:0x8`

Set the owner of a newly created target folder. If the user belongs to the Administrators group, Administrators is assigned as the owner. Must be called with KF_REDIRECT_OWNER_USER.

### `KF_REDIRECT_CHECK_ONLY:0x10`

Do not perform a redirection, simply check whether redirection has occurred. If so, [IKnownFolderManager::Redirect](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-redirect) returns S_OK; if not, or if some actions remain to be completed, it returns S_FALSE.

### `KF_REDIRECT_WITH_UI:0x20`

Display UI during the redirection.

### `KF_REDIRECT_UNPIN:0x40`

Unpin the source folder.

### `KF_REDIRECT_PIN:0x80`

Pin the target folder.

### `KF_REDIRECT_COPY_CONTENTS:0x200`

Copy the existing contents—both files and subfolders—of the known folder to the redirected folder.

### `KF_REDIRECT_DEL_SOURCE_CONTENTS:0x400`

Delete the contents of the source folder after they have been copied to the redirected folder. This flag is valid only if [KF_REDIRECT_COPY_CONTENTS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_kf_redirect_flags) is set.

### `KF_REDIRECT_EXCLUDE_ALL_KNOWN_SUBFOLDERS:0x800`

Reserved. Do not use.

## Remarks

The ****KF_REDIRECT_OWNER_USER**** and ****KF_REDIRECT_SET_OWNER_EXPLICIT**** flags provide ownership checks for the target folder, if that folder exists. By default, [IKnownFolderManager::Redirect](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-redirect) does not perform ownership checks. KF_REDIRECT_OWNER_USER and KF_REDIRECT_SET_OWNER_EXPLICIT are only valid if called together.

The **KF_REDIRECT_FLAGS** type is defined in Shobjidl.h as shown here.

```
typedef DWORD KF_REDIRECT_FLAGS;
```

## See also

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))