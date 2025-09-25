# USEROBJECTFLAGS structure

## Description

Contains information about a window station or desktop handle.

## Members

### `fInherit`

If this member is TRUE, new processes inherit the handle. Otherwise, the handle is not inherited.

### `fReserved`

Reserved for future use. This member must be FALSE.

### `dwFlags`

For window stations, this member can contain the following window station attribute.

| Value | Meaning |
| --- | --- |
| **WSF_VISIBLE**<br><br>0x0001L | Window station has visible display surfaces. |

For desktops, the **dwFlags** member can contain the following value.

| Value | Meaning |
| --- | --- |
| **DF_ALLOWOTHERACCOUNTHOOK**<br><br>0x0001L | Allows processes running in other accounts on the desktop to set hooks in this process. |

## See also

[CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa)

[GetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getuserobjectinformationa)

[OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa)

[OpenInputDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openinputdesktop)

[SetUserObjectInformation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setuserobjectinformationa)