# MCI\_PLAY\_PARMS structure

The **MCI\_PLAY\_PARMS** structure contains positioning information for the [**MCI\_PLAY**](https://learn.microsoft.com/windows/win32/multimedia/mci-play) command.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwFrom**

Position to play from.

**dwTo**

Position to play to.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the members.

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

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

