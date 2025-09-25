# ChangeDisplaySettingsW function

## Description

The **ChangeDisplaySettings** function changes the settings of the default display device to the specified graphics mode.

To change the settings of a specified display device, use the [ChangeDisplaySettingsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsexa) function.

**Note** Apps that you design to target Windows 8 and later can no longer query or set display modes that are less than 32 bits per pixel (bpp); these operations will fail. These apps have a [compatibility manifest](https://learn.microsoft.com/windows/desktop/Win7AppQual/compatibility---application-manifest) that targets Windows 8. Windows 8 still supports 8-bit and 16-bit color modes for desktop apps that were built without a Windows 8 manifest; Windows 8 emulates these modes but still runs in 32-bit color mode.

## Parameters

### `lpDevMode` [in]

A pointer to a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that describes the new graphics mode. If *lpDevMode* is **NULL**, all the values currently in the registry will be used for the display setting. Passing **NULL** for the *lpDevMode* parameter and 0 for the *dwFlags* parameter is the easiest way to return to the default mode after a dynamic mode change.

The **dmSize** member of [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) must be initialized to the size, in bytes, of the **DEVMODE** structure. The **dmDriverExtra** member of **DEVMODE** must be initialized to indicate the number of bytes of private driver data following the **DEVMODE** structure. In addition, you can use any or all of the following members of the **DEVMODE** structure.

| Member | Meaning |
| --- | --- |
| **dmBitsPerPel** | Bits per pixel |
| **dmPelsWidth** | Pixel width |
| **dmPelsHeight** | Pixel height |
| **dmDisplayFlags** | Mode flags |
| **dmDisplayFrequency** | Mode frequency |
| **dmPosition** | Position of the device in a multi-monitor configuration. |

In addition to using one or more of the preceding [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) members, you must also set one or more of the following values in the **dmFields** member to change the display setting.

| Value | Meaning |
| --- | --- |
| DM_BITSPERPEL | Use the **dmBitsPerPel** value. |
| DM_PELSWIDTH | Use the **dmPelsWidth** value. |
| DM_PELSHEIGHT | Use the **dmPelsHeight** value. |
| DM_DISPLAYFLAGS | Use the **dmDisplayFlags** value. |
| DM_DISPLAYFREQUENCY | Use the **dmDisplayFrequency** value. |
| DM_POSITION | Use the **dmPosition** value. |

### `dwFlags` [in]

Indicates how the graphics mode should be changed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The graphics mode for the current screen will be changed dynamically. |
| **CDS_FULLSCREEN** | The mode is temporary in nature.<br><br> If you change to and from another desktop, this mode will not be reset. |
| **CDS_GLOBAL** | The settings will be saved in the global settings area so that they will affect all users on the machine. Otherwise, only the settings for the user are modified. This flag is only valid when specified with the CDS_UPDATEREGISTRY flag. |
| **CDS_NORESET** | The settings will be saved in the registry, but will not take effect. This flag is only valid when specified with the CDS_UPDATEREGISTRY flag. |
| **CDS_RESET** | The settings should be changed, even if the requested settings are the same as the current settings. |
| **CDS_SET_PRIMARY** | This device will become the primary device. |
| **CDS_TEST** | The system tests if the requested graphics mode could be set. |
| **CDS_UPDATEREGISTRY** | The graphics mode for the current screen will be changed dynamically and the graphics mode will be updated in the registry. The mode information is stored in the USER profile. |

Specifying CDS_TEST allows an application to determine which graphics modes are actually valid, without causing the system to change to that graphics mode.

If CDS_UPDATEREGISTRY is specified and it is possible to change the graphics mode dynamically, the information is stored in the registry and DISP_CHANGE_SUCCESSFUL is returned. If it is not possible to change the graphics mode dynamically, the information is stored in the registry and DISP_CHANGE_RESTART is returned.

If CDS_UPDATEREGISTRY is specified and the information could not be stored in the registry, the graphics mode is not changed and DISP_CHANGE_NOTUPDATED is returned.

## Return value

The **ChangeDisplaySettings** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **DISP_CHANGE_SUCCESSFUL** | The settings change was successful. |
| **DISP_CHANGE_BADDUALVIEW** | The settings change was unsuccessful because the system is DualView capable. |
| **DISP_CHANGE_BADFLAGS** | An invalid set of flags was passed in. |
| **DISP_CHANGE_BADMODE** | The graphics mode is not supported. |
| **DISP_CHANGE_BADPARAM** | An invalid parameter was passed in. This can include an invalid flag or combination of flags. |
| **DISP_CHANGE_FAILED** | The display driver failed the specified graphics mode. |
| **DISP_CHANGE_NOTUPDATED** | Unable to write settings to the registry. |
| **DISP_CHANGE_RESTART** | The computer must be restarted for the graphics mode to work. |

## Remarks

To ensure that the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure passed to **ChangeDisplaySettings** is valid and contains only values supported by the display driver, use the **DEVMODE** returned by the [EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa) function.

When the display mode is changed dynamically, the [WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange) message is sent to all running applications with the following message parameters.

| Parameters | Meaning |
| --- | --- |
| wParam | New bits per pixel |
| LOWORD(lParam) | New pixel width |
| HIWORD(lParam) | New pixel height |

### DPI Virtualization

This API does not participate in DPI virtualization. The input given is always in terms of physical pixels, and is not related to the calling context.

> [!NOTE]
> The winuser.h header defines ChangeDisplaySettings as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeDisplaySettingsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsexa)

[CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa)

[EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa)

[WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange)