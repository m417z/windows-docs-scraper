# SLOWAPPINFO structure

## Description

Provides specialized application information to **Add/Remove Programs** in Control Panel. This structure is not applicable to published applications.

## Members

### `ullSize`

Type: **ULONGLONG**

The size of the application in bytes.

### `ftLastUsed`

Type: **FILETIME**

The time the application was last used.

### `iTimesUsed`

Type: **int**

The count of times the application has been used.

### `pszImage`

Type: **LPWSTR**

A pointer to a string containing the path to the image that represents the application. The string buffer must be allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Remarks

This structure is used by the [IShellApp::GetSlowAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ishellapp-getslowappinfo) and [IShellApp::GetCachedSlowAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ishellapp-getcachedslowappinfo) interfaces, neither of which are applicable to published applications. Therefore, this structure is also not applicable to published applications.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)