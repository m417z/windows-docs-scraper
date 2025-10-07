# MCI\_VCR\_SET\_PARMS structure

The **MCI\_VCR\_SET\_PARMS** structure contains parameters for the [**MCI\_SET**](https://learn.microsoft.com/windows/win32/multimedia/mci-set) command for video-cassette recorders.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwTimeFormat**

Current time format.

**dwAudio**

Not used.

**dwTimeMode**

Constant that specifies the timing source used by the device. The timing source is either a timecode recorded on videotape, or the counters in the device that sense videotape movement.

**dwRecordFormat**

Recording rate.

**dwCounterFormat**

Format of a new counter time value.

**dwIndex**

Contents of on-screen display.

**dwTracking**

Speed adjustment used when tracking the VCR playback rate.

**dwSpeed**

Playback speed used by the device as an integer. Normal playback speed is 1000, double speed is 2000, and half speed is 500.

**dwLength**

Videotape length when the length is undetectable by the device.

**dwCounter**

New counter value.

**dwClock**

New clock time.

**dwPauseTimeout**

New timeout value for pause command.

**dwPrerollDuration**

Videotape length needed to stabilize the VCR output.

**dwPostrollDuration**

Videotape length needed to brake the VCR transport when a [**MCI\_STOP**](https://learn.microsoft.com/windows/win32/multimedia/mci-stop) or [**MCI\_PAUSE**](https://learn.microsoft.com/windows/win32/multimedia/mci-pause) command is issued.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the members.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Vcr.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_PAUSE**](https://learn.microsoft.com/windows/win32/multimedia/mci-pause)

[**MCI\_SET**](https://learn.microsoft.com/windows/win32/multimedia/mci-set)

[**MCI\_STOP**](https://learn.microsoft.com/windows/win32/multimedia/mci-stop)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

