# EnumDisplaySettingsExA function

## Description

The **EnumDisplaySettingsEx** function retrieves information about one of the graphics modes for a display device. To retrieve information for all the graphics modes for a display device, make a series of calls to this function.

This function differs from [EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa) in that there is a *dwFlags* parameter.

**Note** Apps that you design to target Windows 8 and later can no longer query or set display modes that are less than 32 bits per pixel (bpp); these operations will fail. These apps have a [compatibility manifest](https://learn.microsoft.com/windows/desktop/Win7AppQual/compatibility---application-manifest) that targets Windows 8. Windows 8 still supports 8-bit and 16-bit color modes for desktop apps that were built without a Windows 8 manifest; Windows 8 emulates these modes but still runs in 32-bit color mode.

## Parameters

### `lpszDeviceName` [in]

A pointer to a null-terminated string that specifies the display device about which graphics mode the function will obtain information.

This parameter is either **NULL** or a [DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea).**DeviceName** returned from [EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa). A **NULL** value specifies the current display device on the computer that the calling thread is running on.

### `iModeNum` [in]

Indicates the type of information to be retrieved. This value can be a graphics mode index or one of the following values.

| Value | Meaning |
| --- | --- |
| **ENUM_CURRENT_SETTINGS** | Retrieve the current settings for the display device. |
| **ENUM_REGISTRY_SETTINGS** | Retrieve the settings for the display device that are currently stored in the registry. |

Graphics mode indexes start at zero. To obtain information for all of a display device's graphics modes, make a series of calls to **EnumDisplaySettingsEx**, as follows: Set *iModeNum* to zero for the first call, and increment *iModeNum* by one for each subsequent call. Continue calling the function until the return value is zero.

When you call **EnumDisplaySettingsEx** with *iModeNum* set to zero, the operating system initializes and caches information about the display device. When you call **EnumDisplaySettingsEx** with *iModeNum* set to a nonzero value, the function returns the information that was cached the last time the function was called with *iModeNum* set to zero.

### `lpDevMode` [out]

A pointer to a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure into which the function stores information about the specified graphics mode. Before calling **EnumDisplaySettingsEx**, set the **dmSize** member to **sizeof** ([DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)), and set the **dmDriverExtra** member to indicate the size, in bytes, of the additional space available to receive private driver data.

The **EnumDisplaySettingsEx** function will populate the **dmFields** member of the **lpDevMode** and one or more other members of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. To determine which members were set by the call to **EnumDisplaySettingsEx**, inspect the *dmFields* bitmask. Some of the fields typically populated by this function include:

* **dmBitsPerPel**
* **dmPelsWidth**
* **dmPelsHeight**
* **dmDisplayFlags**
* **dmDisplayFrequency**
* **dmPosition**
* **dmDisplayOrientation**

### `dwFlags` [in]

This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **EDS_RAWMODE** | If set, the function will return all graphics modes reported by the adapter driver, regardless of monitor capabilities. Otherwise, it will only return modes that are compatible with current monitors. |
| **EDS_ROTATEDMODE** | If set, the function will return graphics modes in all orientations. Otherwise, it will only return modes that have the same orientation as the one currently set for the requested display. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The function fails if *iModeNum* is greater than the index of the display device's last graphics mode. As noted in the description of the *iModeNum* parameter, you can use this behavior to enumerate all of a display device's graphics modes.

### DPI Virtualization

This API does not participate in DPI virtualization. The output given is always in terms of physical pixels, and is not related to the calling context.

> [!NOTE]
> The winuser.h header defines EnumDisplaySettingsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa)

[ChangeDisplaySettingsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsexa)

[CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DISPLAY_DEVICE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-display_devicea)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa)

[EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa)