# IShellFolder2::MapColumnToSCID

## Description

Converts a column to the appropriate property set ID (FMTID) and property ID (PID).

## Parameters

### `iColumn` [in]

Type: **UINT**

The column ID.

### `pscid` [out]

Type: **[SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects)***

A pointer to an [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure containing the FMTID and PID.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.