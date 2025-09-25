# TextRange_ExpandToEnclosingUnit function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Expands the text range to a larger or smaller unit such as Character, Word, Line, or Page.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `unit` [in]

Type: **[TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit)**

The unit that the provider must expand the text range to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

If the range is already an integral number of the specified units, it remains unchanged.

If the starting endpoint is not at a [TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit) boundary, it is moved backward until it is at a boundary.
Subsequently, if the ending endpoint is not at a boundary, or if it is at the same boundary as the starting endpoint,
the ending endpoint is moved forward until it is at a boundary.

**Note** It is common for a screen reader to read out a full word, entire paragraph, and so on,
at the insertion point or any virtual cursor position.

**TextRange_ExpandToEnclosingUnit** respects both hidden and visible text. The UI Automationclient can check the is-hidden attribute (Text_IsHidden_Attribute_GUID) for text visibility.

**TextRange_ExpandToEnclosingUnit** defaults up to the next supported [TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit) if the given **TextUnit** is not supported by the control.