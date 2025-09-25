# tagKSCAMERA_EXTENDEDPROP_VIDEOPROCSETTING structure

## Description

The **KSCAMERA_EXTENDEDPROP_VIDEOPROCSETTING** is a property payload structure for video processing settings related to white balance, exposure mode, and focus mode.

## Members

### `Mode`

The video processing mode type. Currently, this member is used to control white balance. The possible values for **Mode** are the following.

| Value | Description |
| --- | --- |
| KSCAMERA_EXTENDEDPROP_WHITEBALANCE_TEMPERATURE | A picture temperature value is used to set white balance in degrees Kelvin. |
| KSCAMERA_EXTENDEDPROP_WHITEBALANCE_PRESET | The white balance setting is a preset value specified in **VideoProc**. |

This member is not used for [KSPROPERTY_CAMERACONTROL_EXTENDED_EXPOSUREMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-exposuremode) and [KSPROPERTY_CAMERACONTROL_EXTENDED_FOCUSMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-focusmode). In these cases it must be set to 0.

### `Min`

The minimum range value for the setting in **VideoProc**.

### `Max`

The maximum range value for the setting in **VideoProc**.

### `Step`

The increment in value, when applicable, for the setting in **VideoProc** when **Mode** is set to KSCAMERA_EXTENDEDPROP_WHITEBALANCE_TEMPERATURE.

-or-

The increment in value, when applicable, for the setting in **VideoProc** when setting exposure is set manually with KSCAMERA_EXTENDEDPROP_VIDEOPROCFLAG_MANUAL.

### `VideoProc`

Using the [KSPROPERTY_CAMERACONTROL_EXTENDED_WHITEBALANCEMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-whitebalancemode) property, when **Mode** is set to KSCAMERA_EXTENDEDPROP_WHITEBALANCE_PRESET, the **VideoProc.Value.ul** value is one of the following.

| Value | Description |
| --- | --- |
| KSCAMERA_EXTENDEDPROP_WBPRESET_CLOUDY | White balance preset for cloudy conditions. |
| KSCAMERA_EXTENDEDPROP_WBPRESET_DAYLIGHT | White balance preset for cloudy daylight. |
| KSCAMERA_EXTENDEDPROP_WBPRESET_FLASH | White balance preset to compensate for flash lighting. |
| KSCAMERA_EXTENDEDPROP_WBPRESET_FLUORESCENT | White balance preset to compensate for fluorescent lighting. |
| KSCAMERA_EXTENDEDPROP_WBPRESET_TUNGSTEN | White balance preset to compensate for tungsten emitted lighting. |
| KSCAMERA_EXTENDEDPROP_WBPRESET_CANDLELIGHT | White balance preset to compensate for candlelight lighting. |

Using the [KSPROPERTY_CAMERACONTROL_EXTENDED_WHITEBALANCEMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-whitebalancemode) property, when **Mode** is set to KSCAMERA_EXTENDEDPROP_WHITEBALANCE_TEMPERATURE, the **VideoProc.Value.ul** value is a temperature value in degrees Kelvin.

Using the [KSPROPERTY_CAMERACONTROL_EXTENDED_EXPOSUREMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-exposuremode) property, when used for manually setting exposure, KSCAMERA_EXTENDEDPROP_VIDEOPROCFLAG_MANUAL, the **VideoProc.Value.ul** value is the exposure time in 100 nanosecond units.

Using the [KSPROPERTY_CAMERACONTROL_EXTENDED_FOCUSMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-focusmode) property, this member contains the focal length value for manual focus mode, KSCAMERA_EXTENDEDPROP_VIDEOPROCFLAG_MANUAL.

### `Reserved`

Reserved.

## See also

[KSPROPERTY_CAMERACONTROL_EXTENDED_EXPOSUREMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-exposuremode)

[KSPROPERTY_CAMERACONTROL_EXTENDED_FOCUSMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-focusmode)

[KSPROPERTY_CAMERACONTROL_EXTENDED_WHITEBALANCEMODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-whitebalancemode)