# WintrustSetRegPolicyFlags function

## Description

The **WintrustSetRegPolicyFlags** function sets policy flags for a policy provider.

**Note** This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `dwPolicyFlags` [in]

This parameter can be a bitwise combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **WTPF_TRUSTTEST** | Trust any test certificate. |
| **WTPF_TESTCANBEVALID** | Check any test certificate for validity. |
| **WTPF_IGNOREEXPIRATION** | Do not check the expiration date. |
| **WTPF_IGNOREREVOKATION** | Do not check revocation. |
| **WTPF_OFFLINEOK_IND** | If the source is offline, trust any individual certificates. |
| **WTPF_OFFLINEOK_COM** | If the source is offline, trust any commercial certificates. |
| **WTPF_OFFLINEOKNBU_IND** | If the source is offline, trust any individual certificates. Do not use the user interface (UI). |
| **WTPF_OFFLINEOKNBU_COM** | If the source is offline, trust any commercial certificates. Do not use the checking UI. |
| **WTPF_VERIFY_V1_OFF** | Turn off verification of version 1.0 certificates. |
| **WTPF_IGNOREREVOCATIONONTS** | Ignore time stamp revocation checks. |
| **WTPF_ALLOWONLYPERTRUST** | Allow only items in personal trust database. |

## Return value

Returns nonzero if the policy flags were set successfully or zero otherwise.

## See also

[WintrustGetRegPolicyFlags](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustgetregpolicyflags)