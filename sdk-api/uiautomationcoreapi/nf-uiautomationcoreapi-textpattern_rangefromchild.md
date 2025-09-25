# TextPattern_RangeFromChild function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets the text range that a given node spans.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

A control pattern object.

### `hnodeChild` [in]

Type: **HUIANODE**

Reference to a node that the client wants the text range for.

### `pRetVal` [out]

Type: **HUIATEXTRANGE***

When this function returns, contains the text range that the node spans.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

As an example of how this function might be used,
a client can pass in an embedded hyperlink control and receive the range of text that it spans.