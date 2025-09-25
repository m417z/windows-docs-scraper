# DsReplicaGetInfo2W function

## Description

The **DsReplicaGetInfo2** function retrieves replication state data from the directory service. This function allows paging of results in cases where there are more than 1000 entries to retrieve.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `InfoType` [in]

Contains one of the [DS_REPL_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_info_type) values that specifies the type of replication data to retrieve. This value also determines which type of structure is returned in *ppInfo*.

### `pszObject` [in, optional]

Pointer to a constant null-terminated Unicode string that identifies the object to retrieve replication data for. The meaning of this parameter depends on the value of the *InfoType* parameter. The following are possible value codes.

#### DS_REPL_INFO_NEIGHBORS

*pszObject* identifies the naming context for which replication neighbors are requested.

#### DS_REPL_INFO_CURSORS_FOR_NC

*pszObject* identifies the naming context for which replication cursors are requested.

#### DS_REPL_INFO_METADATA_FOR_OBJ

*pszObject* identifies the object for which replication metadata is requested.

#### DS_REPL_INFO_KCC_DSA_CONNECT_FAILURES

*pszObject* must be **NULL**.

#### DS_REPL_INFO_KCC_DSA_LINK_FAILURES

*pszObject* must be **NULL**.

#### DS_REPL_INFO_PENDING_OPS

*pszObject* must be **NULL**.

#### DS_REPL_INFO_METADATA_FOR_ATTR_VALUE

*pszObject* identifies the object for which attribute replication metadata is requested.

#### DS_REPL_INFO_CURSORS_2_FOR_NC

#### DS_REPL_INFO_CURSORS_3_FOR_NC

#### DS_REPL_INFO_METADATA_2_FOR_OBJ

*pszObject* identifies the object for which replication metadata is requested.

#### DS_REPL_INFO_METADATA_2_FOR_ATTR_VALUE

*pszObject* identifies the object for which attribute replication metadata is requested.

### `puuidForSourceDsaObjGuid` [in, optional]

Pointer to a **GUID** value that identifies a specific replication source. If this parameter is not **NULL** and the *InfoType* parameter contains **DS_REPL_INFO_NEIGHBORS**, only neighbor data for the source corresponding to the nTDSDSA object with the given **objectGuid** in the directory is returned. This parameter is ignored if **NULL** or if the *InfoType* parameter is anything other than **DS_REPL_INFO_NEIGHBORS**.

### `pszAttributeName` [in, optional]

Pointer to a null-terminated Unicode string that contains the name of the specific attribute to retrieve replication data for.

This parameter is only used if the *InfoType* parameter contains one of the following values.

#### DS_REPL_INFO_METADATA_FOR_ATTR_VALUE

#### DS_REPL_INFO_METADATA_2_FOR_ATTR_VALUE

### `pszValue` [in, optional]

Pointer to a null-terminated Unicode string that contains the distinguished name value to match. If the requested attribute is a distinguished name type value, this function return the attributes that contain the specified value.

### `dwFlags` [in]

Contains a set of flags that modify the behavior of the function. This parameter can be zero or the following value.

#### DS_REPL_INFO_FLAG_IMPROVE_LINKED_ATTRS

Causes the attribute metadata to account for metadata on the attribute's linked values.
The resulting vector represents changes for all attributes. This modified
vector is useful for clients that expect all attributes and metadata to
be included in the attribute metadata vector.

### `dwEnumerationContext` [in]

Contains the index of the next entry to retrieve. This parameter must be set to zero the first time this function is called.

This parameter is only used if the *InfoType* parameter contains one of the following values.

#### DS_REPL_INFO_CURSORS_2_FOR_NC

#### DS_REPL_INFO_CURSORS_3_FOR_NC

#### DS_REPL_INFO_METADATA_FOR_ATTR_VALUE

#### DS_REPL_INFO_METADATA_2_FOR_ATTR_VALUE

This function will retrieve a maximum of 1000 entries on each call. If after calling this function, more entries are available, the **dwEnumerationContext** member of the retrieved structure will contain the index of the next entry to retrieve. The **dwEnumerationContext** member of the retrieved structure is then used as the *dwEnumerationContext* parameter in the next call to this function. When all of the entries have been retrieved, the **dwEnumerationContext** member of the retrieved structure will contain -1. If -1 is passed for this parameter, this function will return **ERROR_NO_MORE_ITEMS**.

### `ppInfo` [out]

Address of a structure pointer that receives the requested data. The value of the *InfoType* parameter determines the format of this structure. For more information and a list of possible *InfoType* values and the corresponding structure types, see [DS_REPL_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_info_type).

The caller must free this memory when it is no longer required by calling [DsReplicaFreeInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicafreeinfo).

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error otherwise.
The following are possible error codes.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsReplicaFreeInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicafreeinfo)