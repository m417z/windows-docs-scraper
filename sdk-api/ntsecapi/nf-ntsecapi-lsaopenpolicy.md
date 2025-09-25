# LsaOpenPolicy function

## Description

The **LsaOpenPolicy** function opens a handle to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object on a local or remote system.

You must run the process "As Administrator" so that the call doesn't fail with ERROR_ACCESS_DENIED.

## Parameters

### `SystemName` [in]

A pointer to an
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the target system. The name can have the form "*ComputerName*" or "\\*ComputerName*". If this parameter is **NULL**, the function opens the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object on the local system.

### `ObjectAttributes` [in]

A pointer to an
[LSA_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_object_attributes) structure that specifies the connection attributes. The structure members are not used; initialize them to **NULL** or zero.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) that specifies the requested access rights. The function fails if the DACL of the target system does not allow the caller the requested access. To determine the access rights that you need, see the documentation for the LSA functions with which you want to use the policy handle.

### `PolicyHandle` [in, out]

A pointer to an
[LSA_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/lsa-handle) variable that receives a handle to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object.

When you no longer need this handle, pass it to the
[LsaClose](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaclose) function to close it.

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** code to a Windows error code.

## Remarks

To administer the local security policy of a local or remote system, you must call the **LsaOpenPolicy** function to establish a session with that system's LSA subsystem. **LsaOpenPolicy** connects to the LSA of the target system and returns a handle to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object of that system. You can use this handle in subsequent LSA function calls to administer the
[local security policy](https://learn.microsoft.com/windows/desktop/SecMgmt/local-security-policy) information of the target system.

For an example that demonstrates calling this function see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

## See also

[LSA_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/lsa-handle)

[LSA_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_object_attributes)

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaClose](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaclose)

[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror)