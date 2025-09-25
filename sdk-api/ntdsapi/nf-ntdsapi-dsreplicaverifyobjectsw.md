# DsReplicaVerifyObjectsW function

## Description

The **DsReplicaVerifyObjects** function verifies all objects for a naming context with a source.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda),
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda), or [DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna) function.

### `NameContext` [in]

Pointer to a null-terminated string that contains the distinguished name of the naming context.

### `pUuidDsaSrc` [in]

Pointer to a **UUID** value that contains the **objectGuid** of the directory system agent object.

### `ulOptions` [in]

Contains a set of flags that modify the behavior of the function. This can be zero or the following value.

#### DS_EXIST_ADVISORY_MODE

Do not delete objects in response to this function.

##### - ulOptions.DS_EXIST_ADVISORY_MODE

Do not delete objects in response to this function.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 error otherwise. Possible error values include the following.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsReplicaVerifyObjects as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).