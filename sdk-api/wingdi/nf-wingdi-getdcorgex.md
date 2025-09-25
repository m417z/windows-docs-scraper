# GetDCOrgEx function

## Description

The **GetDCOrgEx** function retrieves the final translation origin for a specified device context (DC). The final translation origin specifies an offset that the system uses to translate device coordinates into client coordinates (for coordinates in an application's window).

## Parameters

### `hdc` [in]

A handle to the DC whose final translation origin is to be retrieved.

### `lppt` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the final translation origin, in device coordinates.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The final translation origin is relative to the physical origin of the screen.

## See also

[CreateIC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createica)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)