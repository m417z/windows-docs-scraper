# AutoProxyHelperFunctions structure

## Description

The **AutoProxyHelperFunctions** structure is used to create a v-table of Proxy Auto-Config (PAC) functions that can be passed to [InternetInitializeAutoProxyDll](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetinitializeautoproxydll).

See the [Navigator Proxy Auto-Config (PAC) File Format](https://web.archive.org/web/20060424005037/wp.netscape.com/eng/mozilla/2.0/relnotes/demo/proxy-live.html) documentation for a specification of the form and use of Proxy Auto-Config helper functions.

## Members

### `lpVtbl`

Pointer to an [AutoProxyHelperVtbl](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-autoproxyhelpervtbl) structure that contains an array of pointers to autoproxy helper functions.

### `AutoProxyHelperVtbl`

## Remarks

Together with the [AutoProxyHelperVtbl](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-autoproxyhelpervtbl) structure, **AutoProxyHelperFunctions** serves to create a standard v-table that can be declared and populated using C rather than requiring the use of C++.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[AutoProxyHelperVtbl](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-autoproxyhelpervtbl)

[InternetInitializeAutoProxyDll](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetinitializeautoproxydll)