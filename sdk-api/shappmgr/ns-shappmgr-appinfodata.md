# APPINFODATA structure

## Description

Provides information about a published application to the Add/Remove Programs Control Panel utility.

## Members

### `cbSize`

Type: **DWORD**

A value of type **DWORD** that specifies the size of the **APPINFODATA** data structure. This field is set by the Add/Remove Program executable code.

### `dwMask`

Type: **DWORD**

A value of type **DWORD** that specifies the bitmask that indicates which items in the structure are desired or valid. Implementations of [GetAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ishellapp-getappinfo) should inspect this value for bits that are set and attempt to provide values corresponding to those bits. Implementations should also return with bits set for only those members that are being returned.

### `pszDisplayName`

Type: **LPWSTR**

A pointer to a string that contains the application display name. Memory for this string must be allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pszVersion`

Type: **LPWSTR**

Not applicable to published applications.

### `pszPublisher`

### `pszProductID`

Type: **LPWSTR**

Not applicable to published applications.

### `pszRegisteredOwner`

Type: **LPWSTR**

Not applicable to published applications.

### `pszRegisteredCompany`

Type: **LPWSTR**

Not applicable to published applications.

### `pszLanguage`

Type: **LPWSTR**

Not applicable to published applications.

Type: **LPWSTR**

Not applicable to published applications.

### `pszSupportUrl`

Type: **LPWSTR**

A URL to support information. This string is displayed as a link with the application name in Control Panel Add/Remove Programs. Memory for this string must be allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pszSupportTelephone`

Type: **LPWSTR**

Not applicable to published applications.

### `pszHelpLink`

Type: **LPWSTR**

Not applicable to published applications.

### `pszInstallLocation`

Type: **LPWSTR**

Not applicable to published applications.

### `pszInstallSource`

Type: **LPWSTR**

Not applicable to published applications.

### `pszInstallDate`

Type: **LPWSTR**

Not applicable to published applications.

### `pszContact`

Type: **LPWSTR**

Not applicable to published applications.

### `pszComments`

Type: **LPWSTR**

Not applicable to published applications.

### `pszImage`

Type: **LPWSTR**

Not applicable to published applications.

### `pszReadmeUrl`

Type: **LPWSTR**

Not applicable to published applications.

### `pszUpdateInfoUrl`

Type: **LPWSTR**

Not applicable to published applications.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IPublishedApp::GetPublishedAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-getpublishedappinfo)