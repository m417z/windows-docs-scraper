## Description

Configures automatic retry behavior for failed connections when used with the [**WINHTTP_OPTION_FAILED_CONNECTION_RETRIES**](https://learn.microsoft.com/windows/win32/winhttp/option-flags) option flag. This structure specifies how many retries are allowed and under which conditions WinHTTP should retry a failed connection.

## Members

### `dwMaxRetries`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum number of retries allowed based on the retry conditions specified in *dwAllowedRetryConditions*.

### `dwAllowedRetryConditions`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A bitmask of values defining the retry conditions to be checked. This can be a combination of one or more of the following values.

| Value | Meaning |
|-------|---------|
| **WINHTTP_CONNECTION_RETRY_CONDITION_408** (0x1) | Retries if WinHTTP received a 408 (Request Timeout) response from the server. |
| **WINHTTP_CONNECTION_RETRY_CONDITION_SSL_HANDSHAKE** (0x2) | Retries on TLS/SSL handshake failures. |
| **WINHTTP_CONNECTION_RETRY_CONDITION_STALE_CONNECTION** (0x4) | Retries if a request send operation times out on a reused and stale connection. |

## Remarks

This structure is used with [**WinHttpSetOption**](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) when setting the [**WINHTTP_OPTION_FAILED_CONNECTION_RETRIES**](https://learn.microsoft.com/windows/win32/winhttp/option-flags) option on a session handle. The option must be set on the session handle before any connection or request handles are created from that session.

The following code example shows how to set this option to retry up to 5 times on stale connection failures.

``` syntax
WINHTTP_FAILED_CONNECTION_RETRIES FailedConnectRetries;
FailedConnectRetries.dwMaxRetries = 5;
FailedConnectRetries.dwAllowedRetryConditions = WINHTTP_CONNECTION_RETRY_CONDITION_STALE_CONNECTION;

WinHttpSetOption(hSession,
                 WINHTTP_OPTION_FAILED_CONNECTION_RETRIES,
                 &FailedConnectRetries,
                 sizeof(FailedConnectRetries));
```

## See also

[**WINHTTP_OPTION_FAILED_CONNECTION_RETRIES**](https://learn.microsoft.com/windows/win32/winhttp/option-flags)

[**WinHttpSetOption**](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption)