# MCI\_VD\_PLAY\_PARMS structure

The **MCI\_VD\_PLAY\_PARMS** structure contains position and speed information for the [**MCI\_PLAY**](https://learn.microsoft.com/windows/win32/multimedia/mci-play) command for videodisc devices.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwFrom**

Position to play from.

**dwTo**

Position to play to.

**dwSpeed**

Playback speed in frames per second.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the members.

You can use the [**MCI\_PLAY\_PARMS**](https://learn.microsoft.com/windows/win32/multimedia/mci-play-parms) structure instead of **MCI\_VD\_PLAY\_PARMS** if you are not using the extended data members.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Mciapi.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_PLAY**](https://learn.microsoft.com/windows/win32/multimedia/mci-play)

[**MCI\_PLAY\_PARMS**](https://learn.microsoft.com/windows/win32/multimedia/mci-play-parms)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

