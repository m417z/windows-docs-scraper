# DISPLAYCONFIG_SOURCE_DEVICE_NAME structure

## Description

The **DISPLAYCONFIG_SOURCE_DEVICE_NAME** structure contains the GDI device name for the source or view.

## Members

### `header`

A [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that contains information about the request for the source device name. The caller should set the **type** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME and the **adapterId** and **id** members of DISPLAYCONFIG_DEVICE_INFO_HEADER to the source for which the caller wants the source device name. The caller should set the **size** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to at least the size of the DISPLAYCONFIG_SOURCE_DEVICE_NAME structure.

### `viewGdiDeviceName`

A NULL-terminated WCHAR string that is the GDI device name for the source, or view. This name can be used in a call to **EnumDisplaySettings** to obtain a list of available modes for the specified source.

## See also

[DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header)