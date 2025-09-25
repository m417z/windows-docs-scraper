# DISPLAYCONFIG_TARGET_PREFERRED_MODE structure

## Description

The **DISPLAYCONFIG_TARGET_PREFERRED_MODE** structure contains information about the preferred mode of a display.

## Members

### `header`

A [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that contains information about the request for the target preferred mode. The caller should set the **type** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE and the **adapterId** and **id** members of DISPLAYCONFIG_DEVICE_INFO_HEADER to the target for which the caller wants the preferred mode. The caller should set the **size** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to at least the size of the DISPLAYCONFIG_TARGET_PREFERRED_MODE structure.

### `width`

The width in pixels of the best mode for the monitor that is connected to the target that the **targetMode** member specifies.

### `height`

The height in pixels of the best mode for the monitor that is connected to the target that the **targetMode** member specifies.

### `targetMode`

A [DISPLAYCONFIG_TARGET_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_mode) structure that describes the best target mode for the monitor that is connected to the specified target.

## See also

[DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header)

[DISPLAYCONFIG_TARGET_MODE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_target_mode)