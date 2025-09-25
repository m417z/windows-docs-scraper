# IFhConfigMgr::AddRemoveExcludeRule

## Description

Adds an exclusion rule to the exclusion list or removes a rule from the list.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Add` [in]

If this parameter is **TRUE**, a new exclusion rule is added.
If it is set to **FALSE**, an existing exclusion rule is removed.

### `Category` [in]

Specifies the type of the exclusion rule. See the [FH_PROTECTED_ITEM_CATEGORY](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_protected_item_category) enumeration for possible values.

### `Item` [in]

The folder path or library name or GUID of the item that the exclusion rule applies to.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

The File History protection scope is the set of files that are backed up by the File History feature. It contains inclusion rules and exclusion rules. Inclusion rules specify the files and folders that are included. Exclusion rules specify the files and folders that are excluded.

The default protection scope includes all folders from all user libraries and the Contacts, Desktop, and Favorites folders.

Exclusion rules take precedence over inclusion rules. In other words, if an inclusion rule conflicts with an exclusion rule, the File History feature follows the exclusion rule.

To reduce the protection scope, use the **IFhConfigMgr::AddRemoveExcludeRule** to add exclusion rules.

This method can be used to add or remove exclusion rules. It cannot be used to modify inclusion rules.

User libraries can be enumerated by calling the [SHGetKnownFolderItem](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderitem) function and the methods of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) and [IEnumShellItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumshellitems) interfaces.

Standard folders and libraries are specified by a GUID, prefixed with an asterisk. For example, *a990ae9f-a03b-4e80-94bc-9912d7504104 specifies the Pictures library. For a list of standard folders and libraries and their GUIDs, see the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) documentation.

Custom libraries are specified by name. Folders are specified by their full path (for example, C:\Users\Public\Videos).

## See also

[FH_PROTECTED_ITEM_CATEGORY](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_protected_item_category)

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::GetIncludeExcludeRules](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getincludeexcluderules)