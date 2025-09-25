# ChangeDisplaySettingsExW function

## Description

The **ChangeDisplaySettingsEx** function changes the settings of the specified display device to the specified graphics mode.

**Note** Apps that you design to target Windows 8 and later can no longer query or set display modes that are less than 32 bits per pixel (bpp); these operations will fail. These apps have a [compatibility manifest](https://learn.microsoft.com/windows/desktop/Win7AppQual/compatibility---application-manifest) that targets Windows 8. Windows 8 still supports 8-bit and 16-bit color modes for desktop apps that were built without a Windows 8 manifest; Windows 8 emulates these modes but still runs in 32-bit color mode.

## Parameters

### `lpszDeviceName` [in]

A pointer to a null-terminated string that specifies the display device whose graphics mode will change. Only display device names as returned by [EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa) are valid. See **EnumDisplayDevices** for further information on the names associated with these display devices.

The *lpszDeviceName* parameter can be **NULL**. A **NULL** value specifies the default display device. The default device can be determined by calling [EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa) and checking for the DISPLAY_DEVICE_PRIMARY_DEVICE flag.

### `lpDevMode` [in]

A pointer to a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that describes the new graphics mode. If *lpDevMode* is **NULL**, all the values currently in the registry will be used for the display setting. Passing **NULL** for the *lpDevMode* parameter and 0 for the *dwFlags* parameter is the easiest way to return to the default mode after a dynamic mode change.

The **dmSize** member must be initialized to the size, in bytes, of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. The **dmDriverExtra** member must be initialized to indicate the number of bytes of private driver data following the **DEVMODE** structure. In addition, you can use any of the following members of the **DEVMODE** structure.

| Member | Meaning |
| --- | --- |
| **dmBitsPerPel** | Bits per pixel |
| **dmPelsWidth** | Pixel width |
| **dmPelsHeight** | Pixel height |
| **dmDisplayFlags** | Mode flags |
| **dmDisplayFrequency** | Mode frequency |
| **dmPosition** | Position of the device in a multi-monitor configuration. |

In addition to using one or more of the preceding [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) members, you must also set one or more of the following values in the **dmFields** member to change the display settings.

| Value | Meaning |
| --- | --- |
| DM_BITSPERPEL | Use the **dmBitsPerPel** value. |
| DM_PELSWIDTH | Use the **dmPelsWidth** value. |
| DM_PELSHEIGHT | Use the **dmPelsHeight** value. |
| DM_DISPLAYFLAGS | Use the **dmDisplayFlags** value. |
| DM_DISPLAYFREQUENCY | Use the **dmDisplayFrequency** value. |
| DM_POSITION | Use the **dmPosition** value. |

### `hwnd`

Reserved; must be **NULL**.

### `dwflags` [in]

Indicates how the graphics mode should be changed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The graphics mode for the current screen will be changed dynamically. |
| **CDS_FULLSCREEN** | The mode is temporary in nature.<br><br> If you change to and from another desktop, this mode will not be reset. |
| **CDS_GLOBAL** | The settings will be saved in the global settings area so that they will affect all users on the machine. Otherwise, only the settings for the user are modified. This flag is only valid when specified with the CDS_UPDATEREGISTRY flag. |
| **CDS_NORESET** | The settings will be saved in the registry, but will not take effect. This flag is only valid when specified with the CDS_UPDATEREGISTRY flag. |
| **CDS_RESET** | The settings should be changed, even if the requested settings are the same as the current settings. |
| **CDS_SET_PRIMARY** | This device will become the primary device. |
| **CDS_TEST** | The system tests if the requested graphics mode could be set. |
| **CDS_UPDATEREGISTRY** | The graphics mode for the current screen will be changed dynamically and the graphics mode will be updated in the registry. The mode information is stored in the USER profile. |
| **CDS_VIDEOPARAMETERS** | When set, the *lParam* parameter is a pointer to a [VIDEOPARAMETERS](https://learn.microsoft.com/previous-versions/dd145196(v=vs.85)) structure. |
| **CDS_ENABLE_UNSAFE_MODES** | Enables settings changes to unsafe graphics modes. |
| **CDS_DISABLE_UNSAFE_MODES** | Disables settings changes to unsafe graphics modes. |

Specifying CDS_TEST allows an application to determine which graphics modes are actually valid, without causing the system to change to them.

If CDS_UPDATEREGISTRY is specified and it is possible to change the graphics mode dynamically, the information is stored in the registry and DISP_CHANGE_SUCCESSFUL is returned. If it is not possible to change the graphics mode dynamically, the information is stored in the registry and DISP_CHANGE_RESTART is returned.

If CDS_UPDATEREGISTRY is specified and the information could not be stored in the registry, the graphics mode is not changed and DISP_CHANGE_NOTUPDATED is returned.

### `lParam` [in]

If *dwFlags* is **CDS_VIDEOPARAMETERS**, *lParam* is a pointer to a [VIDEOPARAMETERS](https://learn.microsoft.com/previous-versions/dd145196(v=vs.85)) structure. Otherwise *lParam* must be **NULL**.

## Return value

The **ChangeDisplaySettingsEx** function returns one of the following values.

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

To ensure that the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure passed to **ChangeDisplaySettingsEx** is valid and contains only values supported by the display driver, use the **DEVMODE** returned by the [EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa) function.

When adding a display monitor to a multiple-monitor system programmatically, set **DEVMODE.dmFields** to DM_POSITION and specify a position (in **DEVMODE.dmPosition**) for the monitor you are adding that is adjacent to at least one pixel of the display area of an existing monitor. To detach the monitor, set **DEVMODE.dmFields** to DM_POSITION but set **DEVMODE.dmPelsWidth** and **DEVMODE.dmPelsHeight** to zero. For more information, see [Multiple Display Monitors](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors).

When the display mode is changed dynamically, the [WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange) message is sent to all running applications with the following message parameters.

| Parameters | Meaning |
| --- | --- |
| wParam | New bits per pixel |
| LOWORD(lParam) | New pixel width |
| HIWORD(lParam) | New pixel height |

To change the settings for more than one display at the same time, first call **ChangeDisplaySettingsEx** for each device individually to update the registry without applying the changes. Then call **ChangeDisplaySettingsEx** once more, with a **NULL** device, to apply the changes. For example, to change the settings for two displays, do the following:

```cpp

ChangeDisplaySettingsEx (lpszDeviceName1, lpDevMode1, NULL, (CDS_UPDATEREGISTRY | CDS_NORESET), NULL);
ChangeDisplaySettingsEx (lpszDeviceName2, lpDevMode2, NULL, (CDS_UPDATEREGISTRY | CDS_NORESET), NULL);
ChangeDisplaySettingsEx (NULL, NULL, NULL, 0, NULL);

```

### DPI Virtualization

This API does not participate in DPI virtualization. The input given is always in terms of physical pixels, and is not related to the calling context.

> [!NOTE]
> The winuser.h header defines ChangeDisplaySettingsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa)

[EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa)

[VIDEOPARAMETERS](https://learn.microsoft.com/previous-versions/dd145196(v=vs.85))

[WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange)