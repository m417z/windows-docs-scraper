# EngGetPrinterDataFileName function

## Description

The **EngGetPrinterDataFileName** function retrieves the string name of the printer's data file.

## Parameters

### `hdev` [in]

Handle to the device. This is the GDI handle received by the driver as the *hdev* parameter for [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev).

## Return value

**EngGetPrinterDataFileName** returns a pointer to the null-terminated string buffer in which the name of the printer's data file is specified. The system obtains and stores the printer's data file name from the DRIVER_INFO_2 structure (described in the Microsoft Windows SDK documentation) when the driver is first installed through the Microsoft Win32 **AddPrinterDriver** routine.

## See also

[EngGetDriverName](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetdrivername)