# SetLayout function

## Description

The **SetLayout** function changes the layout of a device context (DC).

## Parameters

### `hdc` [in]

A handle to the DC.

### `l` [in]

The DC layout. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **LAYOUT_BITMAPORIENTATIONPRESERVED** | Disables any reflection during [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt) and [StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt) operations. |
| **LAYOUT_RTL** | Sets the default horizontal layout to be right to left. |

## Return value

If the function succeeds, it returns the previous layout of the DC.

If the function fails, it returns GDI_ERROR.

## Remarks

The layout specifies the order in which text and graphics are revealed in a window or a device context. The default is left to right. The **SetLayout** function changes this to be right to left, which is the standard in Arabic and Hebrew cultures.

Once the LAYOUT_RTL flag is selected, flags normally specifying right or left are reversed. To avoid confusion, consider defining alternate words for standard flags, such as those in the following table.

| Standard flag | Suggested alternate name |
| --- | --- |
| WS_EX_RIGHT | WS_EX_TRAILING |
| WS_EX_RTLREADING | WS_EX_REVERSEREADING |
| WS_EX_LEFTSCROLLBAR | WS_EX_LEADSCROLLBAR |
| ES_LEFT | ES_LEAD |
| ES_RIGHT | ES_TRAIL |
| EC_LEFTMARGIN | EC_LEADMARGIN |
| EC_RIGHTMARGIN | EC_TRAILMARGIN |

**SetLayout** cannot modify drawing directly into the bits of a DIB.

For more information, see "Window Layout and Mirroring" in [Window Features](https://learn.microsoft.com/windows/desktop/winmsg/window-features).

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetLayout](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getlayout)