# InitializePrintMonitor2 function

## Description

A print monitor's **InitializePrintMonitor2** function initializes a print monitor for use with clustered print servers.

## Parameters

### `pMonitorInit` [in]

Caller-supplied pointer to a [MONITORINIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorinit) structure.

### `phMonitor` [out]

Caller-supplied location in which the function returns a monitor handle.

## Return value

If the operation succeeds, the function should return a pointer to a [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure. Otherwise the function should call SetLastError (described in the Microsoft Windows SDK documentation) to set an error code, and return **NULL**.

## Remarks

The **InitializePrintMonitor2** function must be exported by [language monitors](https://learn.microsoft.com/windows-hardware/drivers/print/language-monitors) and by port monitor server DLLs. The function is called immediately after the monitor DLL is loaded, and is not called again until the DLL is reloaded. Its purposes are to allow the monitor to initialize itself, and to provide the spooler with pointers to internal monitor functions. Function pointers are contained in a [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure is larger in Windows XP than it was in Windows 2000. In order to ensure that a monitor developed with the Windows XP Driver Development Kit (DDK) will install on Windows XP and Windows 2000, the monitor must do the following:

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

[MONITORINIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorinit)