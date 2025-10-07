# MCI\_GENERIC\_PARMS structure

The **MCI\_GENERIC\_PARMS** structure contains the handle of the window that receives notification messages. This structure is used for MCI command messages that have empty parameter lists.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

## Remarks

The **MCI\_CLOSE\_PARMS** and **MCI\_REALIZE\_PARMS** structures are identical to the **MCI\_GENERIC\_PARMS** structure.

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

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

