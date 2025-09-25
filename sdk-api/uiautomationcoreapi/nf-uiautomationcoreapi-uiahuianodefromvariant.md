# UiaHUiaNodeFromVariant function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets an HUIANODE from a [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) type.

## Parameters

### `pvar` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)***

The node.

### `phnode` [out]

Type: **HUIANODE***

The address of a variable that receives the HUIANODE.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.