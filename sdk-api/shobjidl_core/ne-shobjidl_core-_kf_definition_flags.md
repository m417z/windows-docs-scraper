# _KF_DEFINITION_FLAGS enumeration

## Description

Flags that specify certain known folder behaviors. Used with the [KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition) structure.

## Constants

### `KFDF_LOCAL_REDIRECT_ONLY:0x2`

Prevent a [per-user](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category) known folder from being redirected to a network location. Note that if the known folder has been flagged with KFDF_LOCAL_REDIRECT_ONLY but it is a subfolder of a known folder that is redirected to a network location, this subfolder is redirected also.

### `KFDF_ROAMABLE:0x4`

Can be roamed through a PC-to-PC synchronization.

### `KFDF_PRECREATE:0x8`

Create the folder when the user first logs on. Normally a known folder is not created until it is first called. At that time, an API such as [SHCreateItemInKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateiteminknownfolder) or [IKnownFolder::GetShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getshellitem) is called with the [KF_FLAG_CREATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-known_folder_flag) flag. However, some known folders need to exist immediately. An example is those known folders under %USERPROFILE%, which must exist to provide a proper view. In those cases, KFDF_PRECREATE is set and Windows Explorer calls the creation API during its user initialization.

### `KFDF_STREAM:0x10`

**Introduced in Windows 7**. The known folder is a file rather than a folder.

### `KFDF_PUBLISHEXPANDEDPATH:0x20`

**Introduced in Windows 7**. The full path of the known folder, with any environment variables fully expanded, is stored in the registry under HKEY_CURRENT_USER.

### `KFDF_NO_REDIRECT_UI:0x40`

**Introduced in Windows 8.1**. Prevent showing the **Locations** tab in the property dialog of the known folder.

## Remarks

The **KF_DEFINITION_FLAGS** type is defined in Shobjidl.h as shown here.

```
typedef DWORD KF_DEFINITION_FLAGS;
```

## See also

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))