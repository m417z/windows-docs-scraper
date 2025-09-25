## Description

The __DISPLAYCONFIG_SDR_WHITE_LEVEL__ structure contains information about a display's current SDR white level. This is the brightness level that SDR "white" is rendered at within an HDR monitor.

## Members

### `header`

A [DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_device_info_header) structure that contains information for getting the SDR white level. The **type** member of DISPLAYCONFIG_DEVICE_INFO_HEADER is set to DISPLAYCONFIG_DEVICE_INFO_GET_SDR_WHITE_LEVEL. DISPLAYCONFIG_DEVICE_INFO_HEADER also contains the adapter and target identifiers of the target to get the SDR white level for. The **size** member of DISPLAYCONFIG_DEVICE_INFO_HEADER is set to at least the size of the DISPLAYCONFIG_SDR_WHITE_LEVEL structure.

### `SDRWhiteLevel`

The monitor's current SDR white level, specified as a multiplier of 80 nits, multiplied by 1000. E.g. a value of 1000 would indicate that the SDR white level is 80 nits, while a value of 2000 would indicate an SDR white level of 160 nits.

```cpp
DISPLAYCONFIG_SDR_WHITE_LEVEL sdrWhiteLevel;
...
float SDRWhiteLevelInNits = (float)sdrWhiteLevel.SDRWhiteLevel / 1000 * 80;
```

## Remarks

## See also

[Using DirectX with high dynamic range Displays and Advanced Color
](https://learn.microsoft.com/windows/win32/direct3darticles/high-dynamic-range)

[DISPLAYCONFIG_DEVICE_INFO_HEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_device_info_header)

[DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-displayconfiggetdeviceinfo)