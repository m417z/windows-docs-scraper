# GridPattern_GetItem function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets the node for an item in a grid.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The *control pattern* object.

### `row` [in]

Type: **int**

The row of the node being requested.

### `column` [in]

Type: **int**

The column of the node being requested.

### `pResult` [out]

Type: **HUIANODE***

When this function returns, contains a pointer to the node for the cell
at the specified location. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

Row 0, column 0 is the first item in a grid.