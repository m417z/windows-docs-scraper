# TextRange_GetBoundingRectangles function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves the minimum number of bounding rectangles that can enclose the range, one rectangle per line.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `pRetVal` [out]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

When this function returns, contains
an array of rectangle coordinates for the lines of text that the range spans.
This parameter is passed uninitialized.
The SAFEARRAY contains VARIANTs of type VT_I4.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.