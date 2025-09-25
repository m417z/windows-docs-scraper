# DsReplicaGetInfoW function

## Description

The **DsReplicaGetInfo** function retrieves replication state data from the directory service.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `InfoType` [in]

Contains one of the [DS_REPL_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_info_type) values that specifies the type of replication data to retrieve. This value also determines which type of structure is returned in *ppInfo*.

Only the following values are supported for this function. If other data types are required, the [DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w) function must be used.

#### DS_REPL_INFO_NEIGHBORS

#### DS_REPL_INFO_CURSORS_FOR_NC

#### DS_REPL_INFO_METADATA_FOR_OBJ

#### DS_REPL_INFO_KCC_DSA_CONNECT_FAILURES

#### DS_REPL_INFO_KCC_DSA_LINK_FAILURES

#### DS_REPL_INFO_PENDING_OPS

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

### `puuidForSourceDsaObjGuid` [in, optional]

Pointer to a **GUID** value that identifies a specific replication source. If this parameter is not **NULL** and the *InfoType* parameter contains **DS_REPL_INFO_NEIGHBORS**, only neighbor data for the source corresponding to the nTDSDSA object with the given **objectGuid** in the directory is returned. This parameter is ignored if **NULL** or if the *InfoType* parameter is anything other than **DS_REPL_INFO_NEIGHBORS**.

### `ppInfo` [out]

Address of a structure pointer that receives the requested data. The value of the *InfoType* parameter determines the format of this structure. For more information and list of possible *InfoType* values and the corresponding structure types, see [DS_REPL_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_info_type).

The caller must free this memory when it is no longer required by calling [DsReplicaFreeInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicafreeinfo).

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error otherwise.
The following are possible error codes.

## See also

[DS_REPL_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_repl_info_type)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsReplicaFreeInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicafreeinfo)

[DsReplicaGetInfo2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicagetinfo2w)