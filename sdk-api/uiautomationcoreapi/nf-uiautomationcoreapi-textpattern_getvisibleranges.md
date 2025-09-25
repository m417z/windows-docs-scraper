# TextPattern_GetVisibleRanges function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves an array of disjoint text ranges from a text container where each
text range begins with the first partially visible line through to the end of the
last partially visible line. For example, a multi-column layout where the columns
are partially scrolled out of the visible area of the viewport and the content
flows from the bottom of one column to the top of the next.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

A control pattern object.

### `pRetVal` [out]

Type: **HUIATEXTRANGE***

When this function returns, contains
an array of text ranges spanning the visible text within the text container.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.