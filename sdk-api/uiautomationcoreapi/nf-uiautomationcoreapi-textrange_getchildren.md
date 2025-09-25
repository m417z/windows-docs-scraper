# TextRange_GetChildren function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Returns all UI Automation elements contained within the specified text range.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `pRetVal` [out]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

When this function returns, contains
an array of nodes that are children of the text range in the UI Automation tree.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.