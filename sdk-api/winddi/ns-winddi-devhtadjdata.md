# DEVHTADJDATA structure

## Description

The DEVHTADJDATA structure is used as input to the [HTUI_DeviceColorAdjustment](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-htui_devicecoloradjustment) function.

## Members

### `DeviceFlags`

Is a set of flags, set by the caller, describing color mixing and color versus gray-scale output. Either, both, or neither of the following flags should be set, as appropriate:

| Flag | Definition |
| --- | --- |
| DEVHTADJF_ADDITIVE_DEVICE | If set, the device uses additive color mixing.<br><br>If not set, the device uses subtractive color mixing. |
| DEVHTADJF_COLOR_DEVICE | If set, the device produces color output.<br><br>If not set, the device produces gray-scaled output. |

### `DeviceXDPI`

Is the caller-supplied horizontal resolution, in dots per inch, for the device.

### `DeviceYDPI`

Is the caller-supplied vertical resolution, in dots per inch, for the device.

### `pDefHTInfo`

Is a caller-supplied pointer to a [DEVHTINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devhtinfo) structure containing the device's default halftoning properties.

### `pAdjHTInfo`

Is a caller-supplied pointer to a DEVHTINFO structure containing the device's current halftoning properties. Before the [HTUI_DeviceColorAdjustment](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-htui_devicecoloradjustment) function returns, it modifies this structure's contents, if the user has adjusted the halftoning properties. Can be **NULL** (see the following Remarks section).

## Remarks

If **pAdjHTInfo** is **NULL**, or if **pAdjHTInfo** and **pDefHTInfo** point to the same buffer, the [HTUI_DeviceColorAdjustment](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-htui_devicecoloradjustment) function displays the halftoning properties supplied by **pDefHTInfo** but does not allow the user to modify them.