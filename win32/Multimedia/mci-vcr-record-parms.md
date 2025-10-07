# MCI\_VCR\_RECORD\_PARMS structure

The **MCI\_VCR\_RECORD\_PARMS** structure contains parameters for the [**MCI\_RECORD**](https://learn.microsoft.com/windows/win32/multimedia/mci-record) command for video-cassette recorders.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwFrom**

Position to play from.

**dwTo**

Position to play to.

**dwAt**

Time value that affects the [**MCI\_RECORD**](https://learn.microsoft.com/windows/win32/multimedia/mci-record) or [**MCI\_CUE**](https://learn.microsoft.com/windows/win32/multimedia/mci-cue) command. For **MCI\_RECORD**, this is the time when recording begins. For **MCI\_CUE**, this is the time when the cued device reaches the position given in **dwFrom**.

## Remarks

Positions are specified in the current time format.

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

[**MCI\_CUE**](https://learn.microsoft.com/windows/win32/multimedia/mci-cue)

[**MCI\_RECORD**](https://learn.microsoft.com/windows/win32/multimedia/mci-record)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

