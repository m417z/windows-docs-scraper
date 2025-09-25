# SetProcessDefaultLayout function

## Description

Changes the default layout when windows are created with no parent or owner only for the currently running process.

## Parameters

### `dwDefaultLayout` [in]

Type: **DWORD**

The default process layout. This parameter can be 0 or the following value.

| Value | Meaning |
| --- | --- |
| **LAYOUT_RTL**<br><br>0x00000001 | Sets the default horizontal layout to be right to left. |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The layout specifies how text and graphics are laid out; the default is left to right. The **SetProcessDefaultLayout** function changes layout to be right to left, which is the standard in Arabic and Hebrew cultures.

After the **LAYOUT_RTL** flag is selected, flags normally specifying right or left are reversed. To avoid confusion, consider defining alternate words for standard flags, such as those in the following table.

| Standard flag | Suggested alternate name |
| --- | --- |
| **WS_EX_RIGHT** | **WS_EX_TRAILING** |
| **WS_EX_RTLREADING** | **WS_EX_REVERSEREADING** |
| **WS_EX_LEFTSCROLLBAR** | **WS_EX_LEADSCROLLBAR** |
| **ES_LEFT** | **ES_LEAD** |
| **ES_RIGHT** | **ES_TRAIL** |
| **EC_LEFTMARGIN** | **EC_LEADMARGIN** |
| **EC_RIGHTMARGIN** | **EC_TRAILMARGIN** |

If using this function with a mirrored window, note that the **SetProcessDefaultLayout** function does not mirror the whole process and all the device contexts (DCs) created in it. It mirrors only the mirrored window's DCs. To mirror any DC, use the [SetLayout](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setlayout) function.

## See also

**Conceptual**

[GetProcessDefaultLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getprocessdefaultlayout)

**Other Resources**

**Reference**

[SetLayout](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setlayout)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)