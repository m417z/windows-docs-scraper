## Description

The print spooler's **IsValidDevmode** function verifies that the contents of a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure are valid.

## Parameters

### `pDevmode` [in, optional]

Pointer to the DEVMODE structure to be validated.

### `DevmodeSize`

Size, in bytes, of the buffer pointed to by *pDevmode*.

## Return value

If the DEVMODE structure is valid, or if the function succeeds in repairing the structure to make it valid, the function returns **TRUE**. Otherwise, the function returns **FALSE**. The caller can obtain an error code by calling **GetLastError**.

## Remarks

Before using a DEVMODE structure obtained from a possibly unreliable source, a printer driver can call this function to verify that the structure is valid. This function validates only the public members of the DEVMODE structure. It does not check the private members of the structure.

The **dmSize** member of the DEVMODE structure specifies the size of the DEVMODE structure, not including any private, driver-specified data appended to the structure. The **dmDriverExtra** member specifies the size of the private data appended to the structure, if there is any. Callers should set *DevModeSize* to **dmSize**+**dmDriverExtra** only if they can guarantee that the input buffer size is at least that large.

This function does not require the caller to obtain elevated privileges.

## See also

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)