# DISPLAYCONFIG_PATH_INFO structure

## Description

The DISPLAYCONFIG_PATH_INFO structure is used to describe a single path from a target to a source.

## Members

### `sourceInfo`

A [DISPLAYCONFIG_PATH_SOURCE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_source_info) structure that contains the source information for the path.

### `targetInfo`

A [DISPLAYCONFIG_PATH_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_target_info) structure that contains the target information for the path.

### `flags`

A bitwise OR of flag values that indicates the state of the path. The following values are supported:

| Value | Meaning |
| --- | --- |
| **DISPLAYCONFIG_PATH_ACTIVE**<br><br>0x00000001 | Set by [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) to indicate that the path is active and part of the desktop. If this flag value is set, [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig) attempts to enable this path. |
| **DISPLAYCONFIG_PATH_SUPPORT_VIRTUAL_MODE**<br><br>0x00000008 | Set by [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) to indicate that the path supports virtual modes. This flag is for reporting only and cannot be modified.<br><br>Supported starting in Windows 10. |
| **DISPLAYCONFIG_PATH_BOOST_REFRESH_RATE**<br><br>0x00000010 | Set by [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) to indicate that the path is configured to automatically boost the refresh rate between the virtual refresh rate and the physical refresh rate (this is known as "Dynamic refresh rate"). This value can be set or removed for a path by [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig). The virtual refresh rate is set by [DISPLAYCONFIG_PATH_TARGET_INFO.refreshRate](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_path_target_info) and the physical refresh rate is selected by [DISPLAYCONFIG_TARGET_MODE.targetVideoSignalInfo](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_target_mode).<br><br>Supported starting in Windows 11. |

## See also

[DISPLAYCONFIG_PATH_SOURCE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_source_info)

[DISPLAYCONFIG_PATH_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_target_info)

[QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig)

[SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig)