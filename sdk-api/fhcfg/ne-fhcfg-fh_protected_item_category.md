# FH_PROTECTED_ITEM_CATEGORY enumeration

## Description

Specifies the type of an inclusion or exclusion list.

## Constants

### `FH_FOLDER:0`

The inclusion or exclusion list is a list of folders.

### `FH_LIBRARY`

The inclusion or exclusion list is a list of libraries.

### `MAX_PROTECTED_ITEM_CATEGORY`

The maximum enumeration value for this enumeration. This value and all values greater than it are reserved for system use.

## Remarks

To retrieve the inclusion and exclusion rules that are currently stored in an [FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr) object, call the [IFhConfigMgr::GetIncludeExcludeRules](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getincludeexcluderules) method.

To add or remove an exclusion rule, call the [IFhConfigMgr::AddRemoveExcludeRule](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-addremoveexcluderule) method.

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr::AddRemoveExcludeRule](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-addremoveexcluderule)

[IFhConfigMgr::GetIncludeExcludeRules](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getincludeexcluderules)