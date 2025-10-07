# MCI\_STATUS\_PARMS structure

The **MCI\_STATUS\_PARMS** structure contains information for the [**MCI\_STATUS**](https://learn.microsoft.com/windows/win32/multimedia/mci-status) command.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwReturn**

Contains information on return.

**dwItem**

Capability being queried.

**dwTrack**

Length or number of tracks.

## Remarks

The MCI\_STATUS\_ITEM flag must be set in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the **dwItem** member, which should contain one of the constants indicating what status information is being requested.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Mciapi.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_STATUS**](https://learn.microsoft.com/windows/win32/multimedia/mci-status)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

