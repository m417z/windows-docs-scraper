# SHCOLUMNINFO structure

## Description

Contains information about the properties of a column. It is used by [IColumnProvider::GetColumnInfo](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-icolumnprovider-getcolumninfo).

## Members

### `scid`

Type: **[SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects)**

A [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure that uniquely identifies the column.

### `vt`

Type: **[VARTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms221127(v=vs.85))**

The native [VARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms221127(v=vs.85)) type of the column's data.

### `fmt`

Type: **DWORD**

[List view format](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvcolumna). This member is normally set to LVCFMT_LEFT.

### `cChars`

Type: **UINT**

The default width of the column, in characters.

### `csFlags`

Type: **DWORD**

Flags indicating the default column state. It can be a combination of the following flags.

#### SHCOLSTATE_TYPE_STR

A string.

#### SHCOLSTATE_TYPE_INT

An integer.

#### SHCOLSTATE_TYPE_DATE

A date.

#### SHCOLSTATE_ONBYDEFAULT

Shown by default in Windows Explorer Details view, even if the user has not selected the column. If this flag is set, the column will be displayed for all folders. There is no way to force a column to be displayed on a per-folder basis.

#### SHCOLSTATE_SLOW

Slow to compute. Windows Explorer should retrieve the data asynchronously and do the computation on a background thread.

#### SHCOLSTATE_EXTENDED

Provided by a handler, not the folder object.

#### SHCOLSTATE_SECONDARYUI

Not displayed in the shortcut menu, but listed in the **More...** dialog box.

#### SHCOLSTATE_HIDDEN

Not displayed in the user interface.

### `wszTitle`

Type: **WCHAR[MAX_COLUMN_NAME_LEN]**

A null-terminated Unicode string with the column's title. It must contain no more than MAX_COLUMN_NAME_LEN characters, including the terminating **NULL**.

### `wszDescription`

Type: **WCHAR[MAX_COLUMN_DESC_LEN]**

A null-terminated Unicode string with the column's description. It must contain no more than MAX_COLUMN_DESC_LEN characters, including the terminating **NULL**.

## See also

[IColumnProvider::GetColumnInfo](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-icolumnprovider-getcolumninfo)