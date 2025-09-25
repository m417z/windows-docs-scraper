# IActiveDesktop::ModifyDesktopItem

## Description

Modifies the desktop item.

## Parameters

### `pcomp` [in, out]

Type: **LPCCOMPONENT**

The address of the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure that contains the modifications. The desktop item associated with the **wszSource** member of the structure will be modified.

### `dwFlags`

Type: **DWORD**

An unsigned long integer value containing the flags used for the modification. This can be one of the following values.

#### COMP_ELEM_ALL

#### COMP_ELEM_CHECKED

#### COMP_ELEM_CURITEMSTATE

#### COMP_ELEM_FRIENDLYNAME

#### COMP_ELEM_NOSCROLL

#### COMP_ELEM_ORIGINAL_CSI

#### COMP_ELEM_POS_LEFT

#### COMP_ELEM_POS_TOP

#### COMP_ELEM_POS_ZINDEX

#### COMP_ELEM_RESTORED_CSI

#### COMP_ELEM_SIZE_HEIGHT

#### COMP_ELEM_SIZE_WIDTH

#### COMP_ELEM_SOURCE

#### COMP_ELEM_TYPE

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The client application must call [IActiveDesktop::ApplyChanges](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-applychanges) separately to update the registry. For example, to change the friendly name, first call this function with either **COMP_ELEM_FRIENDLYNAME** or **COMP_ELEM_ALL** in the **dwFlags** member of [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component). Then call **IActiveDesktop::ApplyChanges**.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)