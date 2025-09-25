## Description

The **DEVCAPS** structure describes the capabilities of an external device.

## Members

### `CanRecord`

Specifies if the external device can record.

### `CanRecordStrobe`

For multitrack devices. Specifies if the external device can record. Switches currently recording tracks off and selected nonrecording track into record.

### `HasAudio`

Specifies if the external device has audio capabilities.

### `HasVideo`

Specifies if the external device has video capabilities.

### `UsesFiles`

Specifies if the external device uses files.

### `CanSave`

Specifies if the external device can save.

### `DeviceType`

Specifies the type of the external device. See Remarks.

| Flag | Meaning |
|---|---|
| ED_DEVTYPE_VCR | Video cassette recorder |
| ED_DEVTYPE_LASERDISC | Laserdisc player |
| ED_DEVTYPE_KEYBOARD | Keyboard |
| ED_DEVTYPE_CAMERA | Video camera |
| ED_DEVTYPE_VTR | Video tape recorder |
| ED_DEVTYPE_UNKNOWN | Unknown type |

### `TCRead`

Specifies if the external device can read timecodes.

### `TCWrite`

Specifies if the external device can write timecodes.

### `CTLRead`

Specifies if the external device can read to a control track (nontimecode) target value.

### `IndexRead`

Specifies if the external device can read to an index (nontimecode) target value.

### `Preroll`

Specifies the external device's preroll time in the current time format.

### `Postroll`

Specifies the external device's postroll time in the current time format.

### `SyncAcc`

Indicates the external device's synchronization accuracy.

### `NormRate`

Specifies the external device's normal frame rate.

### `CanPreview`

Specifies if the external device can preview.

### `CanMonitorSrc`

Specifies if the external device can monitor source.

### `CanTest`

Indicates the implementation of the external device allows testing of methods/parameters by setting the high bit of a parameter that makes sense. This is not implemented an always returns FALSE.

### `VideoIn`

Indicates the external device accepts video as an input.

### `AudioIn`

Indicates the external device accepts audio as an input.

### `Calibrate`

Indicates if the external device requires calibrating.

### `SeekType`

Specifies the type of seeking the external device is capable of. For example:

| Flag | Meaning |
|---|---|
| ED_SEEK_PERFECT | Indicates device can seek to within 1 video frame without a signal break (like a DDR). |
| ED_SEEK_FAST | Indicates device can seek quick with a short break in signal. |
| ED_SEEK_SLOW | Indicates slow seeking (like a tape transport). |

### `SimulatedHardware`

Must be set to zero.

## Remarks

Any ED_Xxx tokens are defined in *xprtdefs.h* in the Microsoft DirectX SDK.

All members of the DEVCAPS structure are **TRUE** or **FALSE** unless otherwise specified.

The **DeviceType** member can be used by an application to detect the device type or its current operating mode. For example, it can return either ED_DEVTYPE_CAMERA or ED_DEVTYPE_VTR depending on a DV camcorder's mode of operation. Also, some DV devices may not be known and a device type of ED_DEVTYPE_UNKNOWN can be returned by the driver. This happens with some DV media converters.

## See also

[KSPROPERTY_EXTDEVICE_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_extdevice_s)

[TIMECODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_timecode)