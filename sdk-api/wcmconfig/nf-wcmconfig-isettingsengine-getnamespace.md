# ISettingsEngine::GetNamespace

## Description

Opens an existing namespace as specified by the [ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsidentity) parameter.

## Parameters

### `SettingsID` [in]

An [ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsidentity) object that specifies an existing namespace to get.

### `Access` [in]

A [WcmNamespaceAccess](https://learn.microsoft.com/windows/win32/api/wcmconfig/ne-wcmconfig-wcmnamespaceaccess) value that specifies the type of access, whether it is read-only or read and write access.

### `Reserved` [in]

Reserved. Must be **NULL**.

### `NamespaceItem` [out]

A pointer to an [ISettingsNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsnamespace) object that is the result of the get operation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **WCM_E_USERNOTFOUND** | Indicates that the store is not currently loaded. |
| **WCM_E_NAMESPACENOTFOUND** | Indicates that the provided identity does not match a namespace registered in the store. |

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)