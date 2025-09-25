# IShellFolder2::GetDefaultColumnState

## Description

Gets the default state for a specified column.

## Parameters

### `iColumn` [in]

Type: **UINT**

An integer that specifies the column number.

### `pcsFlags` [out]

Type: **SHCOLSTATEF***

A pointer to a value that contains flags that indicate the default column state. This parameter can include a combination of the following flags.

#### SHCOLSTATE_TYPE_STR

A string.

#### SHCOLSTATE_TYPE_INT

An integer.

#### SHCOLSTATE_TYPE_DATE

A date.

#### SHCOLSTATE_ONBYDEFAULT

Should be shown by default in the Windows Explorer Details view.

#### SHCOLSTATE_SLOW

Recommends that the folder view extract column information asynchronously, on a background thread, because extracting this information can be time consuming.

#### SHCOLSTATE_EXTENDED

Provided by a handler, not the folder object.

#### SHCOLSTATE_SECONDARYUI

Not displayed in the shortcut menu, but listed in the More dialog box.

#### SHCOLSTATE_HIDDEN

Not displayed in the user interface.

#### SHCOLSTATE_PREFER_VARCMP

Uses default sorting rather than [CompareIDs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-compareids) to get the sort order.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.