# UiaGetErrorDescription function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets an error string so that it can be passed to the client.
This method is not used directly by clients.

## Parameters

### `pDescription` [out]

Type: **BSTR***

The address of a variable that receives the description of the error. This parameter is passed uninitialized.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if an error description can be reported; otherwise **FALSE**.