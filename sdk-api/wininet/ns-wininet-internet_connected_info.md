# INTERNET_CONNECTED_INFO structure

## Description

Contains the information to set the global online/offline state.

## Members

### `dwConnectedState`

State information. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_STATE_CONNECTED** | Connected to network. Replaces INTERNET_STATE_ONLINE. |
| **INTERNET_STATE_DISCONNECTED** | Disconnected from network. Replaces INTERNET_STATE_OFFLINE. |
| **INTERNET_STATE_DISCONNECTED_BY_USER** | Disconnected by user request. Replaces INTERNET_STATE_OFFLINE_USER. |
| **INTERNET_STATE_IDLE** | No network requests are being made. |
| **INTERNET_STATE_BUSY** | Network requests are being made. |

### `dwFlags`

Controls the transition between states. This member can be ISO_FORCE_DISCONNECTED, which puts WinINet into offline mode. All outstanding requests will be aborted with a canceled error.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona)