# REBARBANDINFOA structure

## Description

Contains information that defines a band in a rebar control.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of this structure, in bytes. Your application must fill this member before sending any messages that use the address of this structure as a parameter.

### `fMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that indicate which members of this structure are valid or must be filled. This value can be a combination of the following:

| Value | Meaning |
| --- | --- |
| **RBBIM_BACKGROUND** | The **hbmBack** member is valid or must be set. |
| **RBBIM_CHILD** | The **hwndChild** member is valid or must be set. |
| **RBBIM_CHILDSIZE** | The **cxMinChild**, **cyMinChild**, **cyChild**, **cyMaxChild**, and **cyIntegral** members are valid or must be set. |
| **RBBIM_COLORS** | The **clrFore** and **clrBack** members are valid or must be set. |
| **RBBIM_HEADERSIZE** | [Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **cxHeader** member is valid or must be set. |
| **RBBIM_IDEALSIZE** | [Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **cxIdeal** member is valid or must be set. |
| **RBBIM_ID** | The **wID** member is valid or must be set. |
| **RBBIM_IMAGE** | The **iImage** member is valid or must be set. |
| **RBBIM_LPARAM** | [Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **lParam** member is valid or must be set. |
| **RBBIM_SIZE** | The **cx** member is valid or must be set. |
| **RBBIM_STYLE** | The **fStyle** member is valid or must be set. |
| **RBBIM_TEXT** | The **lpText** member is valid or must be set. |
| **RBBIM_CHEVRONLOCATION** | The **rcChevronLocation** member is valid or must be set. |
| **RBBIM_CHEVRONSTATE** | The **uChevronState** member is valid or must be set. |

### `fStyle`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that specify the band style. This value can be a combination of the following:

| Value | Meaning |
| --- | --- |
| **RBBS_BREAK** | The band is on a new line. |
| **RBBS_CHILDEDGE** | The band has an edge at the top and bottom of the child window. |
| **RBBS_FIXEDBMP** | The background bitmap does not move when the band is resized. |
| **RBBS_FIXEDSIZE** | The band can't be sized. With this style, the sizing grip is not displayed on the band. |
| **RBBS_GRIPPERALWAYS** | [Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The band will always have a sizing grip, even if it is the only band in the rebar. |
| **RBBS_HIDDEN** | The band will not be visible. |
| **RBBS_NOGRIPPER** | [Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The band will never have a sizing grip, even if there is more than one band in the rebar. |
| **RBBS_USECHEVRON** | [Version 5.80.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) Show a chevron button if the band is smaller than **cxIdeal**. |
| **RBBS_VARIABLEHEIGHT** | [Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The band can be resized by the rebar control; **cyIntegral** and **cyMaxChild** affect how the rebar will resize the band. |
| **RBBS_NOVERT** | Do not show when vertical. |
| **RBBS_HIDETITLE** | Keep band title hidden. |
| **RBBS_TOPALIGN** | Keep band in top row. |

### `clrFore`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Band foreground colors.

### `clrBack`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Band background colors. If **hbmBack** specifies a background bitmap, these members are ignored. By default, the band will use the background color of the rebar control set with the [RB_SETBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/rb-setbkcolor) message. If a background color is specified here, then this background color will be used instead.

### `lpText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a buffer that contains the display text for the band. If band information is being requested from the control and RBBIM_TEXT is specified in **fMask**, this member must be initialized to the address of the buffer that will receive the text.

### `cch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the buffer at **lpText**, in bytes. If information is not being requested from the control, this member is ignored.

### `iImage`

Type: **int**

Zero-based index of any image that should be displayed in the band. The image list is set using the [RB_SETBARINFO](https://learn.microsoft.com/windows/desktop/Controls/rb-setbarinfo) message.

### `hwndChild`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the child window contained in the band, if any.

### `cxMinChild`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum width of the child window, in pixels. The band can't be sized smaller than this value.

### `cyMinChild`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum height of the child window, in pixels. The band can't be sized smaller than this value.

### `cx`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of the band, in pixels.

### `hbmBack`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a bitmap that is used as the background for this band.

### `wID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

UINT value that the control uses to identify this band for custom draw notification messages.

### `cyChild`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Initial height of the band, in pixels. This member is ignored unless the RBBS_VARIABLEHEIGHT style is specified.

### `cyMaxChild`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Maximum height of the band, in pixels. This member is ignored unless the RBBS_VARIABLEHEIGHT style is specified.

### `cyIntegral`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Step value by which the band can grow or shrink, in pixels. If the band is resized, it will be resized in steps specified by this value. This member is ignored unless the RBBS_VARIABLEHEIGHT style is specified.

### `cxIdeal`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Ideal width of the band, in pixels. If the band is maximized to the ideal width (see [RB_MAXIMIZEBAND](https://learn.microsoft.com/windows/desktop/Controls/rb-maximizeband)), the rebar control will attempt to make the band this width.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Application-defined value.

### `cxHeader`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Size of the band's header, in pixels. The band header is the area between the edge of the band and the edge of the child window. This is the area where band text and images are displayed, if they are specified. If this value is specified, it will override the normal header dimensions that the control calculates for the band.

### `rcChevronLocation`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[Version 6](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Location of the chevron.

### `uChevronState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 6](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). A combination of the [Object State Constants](https://learn.microsoft.com/windows/desktop/WinAuto/object-state-constants).

## Remarks

The **cxMinChild**, **cyMinChild**, and **cx** members provide information on dimensions relative to the orientation of the control. That is, for a horizontal rebar control, **cxMinChild** and **cx** are horizontal measurements and **cyMinChild** is a vertical measurement. However, if the control uses the [CCS_VERT](https://learn.microsoft.com/windows/desktop/Controls/common-control-styles) style, **cxMinChild** and **cx** are vertical measurements and **cyMinChild** is a horizontal measurement.

> [!NOTE]
> The commctrl.h header defines REBARBANDINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).