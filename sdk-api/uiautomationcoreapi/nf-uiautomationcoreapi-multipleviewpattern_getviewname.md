# MultipleViewPattern_GetViewName function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves the name of a control-specific view.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The *control pattern* object.

### `viewId` [in]

Type: **int**

The integer identifier for the view.

### `ppStr` [out]

Type: **BSTR***

When this function returns, contains a pointer to the string containing the name of the view.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.