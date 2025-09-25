# TextRange_GetAttributeValue function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets the value of a text attribute for a text range.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `attributeId` [in]

Type: **TEXTATTRIBUTEID**

The text attribute whose value is wanted. For a list of text attribute IDs, see [Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids).

### `pRetVal` [out]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)***

When this function returns, contains
the value of the attribute for the text range.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.