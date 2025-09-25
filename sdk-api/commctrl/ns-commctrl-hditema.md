# HDITEMA structure

## Description

Contains information about an item in a header control. This structure supersedes the **HD_ITEM** structure.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags indicating which other structure members contain valid data or must be filled in. This member can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| **HDI_BITMAP** | The **hbm** member is valid. |
| **HDI_DI_SETITEM** | While handling the message [HDM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/hdm-getitem), the header control may not have all the values needed to complete the request. In this case, the control must call the application back for the values via the [HDN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/hdn-getdispinfo) notification. If HDI_DI_SETITEM has been passed in the **HDM_GETITEM** message, the control will cache any values returned from HDN_GETDISPINFO (otherwise the values remain unset.) |
| **HDI_FORMAT** | The **fmt** member is valid. |
| **HDI_FILTER** | The **type** and **pvFilter** members are valid. This is used to filter out the values specified in the **type** member. |
| **HDI_HEIGHT** | The same as HDI_WIDTH. |
| **HDI_IMAGE** | The **iImage** member is valid and specifies the image to be displayed with the item. |
| **HDI_LPARAM** | The **lParam** member is valid. |
| **HDI_ORDER** | The **iOrder** member is valid and specifies the item's order value. |
| **HDI_STATE** | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **state** member is valid. |
| **HDI_TEXT** | The **pszText** and **cchTextMax** members are valid. |
| **HDI_WIDTH** | The **cxy** member is valid and specifies the item's width. |

### `cxy`

Type: **int**

The width or height of the item.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to an item string. If the text is being retrieved from the control, this member must be initialized to point to a character buffer. If this member is set to LPSTR_TEXTCALLBACK, the control will request text information for this item by sending an [HDN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/hdn-getdispinfo) notification code. Note that although the header control allows a string of any length to be stored as item text, only the first 260 **TCHAR****s** are displayed.

### `hbm`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the item bitmap.

### `cchTextMax`

Type: **int**

The length of the item string, in **TCHAR****s**. If the text is being retrieved from the control, this member must contain the number of **TCHAR****s** at the address specified by **pszText**.

### `fmt`

Type: **int**

Flags that specify the item's format.

| Value | Meaning |
| --- | --- |
| **Text Justification:** | Set one of the following flags to specify text justification: |
| **HDF_CENTER** | The item's contents are centered. |
| **HDF_LEFT** | The item's contents are left-aligned. |
| **HDF_RIGHT** | The item's contents are right-aligned. |
| **Display:** | Set one of the following flags to control the display: |
| **HDF_BITMAP** | The item displays a bitmap. |
| **HDF_BITMAP_ON_RIGHT** | The bitmap appears to the right of text. |
| **HDF_OWNERDRAW** | The header control's owner draws the item. |
| **HDF_STRING** | The item displays a string. |
| **Combining Flags:** | The preceding value can be combined with: |
| **HDF_IMAGE** | Display an image from an image list. Specify the image list by sending an [HDM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/hdm-setimagelist) message. Specify the index of the image in the **iImage** member of this structure. |
| **HDF_JUSTIFYMASK** | Isolate the bits corresponding to the three justification flags listed in the preceding table. |
| **HDF_RTLREADING** | Typically, windows displays text left-to-right (LTR). Windows can be *mirrored* to display languages such as Hebrew or Arabic that read right-to-left (RTL). Usually, header text is read in the same direction as the text in its parent window. If HDF_RTLREADING is set, header text will read in the opposite direction from the text in the parent window. |
| **HDF_SORTDOWN** | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Draws a down-arrow on this item. This is typically used to indicate that information in the current window is sorted on this column in descending order. This flag cannot be combined with HDF_IMAGE or HDF_BITMAP. |
| **HDF_SORTUP** | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Draws an up-arrow on this item. This is typically used to indicate that information in the current window is sorted on this column in ascending order. This flag cannot be combined with HDF_IMAGE or HDF_BITMAP. |
| **HDF_CHECKBOX** | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The item displays a checkbox. The flag is only valid when the [HDS_CHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/header-control-styles) style is first set on the header control. |
| **HDF_CHECKED** | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The item displays a checked checkbox. The flag is only valid when HDF_CHECKBOX is also set. |
| **HDF_FIXEDWIDTH** | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The width of the item cannot be modified by a user action to resize it. |
| **HDF_SPLITBUTTON** | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The item displays a split button. The HDN_DROPDOWN notification is sent when the split button is clicked. |

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined item data.

### `iImage`

Type: **int**

The zero-based index of an image within the image list. The specified image will be displayed in the header item in addition to any image specified in the **hbm** field. If **iImage** is set to I_IMAGECALLBACK, the control requests text information for this item by using an [HDN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/hdn-getdispinfo) notification code. To clear the image, set this value to I_IMAGENONE.

### `iOrder`

Type: **int**

The order in which the item appears within the header control, from left to right. That is, the value for the far left item is 0. The value for the next item to the right is 1, and so on.

### `type`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The type of filter specified by **pvFilter**. The possible types include:

| Value | Meaning |
| --- | --- |
| **HDFT_ISSTRING** | String data. |
| **HDFT_ISNUMBER** | Numerical data. |
| **HDFT_HASNOVALUE** | Ignore **pvFilter**. |
| **HDFT_ISDATE** | [Version 6.00 and later](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Date data. The **pvFilter** member is a pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. |

### `pvFilter`

Type: **void***

The address of an application-defined data item. The data filter type is determined by setting the flag value of the member. Use the HDFT_ISSTRING flag to indicate a string and HDFT_ISNUMBER to indicate an integer. When the HDFT_ISSTRING flag is used **pvFilter** is a pointer to a [HDTEXTFILTER](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-hd_textfiltera) structure.

### `state`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The state. The only valid, supported value for this member is the following:

| Value | Meaning |
| --- | --- |
| HDIS_FOCUSED | The item has keyboard focus. |

## Remarks

**Note** Comctl32.dll version 6 is not redistributable but it is included in Windows. To use Comctl32.dll version 6, specify it in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

> [!NOTE]
> The commctrl.h header defines HDITEM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).