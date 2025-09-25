# LSA_GET_CREDENTIALS callback function

## Description

Retrieves credentials associated with a logon session.

This function is not used by newer authentication packages, such as Kerberos.

## Parameters

### `LogonId` [in]

Pointer to an
[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure containing the session ID of the logon session from which credentials are to be retrieved.

### `AuthenticationPackage` [in]

Authentication package ID of the calling authentication package. Authentication packages should retrieve only their own credentials.

### `QueryContext` [in, out]

Pointer to an unsigned **LONG** value used across successive calls to retrieve multiple credentials. The first time this function is used, the value pointed to by this argument should be zero. Thereafter, this value will be updated to allow retrieval to continue where it left off. This value should, therefore, not be changed until all credentials of a given query operation have been retrieved.

### `RetrieveAllCredentials` [in]

Indicates whether all credentials for the specified logon session should be retrieved (**TRUE**), or only those matching the specified *PrimaryKeyValue* (**FALSE**).

### `PrimaryKeyValue` [in, out]

This parameter serves two purposes. If the *RetrieveAllCredentials* parameter is **FALSE**, this string contains the value to use as a primary lookup key. In this case, only credentials belonging to the correct logon session with a primary lookup key matching this value will be retrieved.

If *RetrieveAllCredentials* is **TRUE**, the value of this string on input is ignored and the primary lookup key of each credential retrieved is returned in this string.

### `PrimaryKeyLength` [out]

If the *RetrieveAllCredentials* parameter is **TRUE**, this parameter receives the length needed to store the *PrimaryKeyValue* string.

### `Credentials` [out]

Pointer to a buffer that receives the retrieved credential. Only one credential is retrieved for each call made. The credential is returned in a buffer that the function allocates by calling the
[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap) function. It is the caller's responsibility to free the *Credentials* buffer when it is no longer needed, by calling
[FreeLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntlsa/nc-ntlsa-lsa_free_lsa_heap).

## Return value

If the function succeeds, the function returns the NTSTATUS code, STATUS_SUCCESS, indicating that the credentials were successfully retrieved.

If the function fails, the return value is an NTSTATUS code, which can be one of the following values or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **ERROR_GEN_FAILURE** | No more credentials are available. If this code is returned on the first call, there are no credentials matching the selection criteria. |
| **STATUS_MORE_ENTRIES** | The string provided to receive the *PrimaryKeyValue* was not large enough to hold the data. In this case, no data is retrieved, and the *QueryContext* value is not modified. This allows the same call to be made again with a larger string buffer. |
| **STATUS_NO_SUCH_LOGON_SESSION** | The specified logon session could not be found. |

The
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function converts an NTSTATUS code to a Windows error code.

## See also

[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)