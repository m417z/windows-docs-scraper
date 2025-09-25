# ADS_SEARCHPREF_INFO structure

## Description

The **ADS_SEARCHPREF_INFO** structure specifies the query preferences.

## Members

### `dwSearchPref`

Contains one of the [ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum) enumeration values that specifies the search option to set.

### `vValue`

Contains a [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure that specifies the data type and value of the search preference.

### `dwStatus`

Receives one of the [ADS_STATUSENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_statusenum) enumeration values that indicates the status of the search preference. The [IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) method will fill in this member when it is called.

## Remarks

To setup a search preference, assign appropriate values to the fields of an **ADS_SEARCHPREF_INFO** structure passed to the server. The **vValue** member of the **ADS_SEARCHPREF_INFO** structure is an [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure. The following table lists the [ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum) values, the corresponding values for the **dwType** member of the **ADSVALUE** structure, and the **ADSVALUE** member that is used for the specified type.

| [ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum) Value | **dwType** member of [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) | [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) member |
| --- | --- | --- |
| **ADS_SEARCHPREF_ASYNCHRONOUS** | **ADSTYPE_BOOLEAN** | **Boolean** |
| **ADS_SEARCHPREF_DEREF_ALIASES** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_SIZE_LIMIT** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_TIME_LIMIT** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_ATTRIBTYPES_ONLY** | **ADSTYPE_BOOLEAN** | **Boolean** |
| **ADS_SEARCHPREF_SEARCH_SCOPE** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_TIMEOUT** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_PAGESIZE** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_PAGED_TIME_LIMIT** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_CHASE_REFERRALS** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_SORT_ON** | **ADSTYPE_PROV_SPECIFIC** | **ProviderSpecific** |
| **ADS_SEARCHPREF_CACHE_RESULTS** | **ADSTYPE_BOOLEAN** | **Boolean** |
| **ADS_SEARCHPREF_DIRSYNC** | **ADSTYPE_PROV_SPECIFIC** | **ProviderSpecific** |
| **ADS_SEARCHPREF_TOMBSTONE** | **ADSTYPE_BOOLEAN** | **Boolean** |
| **ADS_SEARCHPREF_VLV** | **ADSTYPE_PROV_SPECIFIC** | **ProviderSpecific** |
| **ADS_SEARCHPREF_ATTRIBUTE_QUERY** | **ADSTYPE_CASE_IGNORE_STRING** | **CaseIgnoreString** |
| **ADS_SEARCHPREF_SECURITY_MASK** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_DIRSYNC_FLAG** | **ADSTYPE_INTEGER** | **Integer** |
| **ADS_SEARCHPREF_EXTENDED_DN** | **ADSTYPE_INTEGER** | **Integer** |

For more information and examples of how to use the **ADS_SEARCHPREF_INFO** structure, see the discussions of the [IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) method and the [ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum) enumeration.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue)

[ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum)

[ADS_STATUSENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_statusenum)

[IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference)