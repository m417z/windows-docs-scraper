# TextPattern_get_SupportedTextSelection function

## Description

> [!Important]
> This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Ascertains whether the text container's contents can be selected and deselected.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

A control pattern object.

### `pRetVal` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

When this function returns, contains a value indicating whether the text container can have its contents selected and deselected.

This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.