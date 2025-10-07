# MCI\_VCR\_CUE\_PARMS structure

The **MCI\_VCR\_CUE\_PARMS** structure contains parameters for the [**MCI\_CUE**](https://learn.microsoft.com/windows/win32/multimedia/mci-cue) command for video-cassette recorders.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwFrom**

Position to cue from.

**dwTo**

Position to cue to.

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

[**MCI\_CUE**](https://learn.microsoft.com/windows/win32/multimedia/mci-cue)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

