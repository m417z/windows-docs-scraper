## Description

The MONITOR2 structure contains pointers to the functions defined by print monitors.

## Members

### `cbSize`

Specifies the size, in bytes, of the MONITOR2 structure.

### `pfnEnumPorts`

A port monitor server DLL's [EnumPorts](https://learn.microsoft.com/windows/win32/printdocs/enumports) function enumerates the ports that the port monitor supports.

### `pfnOpenPort`

Pointer to the print monitor's [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) function.

### `pfnOpenPortEx`

A language monitor's [OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85)) function opens a printer port.

### `pfnStartDocPort`

A print monitor's [StartDocPort](https://learn.microsoft.com/previous-versions/ff562710(v=vs.85)) function performs the tasks required to start a print job on the specified port.

### `pfnWritePort`

Pointer to the print monitor's [WritePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-writeport) function.

### `pfnReadPort`

Pointer to the print monitor's [ReadPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-readport) function.

### `pfnEndDocPort`

A print monitor's [EndDocPort](https://learn.microsoft.com/previous-versions/ff548742(v=vs.85)) function performs the tasks required to end a print job on the specified port.

### `pfnClosePort`

Pointer to the print monitor's [ClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-closeport) function.

### `pfnAddPort`

> [!CAUTION]
> The [AddPort](https://learn.microsoft.com/previous-versions/ff545022(v=vs.85)) function is obsolete and should not be used.

**AddPort** creates a port and adds it to the list of ports currently supported by the specified monitor in the spooler environment.

### `pfnAddPortEx`

(Obsolete. Must be NULL.) Pointer to the print monitor's [AddPortEx](https://learn.microsoft.com/previous-versions/ff545025(v=vs.85)) function. (Port monitors only.)

### `pfnConfigurePort`

> [!CAUTION]
> The [ConfigurePort](https://learn.microsoft.com/previous-versions/ff546286(v=vs.85)) function is obsolete and should not be used. Use [ConfigurePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-configureportui) instead.

**ConfigurePort** is a port management function that configures the specified port.

### `pfnDeletePort`

> [!CAUTION]
> The [DeletePort](https://learn.microsoft.com/windows/win32/printdocs/deleteport) function is obsolete and should not be used.

**DeletePort** deletes a port from the monitor's environment.

### `pfnGetPrinterDataFromPort`

Pointer to the print monitor's [GetPrinterDataFromPort](https://learn.microsoft.com/previous-versions/ff550506(v=vs.85)) function.

### `pfnSetPortTimeOuts`

A port monitor server DLL's [SetPortTimeOuts](https://learn.microsoft.com/previous-versions/ff562630(v=vs.85)) function sets port time-out values for an open port.

### `pfnXcvOpenPort`

Pointer to the print monitor's [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport) function. (Port monitors only.)

### `pfnXcvDataPort`

Pointer to the print monitor's [XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport) function. (Port monitors only.)

### `pfnXcvClosePort`

Pointer to the print monitor's [XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport) function. (Port monitors only.)

### `pfnShutdown`

Pointer to the print monitor's [Shutdown](https://learn.microsoft.com/previous-versions/ff562646(v=vs.85)) function.

### `pfnSendRecvBidiDataFromPort`

Pointer to the print monitor's [SendRecvBidiDataFromPort](https://learn.microsoft.com/previous-versions/ff562071(v=vs.85)) function.

### `pfnNotifyUsedPorts`

Pointer to the print monitor's **NotifyUsedPorts** function.

### `pfnNotifyUnusedPorts`

Pointer to the print monitor's **NotifyUnusedPorts** function.

### `pfnPowerEvent`

Pointer to the print monitor's **PowerEvent** function.

## Remarks

Each language monitor and each port monitor server DLL must provide a MONITOR2 structure. The monitor must supply values for all structure members, and specify the structure's address as the return value for its [InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2) function.

If a function is not defined, its pointer must be NULL.

The **MONITOR2** structure is larger in Windows XP than it was in Windows 2000. In order to ensure that a monitor developed with the Windows XP Driver Development Kit (DDK) will install on Windows XP and Windows 2000, the monitor must do the following:

- Perform a run-time check to determine which operating system version the monitor is running on.
- If the monitor is running on Windows 2000, it must set the **cbSize** member of the MONITOR2 structure to MONITOR2_SIZE_WIN2K (defined in Winsplp.h), the size appropriate for Windows 2000 version of this structure.

The following function determines whether the current operating system version is Windows 2000.

```cpp
BOOL  Is_Win2000()
{
  OSVERSIONINFOEX osvi;
  DWORDLONG dwlConditionMask = 0;

  // Initialize the OSVERSIONINFOEX structure.

  ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
  osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  osvi.dwMajorVersion = 5;
  osvi.dwMinorVersion = 0;

  // Initialize the condition mask.
  VER_SET_CONDITION( dwlConditionMask, VER_MAJORVERSION, VER_EQUAL );
  VER_SET_CONDITION( dwlConditionMask, VER_MINORVERSION, VER_EQUAL );

  // Perform the test.
  return VerifyVersionInfo(
      &osvi,
      VER_MAJORVERSION | VER_MINORVERSION,
      dwlConditionMask);
}
```

For a monitor that is loading on Windows 2000, the following code sets the MONITOR2 structure's **cbSize** member appropriately.

```cpp
if ( Is_Win2000( ) )
    Monitor2.cbSize = MONITOR2_SIZE_WIN2K;
```

## See also

[InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2)

[**MONITORUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorui)