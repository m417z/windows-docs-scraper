# SecLookupAccountSid function

## Description

**SecLookupAccountSid** accepts a security identifier (SID) as input. It retrieves the name of the account for this SID and the name of the first domain on which this SID is found.

## Parameters

### `Sid` [in]

A pointer to the SID to look up.

### `NameSize` [out]

A pointer to a variable that specifies the size of the **NameBuffer**. On input, this value specifies the size in bytes of the input **NameBuffer**. If the function fails because the buffer is too small, this variable receives the required buffer size. On success, this variable contains the size of the returned **NameBuffer**.

### `NameBuffer` [in, out]

A pointer to a buffer that receives the name of the account associated with the **Sid**. If this parameter is NULL, **NameSize** will be zero.

### `DomainSize` [out]

A pointer to a ULONG that specifies the size of the **DomainBuffer** parameter. If the function fails because the buffer is too small, this variable receives the required buffer size. If the **DomainBuffer** parameter is **NULL**, this parameter will be set to be zero.

### `DomainBuffer` [out, optional]

A pointer to a buffer that receives the name of the first domain on which this SID is found.

### `NameUse` [out]

A pointer to a [**SID_NAME_USE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_sid_name_use) enumerated type that receives the type of the account.

## Return value

**SecLookupAccountSid** returns STATUS_SUCCESS on success or one of the following error codes on failure.

| Return code | Description |
| ----------- | ----------- |
| SEC_E_INTERNAL_ERROR | An internal error occurred while trying to connect to the Local System Authority (LSA) or the local procedure call (LPC) to the security provider failed. |
| STATUS_ACCESS_DENIED | The process ID associated with the currently executing thread does not match the current process ID. |
| STATUS_BUFFER_TOO_SMALL | The buffer size for the **NameBuffer** or the **ReferencedDomain** parameter was too small. |
| STATUS_INVALID_PARAMETER | The length of the **Name** parameter exceeded the length allowed in a message to the Local System Authority (LSA). |
| STATUS_NO_MEMORY | It was not possible to allocate sufficient memory for a temporary internal buffer used by this function. |
| STATUS_NONE_MAPPED | The **Sid** parameter could not be found. |
| STATUS_PROCESS_IS_TERMINATING | This process has terminated so it is not possible to establish a local procedure call (LPC) connection. |

## Remarks

**SecLookupAccountSid** attempts to find a name for the specified SID by first checking a list of well-known SIDs. If the supplied SID does not correspond to a well-known SID, the function checks built-in and administratively defined local accounts. Next, the function checks the primary domain. Security identifiers not recognized by the primary domain are checked against the trusted domains that correspond to their SID prefixes.

If the function cannot find an account name for the SID, **SecLookupAccountSid** fails. This can occur if a network time-out prevents the function from finding the name. It also occurs for SIDs that have no corresponding account name, such as a logon SID that identifies a logon session.

In addition to looking up SIDs for local accounts, local domain accounts, and explicitly trusted domain accounts, **SecLookupAccountSid** can look up SIDs for any account in any domain in the forest, including SIDs that appear only in the SIDhistory field of an account in the forest. The SIDhistory field stores former SIDs of an account that has been moved from another domain. To look up a SID, **SecLookupAccountSid** queries the global catalog of the forest.

**SecLookupAccountSid** is equivalent to the Win32 **LookupAccountSid** function.

**SecLookupAccountSid** is exported by the ksecdd driver, which implements this function by using user-mode helper services. Accordingly, the use of this function within file systems must obey the usual rules for communication with user-mode services. **SecLookupAccountSid** cannot be used during paging file I/O.

## See also

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SID_NAME_USE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_sid_name_use)

[**SecLookupAccountName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seclookupaccountname)

[**SecLookupWellKnownSid**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seclookupwellknownsid)