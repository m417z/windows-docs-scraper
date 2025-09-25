# TextRange_FindAttribute function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Searches in a specified direction for the first piece of text supporting a specified text attribute.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

The text range to search.

### `attributeId` [in]

Type: **TEXTATTRIBUTEID**

The text attribute to search for. For a list of text attribute IDs, see [Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids).

### `val` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)**

The value of the attribute that the client wants to find.

### `backward` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to search backward, otherwise **FALSE**.

### `pRetVal` [out]

Type: **HUITEXTRANGE***

When this function returns, contains
the first matching text range.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.