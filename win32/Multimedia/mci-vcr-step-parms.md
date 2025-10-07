# MCI\_VCR\_STEP\_PARMS structure

The **MCI\_VCR\_STEP\_PARMS** structure contains parameters for the [**MCI\_STEP**](https://learn.microsoft.com/windows/win32/multimedia/mci-step) command for video-cassette recorders.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwFrames**

Number of frames to jump (the length of a single step) as the [**MCI\_STEP**](https://learn.microsoft.com/windows/win32/multimedia/mci-step) command steps forward or backward through the content.

## Remarks

When assigning data to the members in this structure, set the corresponding flags in the *fdwCommand* parameter of [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) to validate the members.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Vcr.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_STEP**](https://learn.microsoft.com/windows/win32/multimedia/mci-step)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

