# KNOWNFOLDER_DEFINITION structure

## Description

Defines the specifics of a known folder.

## Members

### `category`

Type: **[KF_CATEGORY](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category)**

A single value from the [KF_CATEGORY](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-kf_category) constants that classifies the folder as virtual, fixed, common, or per-user.

### `pszName`

Type: **LPWSTR**

A pointer to the non-localized, canonical name for the known folder, stored as a null-terminated Unicode string. If this folder is a common or per-user folder, this value is also used as the value name of the "User Shell Folders" registry settings. This name is meant to be a unique, human-readable name. Third parties are recommended to follow the format `Company.Application.Name`. The name given here should not be confused with the display name.

### `pszDescription`

Type: **LPWSTR**

A pointer to a short description of the known folder, stored as a null-terminated Unicode string. This description should include the folder's purpose and usage.

### `fidParent`

Type: **[KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)**

A [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) value that names another known folder to serve as the parent folder. Applies to common and per-user folders only. This value is used in conjunction with **pszRelativePath**. See **Remarks** for more details.

This value is optional if no value is provided for **pszRelativePath**.

### `pszRelativePath`

Type: **LPWSTR**

Optional. A pointer to a path relative to the parent folder specified in **fidParent**. This is a null-terminated Unicode string, refers to the physical file system path, and is not localized. Applies to common and per-user folders only. See **Remarks** for more details.

### `pszParsingName`

Type: **LPWSTR**

A pointer to the Shell namespace folder path of the folder, stored as a null-terminated Unicode string. Applies to virtual folders only. For example, `Control Panel` has a parsing name of `::%CLSID_MyComputer%\::%CLSID_ControlPanel%`.

### `pszTooltip`

Type: **LPWSTR**

Optional. A pointer to the default tooltip resource used for this known folder when it is created. This is a null-terminated Unicode string in this form:

**Module name, Resource ID**

For example, `@%_SYS_MOD_PATH%,-12688` is the tooltip for Common Pictures. When the folder is created, this string is stored in that folder's copy of Desktop.ini. It can be changed later by other Shell APIs. This resource might be localized.

This information is not required for virtual folders.

### `pszLocalizedName`

Type: **LPWSTR**

Optional. A pointer to the default localized name resource used when the folder is created. This is a null-terminated Unicode string in this form:

**Module name, Resource ID**

When the folder is created, this string is stored in that folder's copy of Desktop.ini. It can be changed later by other Shell APIs.

This information is not required for virtual folders.

### `pszIcon`

Type: **LPWSTR**

Optional. A pointer to the default icon resource used when the folder is created. This is a null-terminated Unicode string in this form:

**Module name, Resource ID**

When the folder is created, this string is stored in that folder's copy of Desktop.ini. It can be changed later by other Shell APIs.

This information is not required for virtual folders.

### `pszSecurity`

Type: **LPWSTR**

Optional. A pointer to a [Security Descriptor Definition Language](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-definition-language) format string. This is a null-terminated Unicode string that describes the default security descriptor that the folder receives when it is created. If this parameter is **NULL**, the new folder inherits the security descriptor of its parent. This is particularly useful for common folders that are accessed by all users.

### `dwAttributes`

Type: **DWORD**

Optional. Default file system attributes given to the folder when it is created. For example, the file could be hidden and read-only (FILE_ATTRIBUTE_HIDDEN and FILE_ATTRIBUTE_READONLY). For a complete list of possible values, see the *dwFlagsAndAttributes* parameter of the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. Set to -1 if not needed.

### `kfdFlags`

Type: **[KF_DEFINITION_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_kf_definition_flags)**

Optional. One of more values from the [KF_DEFINITION_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_kf_definition_flags) enumeration that allow you to restrict redirection, allow PC-to-PC roaming, and control the time at which the known folder is created. Set to 0 if not needed.

### `ftidType`

Type: **[FOLDERTYPEID](https://learn.microsoft.com/windows/desktop/shell/foldertypeid)**

One of the [FOLDERTYPEID](https://learn.microsoft.com/windows/desktop/shell/foldertypeid) values that identifies the known folder type based on its contents (such as documents, music, or photographs). This value is a GUID.

## Remarks

The **fidParent** and **pszRelativePath** values work together. For example, suppose you are defining a folder called MyNewFolder and want to create that folder as ...\<Username>\AppData\Local\MyApp\MyNewFolder. Provide [FOLDERID_LocalAppData](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) in **fidParent** to represent ...\<Username>\AppData\Local. Provide "\MyApp\MyNewFolder" in **pszRelativePath**.

## See also

[IKnownFolder::GetFolderDefinition](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getfolderdefinition)

[IKnownFolderManager::RegisterFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-registerfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))