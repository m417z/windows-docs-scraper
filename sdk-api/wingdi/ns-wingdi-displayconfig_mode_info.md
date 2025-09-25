## Description

The DISPLAYCONFIG_MODE_INFO structure contains either source mode or target mode information.

## Members

### `infoType`

A value that indicates whether the **DISPLAYCONFIG_MODE_INFO** structure represents source or target mode information. If **infoType** is DISPLAYCONFIG_MODE_INFO_TYPE_TARGET, the *targetMode* parameter value contains a valid DISPLAYCONFIG_TARGET_MODE structure describing the specified target. If **infoType** is DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE, the *sourceMode* parameter value contains a valid DISPLAYCONFIG_SOURCE_MODE structure describing the specified source.

### `id`

The source or target identifier on the specified adapter that this path relates to.

### `adapterId`

The identifier of the adapter that this source or target mode information relates to.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.targetMode`

A valid [DISPLAYCONFIG_TARGET_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_mode) structure that describes the specified target only when **infoType** is DISPLAYCONFIG_MODE_INFO_TYPE_TARGET.

### `DUMMYUNIONNAME.sourceMode`

A valid [DISPLAYCONFIG_SOURCE_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_source_mode) structure that describes the specified source only when **infoType** is DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE.

### `DUMMYUNIONNAME.desktopImageInfo`

A [DISPLAYCONFIG_DESKTOP_IMAGE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_desktop_image_info) structure that describes information about the desktop image only when **infoType** is [DISPLAYCONFIG_MODE_INFO_TYPE_DESKTOP_IMAGE](https://learn.microsoft.com/windows/win32/api/wingdi/ne-wingdi-displayconfig_mode_info_type).

Supported starting in Windows 10.

## See also

[DISPLAYCONFIG_MODE_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_mode_info_type)

[DISPLAYCONFIG_SOURCE_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_source_mode)

[DISPLAYCONFIG_TARGET_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_mode)