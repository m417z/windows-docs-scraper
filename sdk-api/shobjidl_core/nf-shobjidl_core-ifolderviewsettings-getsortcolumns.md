# IFolderViewSettings::GetSortColumns

## Description

Gets sort column information.

## Parameters

### `rgSortColumns` [out]

Type: **[SORTCOLUMN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-sortcolumn)***

A pointer to an array of [SORTCOLUMN](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-sortcolumn) structures.

### `cColumnsIn` [in]

Type: **UINT**

The source column count.

### `pcColumnsOut` [out]

Type: **UINT***

A pointer to the *rgSortColumns* array length.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.