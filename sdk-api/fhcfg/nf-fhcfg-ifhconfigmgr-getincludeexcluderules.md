# IFhConfigMgr::GetIncludeExcludeRules

## Description

Retrieves the inclusion and exclusion rules that are currently stored in an [FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr) object.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Include` [in]

If set to **TRUE**, inclusion rules are returned. If set to **FALSE**, exclusion rules are returned.

### `Category` [in]

An [FH_PROTECTED_ITEM_CATEGORY](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_protected_item_category) enumeration value that specifies the type of the inclusion or exclusion rules.

### `Iterator` [out]

Receives an [IFhScopeIterator](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhscopeiterator) interface pointer that can be used to enumerate the rules in the requested category.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

The File History protection scope is the set of files that are backed up by this feature. It contains inclusion rules and exclusion rules. Inclusion rules specify the files and folders that are included. Exclusion rules specify the files and folders that are excluded.

The default protection scope includes all folders from all user libraries and the Contacts, Desktop, and Favorites folders.

You can modify the File History protection scope by adding exclusion rules to reduce the File History protection scope without removing folders from user libraries.

Exclusion rules take precedence over inclusion rules. In other words, if an inclusion rule conflicts with an exclusion rule, the File History feature follows the exclusion rule.

The [IFhConfigMgr::AddRemoveExcludeRule](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-addremoveexcluderule) method can be used to add or remove exclusion rules. It cannot be used to modify the inclusion rules.

## See also

[FH_PROTECTED_ITEM_CATEGORY](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_protected_item_category)

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::AddRemoveExcludeRule](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-addremoveexcluderule)

[IFhScopeIterator](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhscopeiterator)