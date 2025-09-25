# CapabilitiesRequestAndCapabilitiesReply function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Retrieves a string describing a monitor's capabilities.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

### `pszASCIICapabilitiesString` [out]

Pointer to a buffer that receives the monitor's capabilities string. The caller must allocate this buffer. To get the size of the string, call [GetCapabilitiesStringLength](https://learn.microsoft.com/windows/desktop/api/lowlevelmonitorconfigurationapi/nf-lowlevelmonitorconfigurationapi-getcapabilitiesstringlength). The capabilities string is always an ASCII string. The buffer must include space for the terminating null character.

### `dwCapabilitiesStringLengthInCharacters` [in]

Size of *pszASCIICapabilitiesString* in characters, including the terminating null character.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function corresponds to the "Capabilities Request & Capabilities Reply" command from the Display Data Channel Command Interface (DDC/CI) standard. For more information about the capabilities string, refer to the DDC/CI standard.

This function usually returns quickly, but sometimes it can take several seconds to complete.

You can update a monitor's capabilities string by adding an *AddReg* directive to the monitor's INF file. Add a registry key named "CapabilitiesString" to the monitor's driver key. The value of the registry key is the capabilities string. The registry data type is REG_SZ.

``` syntax
HKR,,"CapabilitiesString",0x00000000,"updated capabilities string"

```

**Warning** Do not modify a monitor's INF file unless you are familiar with the layout of INF files and also understand the DDC/CI standard.

#### Examples

```cpp

DWORD cchStringLength = 0;
BOOL bSuccess = 0;
LPSTR szCapabilitiesString = NULL;

// Get the length of the string.
bSuccess = GetCapabilitiesStringLength(
   hPhysicalMonitor, // Handle to the monitor.
   &cchStringLength
   );

if (bSuccess)
{
    // Allocate the string buffer.
    LPSTR szCapabilitiesString = (LPSTR)malloc(cchStringLength);
    if (szCapabilitiesString != NULL)
    {
        // Get the capabilities string.
        bSuccess = CapabilitiesRequestAndCapabilitiesReply(
            hPhysicalMonitor,
            szCapabilitiesString,
            cchStringLength
            );

        // Free the string buffer.
        free(szCapabilitiesString);
    }
}

```

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)