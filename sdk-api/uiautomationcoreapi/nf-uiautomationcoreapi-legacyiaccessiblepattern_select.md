# LegacyIAccessiblePattern_Select function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Performs a Microsoft Active Accessibility selection.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The *control pattern* object.

### `flagsSelect` [in]

Type: **long**

Specifies which selection or focus operations are to be performed. This parameter must have a combination of the values described in [SELFLAG Constants](https://learn.microsoft.com/windows/desktop/WinAuto/selflag).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.