# EngGetDriverName function

## Description

The **EngGetDriverName** function returns the name of the driver's DLL.

## Parameters

### `hdev` [in]

Handle to the device. This is the GDI handle received by the driver as the *hdev* parameter for [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev).

## Return value

**EngGetDriverName** returns a pointer to the null-terminated string buffer in which the name of the driver's DLL is specified. The system obtains and stores the driver's name from the DRIVER_INFO_2 structure when the driver is first installed through the Win32 **AddPrinterDriver** routine.

## See also

[EngGetPrinterDataFileName](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetprinterdatafilename)