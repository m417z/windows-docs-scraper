# ADS_SEARCHPREF_ENUM enumeration

## Description

The **ADS_SEARCHPREF_ENUM** enumeration specifies preferences for an [IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch) object. This enumeration is used in the **dwSearchPref** member of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure in the [IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) method.

## Constants

### `ADS_SEARCHPREF_ASYNCHRONOUS:0`

Specifies that searches should be performed asynchronously. By default, searches are synchronous.

In a synchronous search, the [IDirectorySearch::GetFirstRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getfirstrow) and [IDirectorySearch::GetNextRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getnextrow) methods do not return until the server returns the entire result, or for a paged search, the entire page.

An asynchronous search blocks until one row of the search results is available, or until the timeout interval specified by the **ADS_SEARCHPREF_TIMEOUT** search preference elapses.

### `ADS_SEARCHPREF_DEREF_ALIASES`

Specifies that aliases of found objects are to be resolved. Use the [ADS_DEREFENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_derefenum) enumeration to specify how this is performed.

### `ADS_SEARCHPREF_SIZE_LIMIT`

Specifies the size limit that the server should observe during a search. The server stops searching when the size limit is reached and returns the results accumulated to that point. If this value is zero, the size limit is determined by the directory service. The default for this value is zero. If this value is greater than the size limit determined by the directory service, the directory service limit takes precedence.

For Active Directory, the size limit specifies the maximum number of objects to be returned by the search. Also for Active Directory, the maximum number of objects returned by a search is 1000 objects.

### `ADS_SEARCHPREF_TIME_LIMIT`

Specifies the number of seconds that the server waits for a search to complete. When the time limit is reached, the server stops searching and returns the results accumulated to that point. If this value is zero, the timeout period is infinite. The default for this value is 120 seconds.

### `ADS_SEARCHPREF_ATTRIBTYPES_ONLY`

Indicates that the search should obtain only the name of attributes to which values are assigned.

### `ADS_SEARCHPREF_SEARCH_SCOPE`

Specifies the search scope that should be observed by the server. For more information about the appropriate settings, see the [ADS_SCOPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_scopeenum) enumeration.

### `ADS_SEARCHPREF_TIMEOUT`

Specifies the time limit, in seconds, that a client will wait for the server to return the result. This option is set in an [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure.

### `ADS_SEARCHPREF_PAGESIZE`

Specifies the page size in a paged search. For each request by the client, the server returns, at most, the number of objects as set by the page size. When page size is set, it is unnecessary to set the size limit. If a size limit is set, then the value for page size must be less than the value for size limit. If the value for page size exceeds size limit, then the **ERROR_DS_SIZELIMIT_EXCEEDED** error is returned with the number of rows specified by size limit.

### `ADS_SEARCHPREF_PAGED_TIME_LIMIT`

Specifies the number of seconds that the server should wait for a page of search results, as opposed to the time limit for the entire search. When the time limit is reached, the server stops searching and returns the results obtained up to that point, along with a cookie that contains the data about where to resume searching. If this value is zero, the page timeout period is infinite. The default value for this limit is 120 seconds.

### `ADS_SEARCHPREF_CHASE_REFERRALS`

Specifies that referrals may be chased. If the root search is not specified in the naming context of the server or when the search results cross a naming context, for example, when you have child domains and search in the parent domain, the server sends a referral message to the client which the client can choose to ignore or chase. For more information about referral chasing, see [ADS_CHASE_REFERRALS_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_chase_referrals_enum).

### `ADS_SEARCHPREF_SORT_ON`

Specifies that the server sorts the result set. Use the [ADS_SORTKEY](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_sortkey) structure to specify the sort keys. This search preference works only for directory servers that support the LDAP control for server-side sorting. Active Directory supports the sort control, but it can impact server performance, particularly if the results set is large. Active Directory supports only a single sort key.

### `ADS_SEARCHPREF_CACHE_RESULTS`

Specifies if the result should be cached on the client side. By default, ADSI caches the result set. Disabling this option may be desirable for large result sets.

### `ADS_SEARCHPREF_DIRSYNC`

Specifies a directory synchronization (DirSync) search, which returns all changes since a specified state. In the [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure, set the **dwType** member to [ADS_PROV_SPECIFIC](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_prov_specific). The **ProviderSpecific** member is an **ADS_PROV_SPECIFIC** structure whose **lpValue** member specifies a cookie that indicates the state from which changes are retrieved. The first time you use the DirSync control, set the **dwLength** and **lpValue** members of the **ADS_PROV_SPECIFIC** structure to zero and **NULL** respectively. After reading the results set returned by the search until [IDirectorySearch::GetNextRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getnextrow) returns **S_ADS_NOMORE_ROWS**, call [IDirectorySearch::GetColumn](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getcolumn) to retrieve the **ADS_DIRSYNC_COOKIE** attribute which contains a cookie to use in the next DirSync search. For more information, see [Polling for Changes Using the DirSync Control](https://learn.microsoft.com/windows/desktop/AD/polling-for-changes-using-the-dirsync-control) and [LDAP_SERVER_DIRSYNC_OID](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-server-dirsync-oid).

This flag cannot be combined with **ADS_SEARCHPREF_PAGESIZE**.

The caller must have the **SE_SYNC_AGENT_NAME** privilege.

### `ADS_SEARCHPREF_TOMBSTONE`

Specifies whether the search should also return deleted objects that match the search filter. When objects are deleted, Active Directory moves them to a "Deleted Objects" container. By default, deleted objects are not included in the search results. In the [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure, set the **dwType** member to **ADSTYPE_BOOLEAN**. To include deleted objects, set the **Boolean** member of the **ADSVALUE** structure to **TRUE**.

Not all attributes are preserved when the object is deleted. You can retrieve the **objectGUID** and **RDN** attributes. The **distinguishedName** attribute is the DN of the object in the "Deleted Objects" container, not the previous DN. The **isDeleted** attribute is **TRUE** for a deleted object. For more information, see [Retrieving Deleted Objects](https://learn.microsoft.com/windows/desktop/AD/retrieving-deleted-objects).

### `ADS_SEARCHPREF_VLV`

Specifies that the search should use the LDAP virtual list view (VLV) control. **ADS_SEARCHPREF_VLV** can be used to access both string-type and offset-type VLV searches, by setting the appropriate fields. These two options cannot be used simultaneously because it is not possible to set the VLV control to request a result set that is both located at a specific offset and follows a particular value in the sort sequence.

To perform a string search, set the **lpszTarget** field in [ADS_VLV](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_vlv) to the string to be searched for. To perform an offset type search, set the dwOffset field in **ADS_VLV**. If you use an offset search, you must set **lpszTarget** to **NULL**.

**ADS_SEARCHPREF_SORT_ON** must be set to **TRUE** when using **ADS_SEARCHPREF_VLV**. The sort order of the search results determines the order used for the VLV search. If performing an offset-type search, the offset is used as an index into the sorted list. If performing a string-type search, the server attempts to return the first entry which is greater-than-or-equal-to the string, based on the sort order.

Caching of search results is disabled when **ADS_SEARCHPREF_VLV** is specified.

If you assign **ADS_SEARCHPREF_CACHE_RESULTS** a **TRUE**, value when using **ADS_SEARCHPREF_VLV**, [SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) will fail and return the error **E_ADS_BAD_PARAMETER**.

### `ADS_SEARCHPREF_ATTRIBUTE_QUERY`

Specifies that an attribute-scoped query search should be performed. The search is performed against those objects named in a specified attribute of the base object. The **vValue** member of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure contains a **ADSTYPE_CASE_IGNORE_STRING** value which contains the lDAPDisplayName of attribute to search. This attribute must be a **ADS_DN_STRING** attribute. Only one attribute may be specified. Search scope is automatically set to **ADS_SCOPE_BASE** when using this preference, and attempting to set the scope otherwise will fail with the error **E_ADS_BAD_PARAMETER**. With the exception of the **ADS_SEARCHPREF_VLV** preference, all other preferences that use LDAP controls, such as **ADS_SEARCHPREF_DIRSYNC**, **ADS_SEARCHPREF_TOMBSTONE**, and so on, are not allowed when this preference is specified.

### `ADS_SEARCHPREF_SECURITY_MASK`

Specifies that the search should return security access data for the specified attributes. The **vValue** member of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure contains an **ADS_INTEGER** value that is a combination of one or more of the following values.

| Value | Description |
| --- | --- |
| **ADS_SECURITY_INFO_OWNER** | Reads the owner data. |
| **ADS_SECURITY_INFO_GROUP** | Reads the group data. |
| **ADS_SECURITY_INFO_DACL** | Reads the discretionary access-control list (DACL). |
| **ADS_SECURITY_INFO_SACL** | Reads the system access-control list (SACL). |

If you read a security descriptor without explicitly specifying a security mask using **ADS_SEARCHPREF_SECURITY_MASK**, it defaults to the equivalent of **ADS_SECURITY_INFO_OWNER** | **ADS_SECURITY_INFO_GROUP** | **ADS_SECURITY_INFO_DACL**.

### `ADS_SEARCHPREF_DIRSYNC_FLAG`

Contains optional flags for use with the **ADS_SEARCHPREF_DIRSYNC** search preference. The **vValue** member of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure contains an **ADSTYPE_INTEGER** value that is zero or a combination of one or more of the following values. For more information about the DirSync control, see [Polling for Changes Using the DirSync Control](https://learn.microsoft.com/windows/desktop/AD/polling-for-changes-using-the-dirsync-control) and [LDAP_SERVER_DIRSYNC_OID](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-server-dirsync-oid).

| Identifier | Value | Description |
| --- | --- | --- |
| **LDAP_DIRSYNC_OBJECT_SECURITY** | 1 | If this flag is not present, the caller must have the replicate changes right. If this flag is present, the caller requires no rights, but is only allowed to see objects and attributes which are accessible to the caller. |
| **LDAP_DIRSYNC_ANCESTORS_FIRST_ORDER** | 2048 (0x00000800) | Return parent objects before child objects, when parent objects would otherwise appear later in the replication stream. |
| **LDAP_DIRSYNC_PUBLIC_DATA_ONLY** | 8192 (0x00002000) | Do not return private data in the search results. |
| **LDAP_DIRSYNC_INCREMENTAL_VALUES** | 2147483648 (0x80000000) | If this flag is not present, all of the values, up to a server-specified limit, in a multi-valued attribute are returned when any value changes. If this flag is present, only the changed values are returned. |

### `ADS_SEARCHPREF_EXTENDED_DN`

The search should return distinguished names in Active Directory extended format. The **vValue** member of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure contains an **ADSTYPE_INTEGER** value that contains zero if the GUID and SID portions of the DN string should be in hex format or one if the GUID and SID portions of the DN string should be in standard format. For more information about extended distinguished names, see [LDAP_SERVER_EXTENDED_DN_OID](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-server-extended-dn-oid).

## Remarks

To setup a search preference, assign appropriate values to the fields of an
[ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure passed to the server. The **vValue** member of the **ADS_SEARCHPREF_INFO** structure is an [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure. The following list lists the **ADS_SEARCHPREF_ENUM** values, the corresponding values for the **dwType** member of the **ADSVALUE** structure, and the **ADSVALUE** member that is used for the specified type.

| **ADS_SEARCHPREF_ENUM** value | **dwType** member of [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) | [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) member |
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

To setup multiple preferences, use an array of [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structures. The member values of this enumeration are assigned to the **dwSearchPref** member of the **ADS_SEARCHPREF_INFO** structure.

All options are supported by the LDAP system provider.

Because VBScript cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined above. You should use the numerical constants, instead, to set the appropriate flags in your VBScript applications. To use the symbolic constants, as a good programming practice, explicitly declare such constants, as done here, in your VBScript applications.

#### Examples

The following code example shows how to set up search preferences using the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) enumeration.

```cpp
HRESULT SetSearchPreferences2(
    DWORD dwScope,// -1 indicates default: subtree.
    DWORD dwOverallTimeOut,// <=0 indicates default: no time out set.
    DWORD dwOverallSizeLimit,// <=0 indicates default: no size limit set.
    DWORD dwOverallTimeLimit,// <=0 indicates default: no time limit set.
    BOOL bCacheResult,// TRUE indicates default.
    BOOL bIsAsynchronous,// FALSE indicates default.
    DWORD dwPageSize,// <=0 indicates default.
    DWORD dwPageTimeLimit,// <=0 indicates default.
    DWORD dwChaseReferral,// <=0 indicates default.
    LPOLESTR szSortKey,// NULL indicates do not sort.
    BOOL bIsDescending,
    BOOL bReturnAttributeNamesOnly,// FALSE indicates default.
    ADS_SEARCHPREF_INFO **ppSearchPref, // Return an array of search preferences.
    DWORD *pdwSearchPrefCount
)
{
   HRESULT hr = S_OK;
   DWORD dwCountPref = 0L;

   // Determine size of preferences array.
   DWORD dwTotal = 11L;

   if(dwScope==-1)
       dwTotal--;
   if(dwOverallTimeOut<=0)
       dwTotal--;
   if(dwOverallSizeLimit<=0)
       dwTotal--;
   if(dwOverallTimeLimit<=0)
       dwTotal--;
   if(bCacheResult)
       dwTotal--;
   if(!bIsAsynchronous)
       dwTotal--;
   if(dwPageSize<=0)
       dwTotal--;
   if(dwPageTimeLimit<=0)
       dwTotal--;
   if(dwChaseReferral<=0)
       dwTotal--;
   if(!bReturnAttributeNamesOnly)
       dwTotal--;
   if (!szSortKey)
       dwTotal--;

   ADS_SEARCHPREF_INFO *prefInfo = new ADS_SEARCHPREF_INFO[ dwTotal ];
   ADS_SORTKEY SortKey;

    if(!prefInfo)
    {
        return E_OUTOFMEMORY;
    }

    //////////////////
    // Search Scope
    //////////////////
    if(dwScope>=0)
    {
        prefInfo[dwCountPref].dwSearchPref =
                         ADS_SEARCHPREF_SEARCH_SCOPE;
        prefInfo[dwCountPref].vValue.dwType = ADSTYPE_INTEGER;
        prefInfo[dwCountPref].vValue.Integer = dwScope;
        dwCountPref++;
    }

    //////////////////
    // Time Out
    //////////////////
    if(dwOverallTimeOut>0)
    {
       prefInfo[dwCountPref].dwSearchPref = ADS_SEARCHPREF_TIMEOUT;
       prefInfo[dwCountPref].vValue.dwType = ADSTYPE_INTEGER;
       prefInfo[dwCountPref].vValue.Integer = dwOverallTimeOut;
       dwCountPref++;
    }

    ///////////////
    // Size Limit
    ///////////////
    if(dwOverallSizeLimit>0)
    {
       prefInfo[dwCountPref].dwSearchPref = ADS_SEARCHPREF_SIZE_LIMIT;
       prefInfo[dwCountPref].vValue.dwType = ADSTYPE_INTEGER;
       prefInfo[dwCountPref].vValue.Integer = dwOverallSizeLimit;
       dwCountPref++;
    }

    ///////////////
    // Time Limit
    ///////////////
    if(dwOverallTimeLimit>0)
    {
       prefInfo[dwCountPref].dwSearchPref = ADS_SEARCHPREF_TIME_LIMIT;
       prefInfo[dwCountPref].vValue.dwType = ADSTYPE_INTEGER;
       prefInfo[dwCountPref].vValue.Integer = dwOverallTimeLimit;
       dwCountPref++;
    }

    /////////////////
    // Cache Result
    /////////////////

    if (!bCacheResult)
    {
        prefInfo[dwCountPref].dwSearchPref =
                              ADS_SEARCHPREF_CACHE_RESULTS;
        prefInfo[dwCountPref].vValue.dwType = ADSTYPE_BOOLEAN;
        prefInfo[dwCountPref].vValue.Boolean = bCacheResult;
        dwCountPref++;
    }

    //////////////
    // Page Size
    //////////////
    if(dwPageSize>0)
    {
        prefInfo[dwCountPref].dwSearchPref = ADS_SEARCHPREF_PAGESIZE;
        prefInfo[dwCountPref].vValue.dwType = ADSTYPE_INTEGER;;
        prefInfo[dwCountPref].vValue.Integer = dwPageSize;
        dwCountPref++;
    }

    //////////////////
    // Page Time Limit
    //////////////////
    if(dwPageTimeLimit>0)
    {
        prefInfo[dwCountPref].dwSearchPref =
                                      ADS_SEARCHPREF_PAGED_TIME_LIMIT;
        prefInfo[dwCountPref].vValue.dwType = ADSTYPE_INTEGER;;
        prefInfo[dwCountPref].vValue.Integer = dwPageTimeLimit;
        dwCountPref++;
    }

    ///////////////////
    // Chase Referrals
    ///////////////////
    if(dwChaseReferral>0)
    {
        prefInfo[dwCountPref].dwSearchPref =
                                      ADS_SEARCHPREF_CHASE_REFERRALS;
        prefInfo[dwCountPref].vValue.dwType = ADSTYPE_INTEGER;
        prefInfo[dwCountPref].vValue.Integer = dwChaseReferral;
        dwCountPref++;
    }

    /////////////
    // Sort
    /////////////
    if (szSortKey)
    {
        prefInfo[dwCountPref].dwSearchPref = ADS_SEARCHPREF_SORT_ON;
        prefInfo[dwCountPref].vValue.dwType = ADSTYPE_PROV_SPECIFIC;
        SortKey.pszAttrType = (LPWSTR)LocalAlloc(
                        LPTR,
                        wcslen(szSortKey)*sizeof(WCHAR) +sizeof(WCHAR)
                        );
        wcscpy_s(SortKey.pszAttrType,szSortKey);
        SortKey.pszReserved = NULL;
        SortKey.fReverseorder = 0;
        prefInfo[dwCountPref].vValue.ProviderSpecific.dwLength =
                                                 sizeof(ADS_SORTKEY);
        prefInfo[dwCountPref].vValue.ProviderSpecific.lpValue =
                                                 (LPBYTE) &SortKey;
        dwCountPref++;
    }

    /////////////////
    // Asynchronous
    /////////////////
    if(bIsAsynchronous)
    {
        prefInfo[dwCountPref].dwSearchPref =
                                     ADS_SEARCHPREF_ASYNCHRONOUS;
        prefInfo[dwCountPref].vValue.dwType = ADSTYPE_BOOLEAN;
        prefInfo[dwCountPref].vValue.Integer = bIsAsynchronous;
        dwCountPref++;
    }

    ////////////////////////
    // Attribute Type Only
    ////////////////////////
    if(bReturnAttributeNamesOnly)
    {
        prefInfo[dwCountPref].dwSearchPref =
                                  ADS_SEARCHPREF_ATTRIBTYPES_ONLY;
        prefInfo[dwCountPref].vValue.dwType = ADSTYPE_BOOLEAN;
        prefInfo[dwCountPref].vValue.Integer =
                                  bReturnAttributeNamesOnly;
        dwCountPref++;
    }

    if (SUCCEEDED(hr))
    {
        *pdwSearchPrefCount = dwCountPref;
        *ppSearchPref  = prefInfo;
    }
    else
    {
        *pdwSearchPrefCount = 0L;
        *ppSearchPref  = NULL;
    }

    return hr;
}
```

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue)

[ADS_CHASE_REFERRALS_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_chase_referrals_enum)

[ADS_DEREFENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_derefenum)

[ADS_PROV_SPECIFIC](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_prov_specific)

[ADS_SCOPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_scopeenum)

[ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info)

[ADS_SORTKEY](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_sortkey)

[ADS_VLV](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_vlv)

[IDirectorySearch::GetColumn](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getcolumn)

[IDirectorySearch::GetNextRow](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-getnextrow)

[IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference)

[Polling for Changes Using the DirSync Control](https://learn.microsoft.com/windows/desktop/AD/polling-for-changes-using-the-dirsync-control)

[Retrieving
Deleted Objects](https://learn.microsoft.com/windows/desktop/AD/retrieving-deleted-objects)