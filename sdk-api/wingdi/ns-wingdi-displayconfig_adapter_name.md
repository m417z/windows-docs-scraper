# DISPLAYCONFIG_ADAPTER_NAME structure

## Description

The DISPLAYCONFIG_ADAPTER_NAME structure contains information about the display adapter.

## Members

### `header`

A [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that contains information about the request for the adapter name. The caller should set the **type** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME and the **adapterId** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to the adapter identifier of the adapter for which the caller wants the name. For this request, the caller does not need to set the **id** member of DISPLAYCONFIG_DEVICE_INFO_HEADER. The caller should set the **size** member of DISPLAYCONFIG_DEVICE_INFO_HEADER to at least the size of the DISPLAYCONFIG_ADAPTER_NAME structure.

### `adapterDevicePath`

A NULL-terminated WCHAR string that is the device name for the adapter. This name can be used with *SetupAPI.dll* to obtain the device name that is contained in the installation package.