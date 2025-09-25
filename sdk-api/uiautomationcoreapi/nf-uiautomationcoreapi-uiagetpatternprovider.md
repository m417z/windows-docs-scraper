# UiaGetPatternProvider function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves a *control pattern*.

## Parameters

### `hnode` [in]

Type: **HUIANODE**

The element that implements the pattern.

### `patternId` [in]

Type: **PATTERNID**

The identifier of the control pattern being requested. For a list of control pattern IDs, see [Control Pattern Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpattern-ids).

### `phobj` [out]

Type: **HPATTERNOBJECT***

The address of a variable that receives a handle to the control pattern.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.