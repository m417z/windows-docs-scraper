# AUTO_PROXY_SCRIPT_BUFFER structure

## Description

The **AUTO_PROXY_SCRIPT_BUFFER** structure is used to pass an autoproxy script in a buffer to [InternetInitializeAutoProxyDll](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetinitializeautoproxydll) , instead of identifying a file that **InternetInitializeAutoProxyDll** opens.

## Members

### `dwStructSize`

Size of this structure. Always set to "sizeof(AUTO_PROXY_SCRIPT_BUFFER)".

### `lpszScriptBuffer`

Pointer to the script buffer being passed using this structure.

### `dwScriptBufferSize`

Size of the script buffer pointed to by **lpszScriptBuffer**.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetInitializeAutoProxyDll](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetinitializeautoproxydll)