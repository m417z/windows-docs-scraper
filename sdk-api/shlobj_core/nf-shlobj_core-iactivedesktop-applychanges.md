# IActiveDesktop::ApplyChanges

## Description

Applies changes to the Active Desktop and saves them in the registry.

## Parameters

### `dwFlags`

Type: **DWORD**

An unsigned long integer value that contains the changes to be applied. Can be one of the following values.

#### AD_APPLY_ALL

#### AD_APPLY_BUFFERED_REFRESH

#### AD_APPLY_DYNAMICREFRESH

#### AD_APPLY_FORCE

#### AD_APPLY_HTMLGEN

#### AD_APPLY_REFRESH

#### AD_APPLY_SAVE

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)