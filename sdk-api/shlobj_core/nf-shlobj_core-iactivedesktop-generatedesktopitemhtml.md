# IActiveDesktop::GenerateDesktopItemHtml

## Description

Generates a generic HTML page containing the given desktop item.

## Parameters

### `pwszFileName` [in]

Type: **PCWSTR**

A string value that contains the name under which to store the HTML file.

### `pcomp` [in]

Type: **LPCOMPONENT**

A pointer to the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure of the desktop item to insert in the HTML page.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)