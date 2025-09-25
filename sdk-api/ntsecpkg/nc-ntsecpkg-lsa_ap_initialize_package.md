# LSA_AP_INITIALIZE_PACKAGE callback function

## Description

Called once by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) during system initialization to provide the authentication package a chance to initialize itself.

## Parameters

### `AuthenticationPackageId` [in]

The identifier the LSA has assigned to the authentication package.

### `LsaDispatchTable` [in]

Pointer to an
[LSA_DISPATCH_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_dispatch_table) structure that contains the addresses of LSA functions that can be called by authentication packages. Your custom authentication package should save this information if it requires any of the functions described in
[LSA Functions Called by Authentication Packages](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions).

### `Database` [in, optional]

This parameter is not used; it is **NULL**.

### `Confidentiality` [in, optional]

This parameter is not used; it is **NULL**.

### `AuthenticationPackageName` [out]

Pointer to a pointer to an [LSA_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_string) structure that receives the name of the authentication package. The authentication package is responsible for allocating the structure and the buffer that contains this string (using the
[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap) function) and returning the address of the structure in this parameter. The buffer will be freed by the LSA when it is no longer needed.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an NTSTATUS error code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

## Remarks

This function must be implemented by authentication packages.

## See also

[AllocateLsaHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_lsa_heap)