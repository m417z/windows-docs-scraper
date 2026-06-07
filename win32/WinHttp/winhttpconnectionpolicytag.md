# WINHTTP_CONNECTION_POLICY_TAG enumeration

Identifies the owner or source of connection routing policy entries registered with the WinHTTP Auto-Proxy Service. Tags allow multiple components to independently manage their policy sets without overwriting each other.

## Constants

| Constant | Value | Description |
|----------|-------|-------------|
| **TAG_WINHTTP_CONNECTION_POLICY_TAG_DEFAULT** | 0 | Default/untagged policy entries. |
| **TAG_WINHTTP_CONNECTION_POLICY_TAG_CONNECTION_MANAGER** | 1 | Entries managed by the system connection manager. |
| **TAG_WINHTTP_CONNECTION_POLICY_TAG_WWWPT** | 2 | Entries managed by the WWWPT (Windows Web Platform Transport) component. |

## Remarks

> [!NOTE]
> This type is not currently included in an SDK header file. You must declare it yourself in your code.

## Requirements

| Requirement | Value |
|---|---|
| Header | N/A |

## See also

- [WinHttpConnectionSetPolicyEntries](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionsetpolicyentries)
- [WinHttpConnectionDeletePolicyEntries](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectiondeletepolicyentries)