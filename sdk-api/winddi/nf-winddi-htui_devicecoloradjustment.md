# HTUI_DeviceColorAdjustment function

## Description

The **HTUI_DeviceColorAdjustment** function can be used by graphics device drivers to display a dialog box that allows a user to adjust a device's halftoning properties.

## Parameters

### `pDeviceName` [in, optional]

Caller-supplied pointer to a NULL-terminated string representing a displayable device name.

### `pDevHTAdjData` [in]

Caller-supplied pointer to a [DEVHTADJDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devhtadjdata) structure.

## Return value

The function returns the following values:

| Return code | Description |
| --- | --- |
| **Greater than 0** | The user chose the dialog box's **OK** button. |
| **0** | The user chose the dialog box's **Cancel** button. |
| **Less than 0** | An error occurred. |

## Remarks

A graphics driver interface, such as a printer interface DLL, can call the **HTUI_DeviceColorAdjustment** function to display a dialog box that allows a user to view and modify the device's halftoning properties. Depending on member values specified for the [DEVHTADJDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devhtadjdata) structure, the function will either enable the dialog box for user modification or just display caller-specified default values. If user modification is allowed, the function returns the modified parameters to the caller (using the DEVHTAJDATA structure), so the driver can pass them to the device.

## See also

[DEVHTADJDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devhtadjdata)