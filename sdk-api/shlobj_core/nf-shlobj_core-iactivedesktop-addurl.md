# IActiveDesktop::AddUrl

## Description

Adds the desktop item associated with the specified URL.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the parent window for the user interface.

### `pszSource` [in]

Type: **PCWSTR**

A pointer to a string that contains the URL of the desktop item.

### `pcomp` [in]

Type: **LPCOMPONENT**

A pointer to the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure that contains the details of the desktop item to be added.

### `dwFlags`

Type: **DWORD**

An unsigned long integer value that controls this method. Can be set to ADDURL_SILENT to add a desktop item without displaying any user interfaces.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failed to add the desktop item or an instance of the desktop item already exists on the Active Desktop. |
| **E_INVAILDARG** | One or more of the parameters were invalid. |
| **S_OK** | If the ADDURL_SILENT flag has been set, the desktop item has either been added successfully or it already exists on the Active Desktop. Otherwise, the desktop item has been added successfully. |

## Remarks

By default, this method will display some user interface and then add the desktop item to the Active Desktop. Like [IActiveDesktop::AddDesktopItem](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-adddesktopitem), the client application must call [IActiveDesktop::ApplyChanges](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-applychanges) to have the changes saved to the registry.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)

[Using the Active Desktop Object](https://learn.microsoft.com/windows/desktop/lwef/active-desktop-interface)