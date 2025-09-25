# UiaHPatternObjectFromVariant function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets a control pattern object from a [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) type.

## Parameters

### `pvar` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)***

The pattern.

### `phobj` [out]

Type: **HUIAPATTERNOBJECT ***

The address of a variable that receives the control pattern object.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.