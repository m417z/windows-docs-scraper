# GetVCPFeatureAndVCPFeatureReply function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Retrieves the current value, maximum value, and code type of a Virtual Control Panel (VCP) code for a monitor.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

### `bVCPCode` [in]

VCP code to query. The VCP codes are Include the VESA Monitor Control Command Set (MCCS) standard, versions 1.0 and 2.0. This parameter must specify a continuous or non-continuous VCP, or a vendor-specific code. It should not be a table control code.

### `pvct` [out]

Receives the VCP code type, as a member of the [MC_VCP_CODE_TYPE](https://learn.microsoft.com/windows/win32/api/lowlevelmonitorconfigurationapi/ne-lowlevelmonitorconfigurationapi-mc_vcp_code_type) enumeration. This parameter can be **NULL**.

### `pdwCurrentValue` [out]

Receives the current value of the VCP code. This parameter can be **NULL**.

### `pdwMaximumValue` [out]

If *bVCPCode* specifies a continuous VCP code, this parameter receives the maximum value of the VCP code. If *bVCPCode* specifies a non-continuous VCP code, the value received in this parameter is undefined. This parameter can be **NULL**.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function corresponds to the "Get VCP Feature & VCP Feature Reply" command from the Display Data Channel Command Interface (DDC/CI) standard. Vendor-specific VCP codes can be used with this function.

This function takes about 40 milliseconds to return.

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)