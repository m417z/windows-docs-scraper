# IMESTRUCT structure

## Description

Used by [SendIMEMessageEx](https://learn.microsoft.com/windows/desktop/api/ime/nf-ime-sendimemessageexa) to specify the subfunction to be executed in the Input Method Editor (IME) message and its parameters. This structure is also used to receive return values from those subfunctions.

## Members

### `fnc`

A subfunction. One of the following values.

#### IME_ENTERWORDREGISTERMODE

Used to register words. Words are registered as an application sends a word and its reading. Structure members are interpreted as follows:

| Member | Type | Description |
| --- | --- | --- |
| **lParam1** [Windows 3.1] | **LPARAM** | The low-order word specifies a handle to the global memory that contains a word string ending with 0. The global memory is a memory block allocated by specifying the **GMEM_MOVEABLE** and **GMEM_SHARE** flags in the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function. |
| **lParam2** [Windows 3.1] | **LPARAM** | The low-order word specifies a handle to the global memory that contains a reading string ending with 0. The global memory is a memory block allocated by specifying the **GMEM_MOVEABLE** and **GMEM_SHARE** flags in the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function |
| **lParam3** [Windows 3.1] | **LPARAM** | Must be **NULL**. |
| **lParam1** [Windows NT] | **LPARAM** | Specifies a handle to the global memory that contains a word string ending with 0. The global memory is a memory block allocated by specifying the **GMEM_MOVEABLE** and **GMEM_SHARE** flags in the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function. |
| **lParam2** [Windows NT] | **LPARAM** | Specifies a handle to the global memory that contains a reading string ending with 0. The global memory is a memory block allocated by specifying the **GMEM_MOVEABLE** and **GMEM_SHARE** flags in the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function. |
| **lParam3** [Windows NT] | **LPARAM** | Used to specify information about a part of speech. Since such information cannot be specified with the current Windows specification, **NULL** is set here. |

The return value indicates the result of word registration. **TRUE** if the registration has been processed normally; otherwise, **FALSE**.

If information such as a part of speech is necessary, a dialog box should be displayed to prompt the user for input. **NULL** may be specified in the members **lParam1** and **lParam2**; in this case, nothing should be displayed in the associated entry field in the dialog box.

#### IME_GETCONVERSIONMODE

Acquires the current conversion mode of the IME. This subprogram uses no parameters.

This is the same as **IME_GET_MODE**.

Returns the current conversion mode of the IME as a combination of **IME_MODE_ALPHANUMERIC** to **IME_MODE_NOCODEINPUT**. Conversion modes are as follows:

| Conversion Mode | Mode |
| --- | --- |
| **IME_MODE_ALPHANUMERIC** | Alphanumeric |
| **IME_MODE_KATAKANA** | Katakana |
| **IME_MODE_HIRAGANA** | Hiragana |
| **IME_MODE_SBCSCHAR** | Single-byte character |
| **IME_MODE_DBCSCHAR** | Double-byte character |
| **IME_MODE_ROMAN** | Roman character |
| **IME_MODE_NOROMAN** | Non-Roman character |
| **IME_MODE_CODEINPUT** | Code input |
| **IME_MODE_NOCODEINPUT** | Non-code input |

#### IME_GET_MODE

Same as **IME_GETCONVERSIONMODE**.

#### IME_MOVECONVERTWINDOW

Same as **IME_SETCONVERSIONWINDOW**.

#### IME_SETCONVERSIONFONTEX

A font to be used to display an undetermined string that appears in the conversion window. Structure members are interpreted as follows:

| Member | Type | Description |
| --- | --- | --- |
| **lParam1** [Windows 3.1] | **LPARAM** | The low-order word specifies a handle to the global memory that contains a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that specifies the logical font. The global memory is a memory block allocated by specifying the **GMEM_MOVEABLE** and **GMEM_SHARE** flags in the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function. **NULL** indicates a system font. |
| **lParam1** [Windows NT] | **LPARAM** | Specifies a handle to the global memory that contains a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that specifies the logical font. The global memory is a memory block allocated by specifying the **GMEM_MOVEABLE** and **GMEM_SHARE** flags in the [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function. **NULL** indicates a system font. |

This subfunction has no return value.

The font specified by **IME_SETCONVERSIONFONTEX** can only be used to display undetermined strings.

To display undetermined strings at the default position, use a system font. If the display position is no longer the default position, enable the previously specified font.

The global memory that contains the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure is released by the application.

If the IME currently displaying the conversion window receives the **IME_SETCONVERSIONFONTEX** command, and as a result of the command processing the conversion window has changed, the IME should send a WM_IME_REPORT:IR_CHANGECONVERT message. This message should not be sent if the font specified by **IME_SETCONVERSIONFONTEX** is the same as the one being used by the IME.

#### IME_SETCONVERSIONMODE

Sets the conversion mode of the IME. The **wParam** member specifies one or more of the following values:

| Value | Meaning |
| --- | --- |
| IME_MODE_ALPHANUMERIC | Alphanumeric conversion mode. This value cannot be used with IME_MODE_KATAKANA or IME_MODE_HIRAGANA. |
| IME_MODE_KATAKANA | Katakana conversion mode. This value cannot be used with IME_MODE_ALPHANUMERIC or IME_MODE_HIRAGANA. |
| IME_MODE_HIRAGANA | Hiragana conversion mode. This value cannot be used with IME_MODE_ALPHANUMERIC or IME_MODE_HIRAGANA. |
| IME_MODE_SBCSCHAR | Single-byte character conversion mode. This parameter cannot be used with IME_MODE_DBCSCHAR. |
| IME_MODE_DBCSCHAR | Double-byte character conversion mode. This parameter cannot be used with IME_MODE_SBCSCHAR. |
| IME_MODE_ROMAN | Roman character conversion mode. This parameter cannot be used with IME_MODE_NOROMAN. |
| IME_MODE_NOROMAN | Non-Roman character conversion mode. This parameter cannot be used with IME_MODE_ROMAN. |
| IME_MODE_CODEINPUT | Code input conversion mode. This parameter cannot be used with IME_MODE_NOCODEINPUT. How an IME operates in code input mode depends on the particular IME. |
| IME_MODE_NOCODEINPUT | Noncode input conversion mode. This parameter cannot be used with IME_MODE_CODEINPUT. |

The return value indicates whether the given conversion mode has been set up successfully. It returns the state of the conversion mode previously in effect if the new conversion mode has been set up; otherwise, **NULL**.

#### IME_SETCONVERSIONWINDOW

The size and position of the bounding rectangle for the IME, and the initial position of the conversion window. The IME displays an undetermined string at the position specified by this subfunction.

The **wParam** member specifies one of the following values:

| Value | Meaning |
| --- | --- |
| MCW_DEFAULT | Displays the conversion window at the default position, which is usually the bottom of the screen.<br><br>If the MCW_DEFAULT style is specified in an IME_SETCONVERSIONWINDOW message, then when the IME displays or draws a conversion window at the default position, it must not send an IR_OPENCONVERT, IR_CHANGECONVERT, IR_FULLCONVERT or IR_CLOSECONVERT message. |
| MCW_WINDOW | Displays the conversion window at the coordinate given in the **lParam1** member, in the window specified in the *wParam* parameter of the WM_CONVERTREQUEST or WM_CONVERTREQUESTEX message. The value in **lParam1** indicates the coordinates relative to the upper left corner of the window, with the low-order word representing the X coordinate and the high-order word the Y coordinate. The bounding rectangle is the client rectangle of the given window and is the most typical way of invoking a kana-to-kanji conversion.<br><br>If the MCW_WINDOW style is specified in an IME_SETCONVERSIONWINDOW message, the IME must send an IR_OPENCOVERT message if the conversion window status has changed from closed to open. If the conversion window status has changed from open to closed, the IME must send an IR_CLOSECONVERT message. There is an exception, however. See IME_WINDOWUPDATE for details. |
| MCW_WINDOW \| MCW_RECT | Same as MCW_WINDOW except that the bounding rectangle is specified by the **lParam2** and **lParam3** members. The **lParam2** member specifies the upper-left point and **lParam3** specifies the lower-right point, each with the low-order word representing the X coordinate and the high-order word the Y coordinate. The coordinates are relative to the upper left of the window. |
| MCW_SCREEN | Displays the conversion window with its upper left corner designated by the **lParam1** member. The **lParam1** member indicates absolute coordinates with the origin at the upper left corner of the screen. The low-order word represents the X coordinate and the high-order word the Y coordinate. The bounding rectangle is the full screen.<br><br>If the MCW_SCREEN style is specified in an IME_SETCONVERSIONWINDOW message, the IME must send an IR_OPENCOVERT message if the conversion window status has changed from closed to open. If the conversion window status has changed from open to closed, the IME must send an IR_CLOSECONVERT message. There is an exception, however. See IME_WINDOWUPDATE for details. |
| MCW_SCREEN \| MCW_RECT | Same as MCW_SCREEN except that the bounding rectangle is specified by the **lParam2** and **lParam3** members. The **lParam2** member specifies the upper-left point and **lParam3** specifies the lower-right point, each with the low-order word representing the X coordinate and the high-order word the Y coordinate. The coordinates are absolute coordinates with the origin at the upper left of the screen. |
| MCW_HIDDEN [Windows 3.1] | When this flag is specified, the IME does not display the conversion window. Instead, the application itself displays undetermined strings. The **lParam1** member specifies the coordinates of the cursor position being displayed by the application or of the point of interest. The **lParam2** and **lParam3** members specify a region where no display is enabled by the IME. An IME that displays determined-string candidates in a pop-up window is able to use these pieces of information to determine where to display the window of determined-string candidates. A window to display candidate strings is considered as a system window. Therefore it is IME-dependent regarding whether to display such a window, where and how to display the window, and what keyboard input to use. The three members **lParam1**, **lParam2**, and **lParam3**, specify the absolute coordinates from the upper left of the screen, each with the low-order word representing the X coordinate and the high-order word the Y coordinate.<br><br>When the MCW_HIDDEN flag is specified, the IME sends an IR_UNDETERMINE message to request that the application displays the undetermined string. The application itself displays the undetermined string contained in this message.<br><br>Once the MCW_HIDDEN flag is specified, the IME does not send an IR_OPENCONVERT, IR_CHANGECONVERT or IR_CLOSECONVERT message.<br><br>If an application specifies MCW_HIDDEN and, at the same time, requests a rectangle too large to display the candidate window for a determined string, it should be treated as an error. The error code must be IME_RD_TOOLONG.<br><br>If the MCW_HIDDEN style is specified in an IME_SETCONVERSIONWINDOW message, the IME must never send an IR_OPENCONVERT, IR_CHANGECONVERT, IR_FULLCONVERT or IR_CLOSECONVERT. |
| MCW_VERTICAL | Tells the IME that the application is displaying character strings in vertical writing format. If this flag is specified, the conversion window is displayed for vertical writing, with the position designated by the **lParam1** member being the upper-right corner. This flag is can be specified with MCW_WINDOW, MCW_WINDOW\|MCW_RECT, MCW_SCREEN, or MCW_SCREEN\|MCW_RECT. An IME must support MCW_VERTICAL. If MCW_VERTICAL is specified and the font being selected is not for vertical writing, the IME uses the default vertical-writing font. This default font is created as follows:<br><br>1. Font information is retrieved in the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure by the [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) function using the font handle of SYSTEM_FONT. 2. The font is created by adding an ampersand (@) at the beginning of the face name and setting the escapement and orientation to 270 degrees. |

The return value indicates whether the command has been executed. **TRUE** if the command execution was successful; otherwise, **FALSE**.

If an undetermined string seems to overflow the bounding rectangle, the IME must issue the report message WM_IME_REPORT:IR_FULLCONVERT to the application before displaying that string. If the application does not handle this message, the subsequent processing for the display is not formulated in this specification, but it is left to the IME. For example, the undetermined string might be scrolled within the bounding rectangle or it may be moved temporarily to the default position.

If an IME_SETCONVERSIONWINDOW message is called when the IME is holding an undetermined string, the IME should issue a WM_IME_REPORT:IR_CLOSECONVERT message; if the string fits in the window given as a parameter, the IME should issue a WM_IME_REPORT:IR_OPENCONVERT message. Only then should the conversion window be drawn. If the string does not fit in the window, the IME should issue a WM_IME_REPORT:IR_FULLCONVERT message.

The position of the bounding rectangle may be specified outside the physical screen area. If the whole bounding rectangle is outside the physical screen, undetermined strings must not be displayed. If part of the bounding rectangle is outside the physical screen, the IME clips the bounding rectangle so that no part of the undetermined string overflows the screen, and also adjusts the display start position.

It is recommended not to set the maximum number of lines of, or maximum characters displayed in, the conversion window.

If the conversion window overlaps a system window, the conversion window must be visible. For example, the conversion window can be given top priority for display or the system window can be moved elsewhere.

The IME must send an IR_CHANGECONVERT message if the conversion window has changed in size, display contents, or display color. However, if an undetermined string does not fit in a specified window, the IME must send an IR_FULLCONVERT message rather than IR_CHANGECONVERT.

When the IME has shifted from the MCW_WINDOW or MCW_SCREEN mode to MCW_DEFAULT, it must send an IR_CLOSECONVERT message if an undetermined string exists.

When the IME has shifted from the MCW_WINDOW or MCW_SCREEN mode to MCW_HIDDEN, it must send an IR_CLOSECONVERT message if an undetermined string exists.

When the IME has shifted from the MCW_HIDDEN mode to MCW_DEFAULT, MCW_SCREEN, or MCW_WINDOW, the IME must transmit an IR_UNDETERMINE message with undetermined string = 0 and determined string = 0.

#### IME_SETLEVEL

Korean-specific subfunction that sets the IME level on the current application. The **wParam** member accepts one of the following level values.

| Level | Meaning |
| --- | --- |
| 1 | No IME support. All IME-specific messages are ignored. |
| 2 | Partial IME support. Supports a subset of IME behavior including the position of the composition or candidate windows and the input mode or status. |
| 3 | Full IME support. |

#### IME_SETOPEN

Sets the status of the kana-to-kanji conversion feature of the IME.

The **wParam** member is set to nonzero to open the IME and zero to close the IME

The return value indicates the previous status of the kana-to-kanji conversion feature. Returns **TRUE** if open; otherwise, **FALSE**.

An undetermined string must not be determined if the kana-to-kanji conversion feature has been closed by IME_SETOPEN.

When the kana-to-kanji conversion feature is to be closed by IME_SETOPEN, the IME must send an IR_CLOSECONVERT message if the IME is in MCW_WINDOW or MCW-SCREEN mode and if a conversion window is open. However, the IME need not issue IR_CLOSECONVERT if it is in MCW_HIDDEN mode and if an undetermined string exists.

#### IME_SET_MODEK

Korean-specific version of IME_SETCONVERSIONMODE.

### `wParam`

Usage depends on the subfunction specified in **fnc**.

### `wCount`

Usage depends on the subfunction specified in **fnc**.

### `dchSource`

Usage depends on the subfunction specified in **fnc**.

### `dchDest`

Usage depends on the subfunction specified in **fnc**.

### `lParam1`

Usage depends on the subfunction specified in **fnc**.

### `lParam2`

Usage depends on the subfunction specified in **fnc**.

### `lParam3`

Usage depends on the subfunction specified in **fnc**.

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

**Reference**

[SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata)