# SerialDisplayAdvancedSettings function

## Description

**SerialDisplayAdvancedSettings** displays the system-supplied advanced settings dialog box for a specified COM port device.

## Parameters

### `ParentHwnd` [in]

Handle to the parent window for the advanced settings dialog box.

### `DeviceInfoSet` [in]

Specifies the device information set that includes the device instance specified by *DeviceInfoData*.

### `DeviceInfoData` [in]

Pointer to the device instance in the specified device information set. The routine displays the advanced settings dialog box for this device.

## Return value

**SerialDisplayAdvancedSettings** returns one of the following status values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The advanced settings dialog box was successfully displayed. |
| **ERROR_INVALID_PARAMETER** | One of the following occurred: The specified device information set is not valid. |
| **ERROR_ACCESS_DENIED** | The routine could not open the specified device's hardware registry key. |
| **ERROR_INVALID_DATA** | The name of the port is not valid. |
| **ERROR_ACCESS_DENIED** | The routine could not display the dialog box. |

## Remarks

**SerialDisplayAdvancedSettings** displays the system-supplied advanced settings dialog box for a specified device. If you supply a custom dialog box, this routine displays it; otherwise, the routine displays the default dialog box.

**SerialDisplayAdvancedSettings** runs in user mode.

For more information, see [Installing an Advanced Properties Page for a COM Port](https://learn.microsoft.com/previous-versions/ff546508(v=vs.85)).

## See also

[PPORT_ADVANCED_DIALOG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546956(v=vs.85))