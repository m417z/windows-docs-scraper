# TextRange_GetEnclosingElement function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Returns the node for the next smallest provider that covers the range.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `pRetVal` [out]

Type: **HUIANODE***

When this function returns, contains
the node for the next smallest element that encloses the range.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The enclosing element is typically the text provider that supplies the text range. However,
if the text provider supports child elements such as tables or hyperlinks,
the enclosing element could be a descendant of the text provider.