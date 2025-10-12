# CRYPT\_RETURN\_HWND function pointer

The **FuncReturnhWnd** callback function is used by a [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) to obtain the window handle that the CSP should use as the parent or owner of any user interface that is displayed.

## Parameters

*phWnd* \[in, out\]

The address of an **HWND** variable that receives the parent window handle.

## Return value

This function pointer does not return a value.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Cspdk.h |

## See also

[**CPAcquireContext**](https://www.bing.com/search?q=**CPAcquireContext**)

[**VTableProvStruc**](https://learn.microsoft.com/windows/win32/seccrypto/vtableprovstruc)

