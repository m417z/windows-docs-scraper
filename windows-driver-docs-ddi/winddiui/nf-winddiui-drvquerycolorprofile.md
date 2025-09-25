## Description

The **DrvQueryColorProfile** function allows a printer interface DLL to specify an ICC profile to use for color management.

## Parameters

### `hPrinter`

Caller-supplied printer handle.

### `pdevmode` [in]

Caller-supplied pointer to a [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

### `ulQueryMode`

One of the following caller-supplied bit flags, indicating the type of profile to be specified.

| Flag | Definition |
|---|---|
| QCP_DEVICEPROFILE | The caller is requesting a device profile. |
| QCP_SOURCEPROFILE | The caller is requesting a source profile. |

### `pvProfileData` [out]

Caller-supplied pointer to a buffer to receive profile information.

### `pcbProfileData` [out]

Caller-supplied pointer to a value representing the size, in bytes, of the buffer pointed to by **pvProfileData**.

### `pflProfileData` [out]

One of the following function-supplied bit flags, indicating the type of information the function is returning.

| Flag | Definition |
|---|---|
| QCP_PROFILEDISK | The function is returning the file name of an ICC profile in the buffer pointed to by *pvProfileData*. |
| QCP_PROFILEMEMORY | The function is returning profile data in the buffer pointed to by *pvProfileData*. |

## Return value

If the operation succeeds, the function returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

A [printer interface DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-interface-dll) can optionally provide a **DrvQueryColorProfile** function. If the function is provided, GDI calls it if ICM has been enabled for a print job. The function's purpose is to determine and specify an ICC profile that is appropriate for use with the print job.

If a driver's printer interface DLL does not provide a **DrvQueryColorProfile** function, or if the function returns **FALSE**, GDI attempts to find a profile. For more information, see [Locating ICC Profiles](https://learn.microsoft.com/windows-hardware/drivers/print/locating-icc-profiles).

If the output buffer size specified by **pcbProfileData** is too small, the driver should overwrite the size value supplied by **pcbProfileData** with the required buffer size, call SetLastError(ERROR_INSUFFICIENT_BUFFER), and return **FALSE**.