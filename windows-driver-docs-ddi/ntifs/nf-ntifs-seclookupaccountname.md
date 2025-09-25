# SecLookupAccountName function

## Description

**SecLookupAccountName** accepts an account as input and retrieves a security identifier (SID) for the account and the name of the domain on which the account was found.

## Parameters

### `Name` [in]

A pointer to a Unicode string that specifies the account name. Use a fully qualified string in the domain_name\user_name format to ensure that **SecLookupAccountName** finds the account in the desired domain.

### `SidSize` [in, out]

A pointer to a variable that specifies the size of the **Sid** buffer. On input, this value specifies the size in bytes of the input **Sid** buffer. If the function fails because the buffer is too small or if **SidSize** is zero, this variable receives the required buffer size. On success, this variable contains the size of the returned **Sid**.

### `Sid` [out]

A pointer to a buffer that receives the SID structure that corresponds to the account name pointed to by the **Name** parameter. If this parameter is **NULL**, **SidSize** must be zero.

### `NameUse` [out]

A pointer to a [**SID_NAME_USE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_sid_name_use) enumerated type that receives the type of the account.

### `DomainSize` [out]

A pointer to A ULONG that receives the size of the **ReferencedDomain** parameter. If the function fails because the buffer is too small, this variable receives the required buffer size. If the input **ReferencedDomain** parameter is NULL, this parameter will receive zero.

### `ReferencedDomain` [in_out, optional]

Pointer to a buffer for the name of the domain where the account name is found. This parameter is optional and can be NULL. For computers that are not joined to a domain, this buffer receives the computer name.

## Return value

**SecLookupAccountName** returns STATUS_SUCCESS on success or one of the following error codes on failure.

| Return code | Description |
| ----------- | ----------- |
| SEC_E_INTERNAL_ERROR | An internal error occurred while trying to connect to the Local System Authority (LSA) or the local procedure call (LPC) to the security provider failed. |
| STATUS_ACCESS_DENIED | The process ID associated with the currently executing thread does not match the current process ID. |
| STATUS_BUFFER_TOO_SMALL | The buffer size for the **Sid** or the **ReferencedDomain** parameter was too small. |
| STATUS_INVALID_PARAMETER | The length of the **Name** parameter exceeded the length allowed in a message to the Local System Authority. |
| STATUS_NONE_MAPPED | The **Name** parameter could not be found. |
| STATUS_PROCESS_IS_TERMINATING | This process has terminated so it is not possible to establish the local procedure call (LPC) connection. |

## Remarks

**SecLookupAccountName** attempts to find a SID for the specified name. The function checks built-in and administratively defined local accounts. Next, the function checks the primary domain. If the name is not found there, trusted domains are checked.

Use fully qualified account names (for example, domain_name\user_name) instead of isolated names (for example, user_name). Fully qualified names are unambiguous and provide better performance when the lookup is performed. This function also supports fully qualified DNS names (for example, example.example.com\user_name) and user principal names (UPN) (for example, someone@example.com).

In addition to looking up local accounts, local domain accounts, and explicitly trusted domain accounts, **SecLookupAccountName** can look up the name for any account in any domain in the forest.

**SecLookupAccountName** is equivalent to the Win32 **LookupAccountName** function.

**SecLookupAccountName** is exported by the ksecdd driver, which implements this function by using user-mode helper services. Accordingly, the use of this function within file systems must obey the usual rules for communication with user-mode services. **SecLookupAccountName** cannot be used during paging file I/O.

## See also

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SID_NAME_USE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_sid_name_use)

[**SecLookupAccountSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seclookupaccountsid)

[**SecLookupWellKnownSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seclookupwellknownsid)