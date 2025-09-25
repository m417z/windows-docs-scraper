# LSA_AUDIT_ACCOUNT_LOGON callback function

## Description

The **AuditAccountLogon** function produces an audit record that represents the mapping of a foreign [principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) name onto a Windows account.

## Parameters

### `AuditId` [in]

[Security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)–defined message identifier. This value is included in the audit record.

### `Success` [in]

Specifies whether the audit record is generated on success or failure of the logon.

### `Source` [in]

Pointer to a
[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) specifying the source of the logon attempt.

### `ClientName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) specifying the client name.

### `MappedName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) containing the Windows account name to which the client name was mapped, if any.

### `Status` [in]

An NTSTATUS value specifying any error that occurred.

## Return value

This function returns STATUS_SUCCESS.

## Remarks

A pointer to the **AuditAccountLogon** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## See also

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)