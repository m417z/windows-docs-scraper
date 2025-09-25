# IAMExtDevice::GetCapability

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCapability` method retrieves the capabilities of the external device.

## Parameters

### `Capability` [in]

Specifies the capability to check. See Remarks for more information.

### `pValue` [out]

Pointer to a variable that receives a **long** integer. See Remarks for more information.

### `pdblValue` [out]

Pointer to a variable that receives a **double**. See Remarks for more information.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

The *Capability* parameter is a flag that specifies which capability to check. The method returns the result either in the *pValue* parameter or in the *pdblValue* parameter, depending on the capability flag.

For the following flags, the method returns the value OATRUE or OAFALSE in the *pValue* parameter. The value OATRUE indicates that the capability is present, while the value OAFALSE indicates it is absent.

| Capability flag | Description |
| --- | --- |
| ED_DEVCAP_AUDIO_INPUTS | Device accepts audio input. |
| ED_DEVCAP_CAN_MONITOR_SOURCES | Device can send any input to the monitored output, regardless of the input that is currently selected. |
| ED_DEVCAP_CAN_PREVIEW | Device can preview. |
| ED_DEVCAP_CAN_RECORD | Device can record. |
| ED_DEVCAP_CAN_RECORD_STROBE | Device can strobe record. This capability applies to multitrack devices that can record to selected tracks. |
| ED_DEVCAP_CAN_SAVE | Device can save data. |
| ED_DEVCAP_CTLTRK_READ | Device can read control tracks. |
| ED_DEVCAP_HAS_AUDIO | Device has audio. |
| ED_DEVCAP_HAS_VIDEO | Device has video. |
| ED_DEVCAP_INDEX_READ | Device can read index marks. |
| ED_DEVCAP_NEEDS_CALIBRATING | Device needs calibrating. See [IAMExtDevice::Calibrate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamextdevice-calibrate). |
| ED_DEVCAP_TIMECODE_READ | Device can read SMPTE time code. |
| ED_DEVCAP_TIMECODE_WRITE | Device can set SMPTE time code. |
| ED_DEVCAP_USES_FILES | Device has a built-in file system. |
| ED_DEVCAP_VIDEO_INPUTS | Device accepts video input. |

For the following flags, the method returns a defined constant in the *pValue* parameter.

ED_DEVCAP_DEVICE_TYPE: Returns the device type.

| Returned Constant | Description |
| --- | --- |
| ED_DEVTYPE_ATR | Audio tape recorder |
| ED_DEVTYPE_CG | Character generator |
| ED_DEVTYPE_DDR | Digital disk recorder |
| ED_DEVTYPE_DVE | Digital video effects unit |
| ED_DEVTYPE_GPI | General purpose interface trigger |
| ED_DEVTYPE_KEYER | Video keyer |
| ED_DEVTYPE_LASERDISK | Laserdisc |
| ED_DEVTYPE_MIXER_AUDIO | Audio mixer |
| ED_DEVTYPE_MIXER_VIDEO | Video mixer |
| ED_DEVTYPE_ROUTER | Video router |
| ED_DEVTYPE_TBC | Timebase corrector |
| ED_DEVTYPE_TCG | Timecode generator/reader |
| ED_DEVTYPE_VCR | VCR, or camcorder with full VCR capabilities |
| ED_DEVTYPE_WIPEGEN | Video wipe generator |
| ED_DEVTYPE_JOYSTICK | Joystick |
| ED_DEVTYPE_KEYBOARD | Keyboard |

ED_DEVCAP_SYNC_ACCURACY: Returns an indication of the device's synchronization accuracy.

| Returned Constant | Description |
| --- | --- |
| ED_SYNCACC_PRECISE | Device has precise accuracy. |
| ED_SYNCACC_FRAME | Device is frame accurate. |
| ED_SYNCACC_ROUGH | Device is less than frame accurate. |

ED_DEVCAP_NORMAL_RATE: Returns the device's normal frame rate.

| Returned Constant | Description |
| --- | --- |
| ED_RATE_24 | 24 frames per second (fps) |
| ED_RATE_25 | 25 fps |
| ED_RATE_2997 | 29.97 fps |
| ED_RATE_30 | 30 fps |

ED_DEVCAP_SEEK_TYPE: Returns an indication of the device's seeking accuracy.

| Returned Constant | Description |
| --- | --- |
| ED_SEEK_PERFECT | Device can seek within one video frame without a signal break. |
| ED_SEEK_FAST | Device can seek quickly, with a short break in the signal. |
| ED_SEEK_SLOW | Device seeks slowly; such as tape transport. |

For the following flags, the method returns a numeric value in the *pValue* parameter.

|  |  |
| --- | --- |
| Capability Flag | Returned Value |
| ED_DEVCAP_EXTERNAL_DEVICE_ID | Manufacturer-specific identifier. |
| ED_DEVCAP_PREROLL | Device preroll time. |
| ED_DEVCAP_POSTROLL | Device postroll time. |

In Windows XP Service Pack 2 and later, the following additional flags are supported for ED_DEVCAP_DEVICE_TYPE.

| Returned Constant | Description |
| --- | --- |
| ED_DEVTYPE_CAMERA_STORAGE | Storage for still images or short video files. |
| ED_DEVTYPE_DTV | Digital television with serial bus interface. |
| ED_DEVTYPE_PC_VIRTUAL | Virtual or emulated device on a computer. |

To use these constants, include the header file Xprtdefs.h.

### DV Implementation

The [MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) and UVC drivers support the following behaviors.

The ED_DEVCAP_NORMAL_RATE flag returns the frame rate.

| Returned Constant | Description |
| --- | --- |
| ED_RATE_25 | 25 fps (default PAL frame rate) |
| ED_RATE_2997 | 29.997 fps (default NTSC frame rate) |

For MSDV only, the ED_DEVCAP_DEVICE_TYPE flag returns the device type. Possible values are shown in the following table. For UVC devices, use the [IKsTopologyInfo](https://learn.microsoft.com/previous-versions/ms785846(v=vs.85)) interface instead.

| Returned Constant | Description |
| --- | --- |
| ED_DEVTYPE_CAMERA | Simple camera that can record or pause-record, but lacks full VCR capabilities. |
| ED_DEVTYPE_DVHS | Device supports D-VHS format. |
| ED_DEVTYPE_UNKNOWN | Unknown device type. |
| ED_DEVTYPE_VCR | Device has full VCR capabilities. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtDevice Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamextdevice)