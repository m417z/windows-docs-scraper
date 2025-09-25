# DsReplicaDelA function

## Description

The **DsReplicaDel** function removes a replication source reference from a destination naming context (NC).

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `NameContext` [in]

Pointer to a constant null-terminated string that specifies the distinguished name (DN) of the destination NC from which to remove the replica. The destination NC record must exist locally as either an object, instantiated or not, or a reference phantom, for example, a phantom with a GUID.

### `DsaSrc` [in]

Pointer to a constant null-terminated Unicode string that specifies the transport-specific address of the source directory system agent (DSA). This source server is identified by a string name, not by its **UUID**. A string name appropriate for *DsaSrc* is usually a DNS name that is based on a **GUID**, where the **GUID** part of the name is the **GUID** of the nTDSDSA object for the source server.

### `Options` [in]

Passes additional data used to process the request. This parameter can be a combination of the following values.

#### DS_REPDEL_ASYNCHRONOUS_OPERATION

Performs this operation asynchronously.

#### DS_REPDEL_IGNORE_ERRORS

Ignores any error generated from contacting the source to instruct it to remove this NC from its list of servers to which it replicates.

#### DS_REPDEL_INTERSITE_MESSAGING

Signifies the replica is mail-based rather than synchronized using native directory service RPC.

#### DS_REPDEL_LOCAL_ONLY

Does not contact the source to tell it to remove this NC from its list of servers to which it replicates. If this flag is not set and the link is based in RPC, the source is contacted.

#### DS_REPDEL_NO_SOURCE

Deletes all the objects in the NC. This option is valid only for read-only NCs with no source.

#### DS_REPDEL_REF_OK

Allows deletion of a read-only replica even if it sources other read-only replicas.

#### DS_REPDEL_WRITEABLE

Signifies that the replica deleted can be written to.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is a standard Win32 API error or **ERROR_INVALID_PARAMETER** if a parameter is invalid.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsReplicaAdd](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaadda)

[DsReplicaModify](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicamodifya)

[DsReplicaSync](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicasynca)

[DsReplicaUpdateRefs](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsreplicaupdaterefsa)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsReplicaDel as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).