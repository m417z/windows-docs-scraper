# MCI\_OVLY\_RECT\_PARMS structure

The **MCI\_OVLY\_RECT\_PARMS** structure contains positioning information for the [**MCI\_PUT**](https://learn.microsoft.com/windows/win32/multimedia/mci-put) and [**MCI\_WHERE**](https://learn.microsoft.com/windows/win32/multimedia/mci-where) commands for video-overlay devices.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**rc**

Rectangle containing positioning information. [RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85)) structures are handled differently in MCI than in other parts of Windows; in MCI, **rc.right** contains the width of the rectangle and **rc.bottom** contains its height.

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

[**MCI\_PUT**](https://learn.microsoft.com/windows/win32/multimedia/mci-put)

[**MCI\_WHERE**](https://learn.microsoft.com/windows/win32/multimedia/mci-where)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

[RECT](https://learn.microsoft.com/previous-versions//ms536136(v=vs.85))

