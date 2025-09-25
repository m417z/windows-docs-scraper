# DrawDibTime function

## Description

The **DrawDibTime** function retrieves timing information about the drawing operation and is used during debug operations.

## Parameters

### `hdd`

Handle to a DrawDib DC.

### `lpddtime`

Pointer to a [DRAWDIBTIME](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-drawdibtime) structure.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

This function is present only in the debug version of the Microsoft Windows Software Development Kit (SDK) libraries.

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)