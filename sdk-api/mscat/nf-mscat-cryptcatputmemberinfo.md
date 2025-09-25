# CryptCATPutMemberInfo function

## Description

[The **CryptCATPutMemberInfo** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATPutMemberInfo** function allocates memory for a catalog member and adds it to the catalog.

## Parameters

### `hCatalog` [in]

A handle to the catalog obtained from the [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) or [CryptCATHandleFromStore](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcathandlefromstore) function.

### `pwszFileName` [in, optional]

A pointer to a null-terminated string for the catalog file name.

### `pwszReferenceTag` [in]

A pointer to a null-terminated string that contains the name of the member.

### `pgSubjectType` [in]

A GUID for the subject type of the member.

### `dwCertVersion` [in]

A value that specifies the certificate version.

### `cbSIPIndirectData` [in]

A value that specifies the number of bytes in the *pbSIPIndirectData* buffer.

### `pbSIPIndirectData` [in]

A pointer to a memory buffer for [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP)-indirect data.

## Return value

A pointer to a [CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember) structure that contains the assigned member. The caller must not free this pointer or any of its members.

If this function returns **NULL**, additional error information can be obtained by calling the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. **GetLastError** will return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | The operating system ran out of memory during the operation. |