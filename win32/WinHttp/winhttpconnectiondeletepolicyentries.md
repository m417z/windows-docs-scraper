# WinHttpConnectionDeletePolicyEntries function

Removes all connection routing policy entries associated with a specific policy tag from the WinHTTP Auto-Proxy Service.

## Parameters

### hSession [in]

A valid WinHTTP session handle created by [**WinHttpOpen**](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopen). The handle must be a session-level handle.

### PolicyEntryTag [in]

Identifies which set of policy entries to remove. One of the following values.

| Value | Meaning |
|-------|---------|
| **TAG_WINHTTP_CONNECTION_POLICY_TAG_DEFAULT** (0) | Default/untagged policy entries. |
| **TAG_WINHTTP_CONNECTION_POLICY_TAG_CONNECTION_MANAGER** (1) | Entries managed by the system connection manager. |
| **TAG_WINHTTP_CONNECTION_POLICY_TAG_WWWPT** (2) | Entries managed by the WWWPT (Windows Web Platform Transport) component. |

## Return value

Returns **ERROR_SUCCESS** (0) on success. Returns a [system error code](https://learn.microsoft.com/windows/win32/debug/system-error-codes) on failure, including the following.

| Value | Description |
|-------|-------------|
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | *hSession* is not a session handle. |
| **ERROR_WINHTTP_NOT_INITIALIZED** | WinHTTP globals are not initialized. |
| **ERROR_ACCESS_DENIED** | Caller lacks required privileges. |

## Remarks

> [!NOTE]
> This API is not currently included in an SDK header file. You must declare the function yourself in your code.

Removes all policy entries previously registered with the specified tag. Other tags' entries remain unaffected.

Typically called before [**WinHttpConnectionSetPolicyEntries**](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionsetpolicyentries) to ensure a clean slate when refreshing policy from the owning component.

This API requires elevated (administrator/SYSTEM) privileges.

## Requirements

| Requirement | Value |
|---|---|
| Header | N/A |
| Library | winhttp.lib |
| DLL | winhttp.dll |

## See also

- [WinHttpConnectionSetPolicyEntries](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionsetpolicyentries)
- [WinHttpOpen](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopen)