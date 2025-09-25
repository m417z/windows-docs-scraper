# DrvGetModes function

## Description

The **DrvGetModes** function lists the modes supported by a given device.

## Parameters

### `hDriver` [in]

Handle to the driver for which the modes must be enumerated. This is the handle passed in the *hDriver* parameter of the [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) function.

### `cjSize`

Specifies the size in bytes of the buffer pointed to by *pdm*.

### `pdm` [out, optional]

Pointer to the buffer containing [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure(s) for the driver to fill in, or **NULL**.

## Return value

The driver should return the number of bytes written to the buffer if *pdm* is not **NULL**. If *pdm* is **NULL**, the driver should return the number of bytes required to hold all mode data. The driver should return zero if an error occurs.

## Remarks

This function must be implemented in all display drivers.

Window Manager dynamically loads all display drivers associated with a miniport driver (based on the **InstalledDisplayDrivers** key in the registry). Each display driver is called to retrieve the list of modes supported by that combination of loaded drivers. For example, the VGA64K display driver only returns the 64K color modes that were returned in the list of modes obtained from the miniport driver.

**DrvGetModes** can be called before there is an active PDEV.

Refer to the *Permedia* samples to see a working implementation of **DrvGetModes**.

**Note** The Microsoft Windows Driver Kit (WDK) does not contain the 3Dlabs Permedia2 (*3dlabs.htm* ) and 3Dlabs Permedia3 (*Perm3.htm*) sample display drivers. You can get these sample drivers from the Windows Server 2003 SP1 Driver Development Kit (DDK), which you can download from the [DDK - Windows Driver Development Kit](https://learn.microsoft.com/windows-hardware/drivers/devtest/) page of the WDHC website.

## See also

[DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

[DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngDeviceIoControl](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeviceiocontrol)