# DsReplicaUpdateRefsA function

## Description

The **DsReplicaUpdateRefs** function adds or removes a replication reference for a destination from a source naming context.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `NameContext` [in]

Pointer to a constant null-terminated string that specifies the distinguished name of the source naming context.

### `DsaDest` [in]

Pointer to a constant null-terminated string that specifies the transport-specific address of the destination directory system agent.

### `pUuidDsaDest` [in]

Pointer to a **UUID** value that contains the destination directory system agent.

### `Options` [in]

Contains a set of flags that provide additional data used to process the request. This can be zero or a combination of one or more of the following values.

#### DS_REPUPD_ADD_REFERENCE

A reference to the destination is added to the source server.

#### DS_REPUPD_ASYNCHRONOUS_OPERATION

The operation is performed asynchronously.

#### DS_REPUPD_DELETE_REFERENCE

A reference to the destination is removed from the source server.

#### DS_REPUPD_WRITEABLE

The reference to the replica added or removed is writable. Otherwise, it is read-only.

## Return value

If the function succeeds, **ERROR_SUCCESS** is returned.

If the function fails, the return value can be one of the following.

## Remarks

If both **DS_REPUPD_ADD_REFERENCE** and **DS_REPUPD_DELETE_REFERENCE** are set in the *Options* parameter, a reference to the destination is added if one does not already exist on the server. If a reference to the destination already exists, the reference is updated.

> [!NOTE]
> The ntdsapi.h header defines DsReplicaUpdateRefs as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda)

[DsReplicaDel](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicadela)

[DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya)

[DsReplicaSync](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasynca)