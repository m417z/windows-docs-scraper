# IFileDialogCustomize::StartVisualGroup

## Description

Declares a visual group in the dialog. Subsequent calls to any "add" method add those elements to this group.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the visual group.

### `pszLabel` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains text, as a null-terminated Unicode string, that appears next to the visual group.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Controls will continue to be added to this visual group until you call [IFileDialogCustomize::EndVisualGroup](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogcustomize-endvisualgroup).

A visual group can be hidden and disabled like any other control, except that doing so affects all of the controls within it. Individual members of the visual group can also be hidden and disabled singly.