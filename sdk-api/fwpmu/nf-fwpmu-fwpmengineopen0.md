## Description

The **FwpmEngineOpen0** function opens a session to the filter engine.

## Parameters

### `serverName` [in, optional]

Type: **const wchar_t***

This value must be **NULL**.

### `authnService` [in]

Type: **UINT32**

Specifies the authentication service to use. Allowed services are RPC_C_AUTHN_WINNT and RPC_C_AUTHN_DEFAULT.

### `authIdentity` [in, optional]

Type: **[SEC_WINNT_AUTH_IDENTITY_A](https://learn.microsoft.com/windows/win32/api/rpcdce/ns-rpcdce-sec_winnt_auth_identity_a)***

The authentication and authorization credentials for accessing the filter engine. This pointer is optional and can be **NULL**. If this pointer is **NULL**, the calling thread's credentials are used.

### `session` [in, optional]

Type: [FWPM_SESSION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_session0)*

Session-specific parameters for the session being opened. This pointer is optional and can be **NULL**.

### `engineHandle` [out]

Type: **HANDLE***

Handle for the open session to the filter engine.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The session was started successfully. |
| **FWP_E_ALREADY_EXISTS**<br><br>0x80320009 | A session with the specified **sessionKey** is already opened. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

A user application must call **FwpmEngineOpen0** to obtain a handle for open session to the filter engine before adding or removing any filter objects. A handle for an open session to the filter engine is also required for most of the other Windows Filtering Platform management functions.

The session is automatically closed when the program ends. To explicitly close a session, call [FwpmEngineClose0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineclose0).

If *session*.**flags** is set to **FWPM_SESSION_FLAG_DYNAMIC**, any WFP objects added during the session are
automatically deleted when the session ends. If the session is not dynamic, the caller needs to explicitly delete all WFP objects added during the session.

The caller needs [FWPM_ACTRL_OPEN](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the filter engine. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmEngineOpen0** is intended for use in non-impersonated mode only.

**FwpmEngineOpen0** is a specific implementation of FwpmEngineOpen. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

#### Examples

The following C++ example uses **FwpmEngineOpen0** to open a filter session.

```cpp
// Open a session to the filter engine

HANDLE    engineHandle = NULL;
DWORD    result = ERROR_SUCCESS;

printf("Opening the filter engine.\n");

result = FwpmEngineOpen0(
    NULL,
    RPC_C_AUTHN_WINNT,
    NULL,
    NULL,
    &engineHandle );

if (result != ERROR_SUCCESS)
    printf("FwpmEngineOpen0 failed. Return value: %d.\n", result);
else
    printf("Filter engine opened successfully.\n");

```

## See also

[Authentication-Service Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-service-constants)

[FWPM_SESSION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_session0)

[FwpmEngineClose0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineclose0)

[Kernel-Mode FwpmEngineOpen0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineopen0)

[SEC_WINNT_AUTH_IDENTITY_A](https://learn.microsoft.com/windows/win32/api/rpcdce/ns-rpcdce-sec_winnt_auth_identity_a)