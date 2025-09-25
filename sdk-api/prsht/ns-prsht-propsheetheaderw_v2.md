# PROPSHEETHEADERW_V2 structure

## Description

Defines the frame and pages of a property sheet.

> [!NOTE]
> This structure is not intended to be used directly in your code. Instead, use the [PROPSHEETHEADER](https://learn.microsoft.com/windows/win32/controls/pss-propsheetheader) structure.

## Members

### `DUMMYUNIONNAME4`

### `DUMMYUNIONNAME4.hbmWatermark`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Handle to the watermark bitmap. If the **dwFlags** member does not include PSH_USEHBMWATERMARK, this member is ignored.

### `DUMMYUNIONNAME4.pszbmWatermark`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Bitmap resource to use as the watermark. This member can specify either the identifier of the bitmap resource or the address of the string that specifies the name of the bitmap resource. If the **dwFlags** member includes PSH_USEHBMWATERMARK, this member is ignored.

### `hplWatermark`

Type: **[HPALETTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. **HPALETTE** structure used for drawing the watermark bitmap and/or header bitmap. If the **dwFlags** member does not include PSH_USEHPLWATERMARK, this member is ignored.

### `DUMMYUNIONNAME5`

### `DUMMYUNIONNAME5.hbmHeader`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Handle to the header bitmap. If the **dwFlags** member does not include PSH_USEHBMHEADER, this member is ignored.

### `DUMMYUNIONNAME5.pszbmHeader`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Bitmap resource to use as the header. This member can specify either the identifier of the bitmap resource or the address of the string that specifies the name of the bitmap resource. If the **dwFlags** member includes PSH_USEHBMHEADER, this member is ignored.

#### - dwFlags

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that indicate which options to use when creating the property sheet page. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **PSH_DEFAULT**<br><br>0x00000000 | Uses the default meaning for all structure members, and creates a normal property sheet. This flag has a value of zero and is not combined with other flags. |
| **PSH_AEROWIZARD**<br><br>0x00004000 | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.**. Creates a wizard property sheet that uses the newer Aero style. The PSH_WIZARD flag must also be set. The single-threaded apartment (STA) model must be used. |
| **PSH_HASHELP**<br><br>0x00000200 | Permits property sheet pages to display a **Help** button. You must also set the PSP_HASHELP flag in the page's [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure when the page is created. If any of the initial property sheet pages enable a **Help** button, PSH_HASHELP will be set automatically. If none of the initial pages enable a **Help** button, you must explicitly set PSH_HASHELP if you want to have **Help** buttons on any pages that might be added later. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_HEADER**<br><br>0x00080000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and later. Indicates that a header bitmap will be used with a Wizard97 wizard. You must also set the PSH_WIZARD97 flag. The header bitmap is obtained from the **pszbmHeader** member, unless the PSH_USEHBMHEADER flag is also set. In that case, the header bitmap is obtained from the **hbmHeader** member. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_HEADERBITMAP**<br><br>0x08000000 | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.**.The **pszbmHeader** member specifies a bitmap that is displayed in the header area. Must be used in combination with PSH_AEROWIZARD. |
| **PSH_MODELESS**<br><br>0x00000400 | Causes the [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function to create the property sheet as a modeless dialog box instead of as a modal dialog box. When this flag is set, **PropertySheet** returns immediately after the dialog box is created, and the return value from **PropertySheet** is the window handle to the property sheet dialog box. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_NOAPPLYNOW**<br><br>0x00000080 | Removes the **Apply** button. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_NOCONTEXTHELP**<br><br>0x02000000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and later. Removes the context-sensitive **Help** button ("?"), which is usually present on the caption bar of property sheets. This flag is not valid for wizards. See [About Property Sheets](https://learn.microsoft.com/windows/desktop/Controls/property-sheets) for a discussion of how to remove the caption bar **Help** button for earlier versions of the common controls. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_NOMARGIN**<br><br>0x10000000 | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.**. Specifies that no margin is inserted between the page and the frame. Must be used in combination with PSH_AEROWIZARD. |
| **PSH_PROPSHEETPAGE**<br><br>0x00000008 | Uses the **ppsp** member and ignores the **phpage** member when creating the pages for the property sheet. |
| **PSH_PROPTITLE**<br><br>0x00000001 | Displays a title in the title bar of the property sheet. The title takes the appropriate form for the Windows version. In more recent versions of Windows, the title is the string specified by the **pszCaption** followed by the string "Properties". In older versions of Windows, the title is the string "Properties for", followed by the string specified by the **pszCaption** member. This flag is not supported for wizards. |
| **PSH_RESIZABLE**<br><br>0x04000000 | Allows the wizard to be resized by the user. Maximize and minimize buttons appear in the wizard's frame and the frame is sizable. To use this flag, you must also set PSH_AEROWIZARD. |
| **PSH_RTLREADING**<br><br>0x00000800 | Displays the title of the property sheet (**pszCaption**) using right-to-left (RTL) reading order for Hebrew or Arabic languages. If this flag is not specified, the title is displayed in left-to-right (LTR) reading order. |
| **PSH_STRETCHWATERMARK**<br><br>0x00040000 | Stretches the watermark in Internet Explorer 4.0-compatible Wizard97-style wizards. This flag is not supported in conjunction with PSH_AEROWIZARD.<br><br>**Note** This style flag is only included to provide backward compatibility for certain applications. Its use is not recommended, and it is only supported by common controls [versions 4.0 and 4.01](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). With common controls version 5.80 and later, this flag is ignored. |
| **PSH_USECALLBACK**<br><br>0x00000100 | Calls the function specified by the **pfnCallback** member when initializing the property sheet defined by this structure. |
| **PSH_USEHBMHEADER**<br><br>0x00100000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Obtains the header bitmap from the **hbmHeader** member instead of the **pszbmHeader** member. You must also set either the PSH_AEROWIZARD flag or the PSH_WIZARD97 flag together with the PSH_HEADER flag. |
| **PSH_USEHBMWATERMARK**<br><br>0x00010000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Obtains the watermark bitmap from the **hbmWatermark** member instead of the **pszbmWatermark** member. You must also set PSH_WIZARD97 and PSH_WATERMARK. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_USEHICON**<br><br>0x00000002 | Uses **hIcon** as the small icon in the title bar of the property sheet dialog box. |
| **PSH_USEHPLWATERMARK**<br><br>0x00020000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Uses the **HPALETTE** structure pointed to by the **hplWatermark** member instead of the default palette to draw the watermark bitmap and/or header bitmap for a Wizard97 wizard. You must also set PSH_WIZARD97, and PSH_WATERMARK or PSH_HEADER. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_USEICONID**<br><br>0x00000004 | Uses **pszIcon** as the name of the icon resource to load and use as the small icon in the title bar of the property sheet dialog box. |
| **PSH_USEPAGELANG**<br><br>0x00200000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Specifies that the language for the property sheet will be taken from the first page's resource. That page must be specified by resource identifier. |
| **PSH_USEPSTARTPAGE**<br><br>0x00000040 | Uses the **pStartPage** member instead of the **nStartPage** member when displaying the initial page of the property sheet. |
| **PSH_WATERMARK**<br><br>0x00008000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Specifies that a watermark bitmap will be used with a Wizard97 wizard on pages that have the PSP_HIDEHEADER style. You must also set the PSH_WIZARD97 flag. The watermark bitmap is obtained from the **pszbmWatermark** member, unless PSH_USEHBMWATERMARK is set. In that case, the header bitmap is obtained from the **hbmWatermark** member. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_WIZARD**<br><br>0x00000020 | Creates a wizard property sheet. When using PSH_AEROWIZARD, you must also set this flag. |
| **PSH_WIZARD97**<br><br>0x00002000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Creates a Wizard97-style property sheet, which supports bitmaps in the header of interior pages and on the left side of exterior pages. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_WIZARDCONTEXTHELP**<br><br>0x00001000 | Adds a context-sensitive **Help** button ("?"), which is usually absent from the caption bar of a wizard. This flag is not valid for regular property sheets. This flag is not supported in conjunction with PSH_AEROWIZARD. |
| **PSH_WIZARDHASFINISH**<br><br>0x00000010 | Always displays the **Finish** button on the wizard. You must also set either PSH_WIZARD, PSH_WIZARD97, or PSH_AEROWIZARD. |
| **PSH_WIZARD_LITE**<br><br>0x00400000 | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Uses the Wizard-lite style. This style is similar in appearance to PSH_WIZARD97, but it is implemented much like PSH_WIZARD. There are few restrictions on how the pages are formatted. For instance, there are no enforced borders, and the PSH_WIZARD_LITE style does not paint the watermark and header bitmaps for you the way Wizard97 does. This flag is not supported in conjunction with PSH_AEROWIZARD. |

#### - dwSize

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size, in bytes, of this structure. The property sheet manager uses this member to determine which version of the **PROPSHEETHEADER** structure you are using. For more information, see the Remarks.

#### - hIcon

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the icon to use as the small icon in the title bar of the property sheet dialog box. If the **dwFlags** member does not include PSH_USEHICON, this member is ignored. This member is declared as a union with **pszIcon**.

#### - hInstance

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the instance from which to load the icon or title string resource. If the **pszIcon** or **pszCaption** member identifies a resource to load, this member must be specified.

#### - hwndParent

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet's owner window.

#### - nPages

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of elements in the **phpage** array.

#### - nStartPage

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the initial page that appears when the property sheet dialog box is created. This member is declared as a union with **pStartPage**.

#### - pStartPage

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the initial page that appears when the property sheet dialog box is created. This member can specify either the identifier of a string resource or the address of a string that specifies the name. This member is declared as a union with **nStartPage**.

#### - pfnCallback

Type: **PFNPROPSHEETCALLBACK**

Pointer to an application-defined callback function that is called when the property sheet is initialized. For more information about the callback function, see the description of the [PropSheetProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-pfnpropsheetcallback) function. If the
**dwFlags** member does not include PSH_USECALLBACK, this member is ignored.

#### - phpage

Type: **HPROPSHEETPAGE***

Pointer to an array of handles to the property sheet pages. Each handle must have been created by a previous call to the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function. If the **dwFlags** member includes PSH_PROPSHEETPAGE, **phpage** is ignored and should be set to **NULL**. When the [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function returns, any HPROPSHEETPAGE handles in the **phpage** array will have been destroyed. This member is declared as a union with **ppsp**.

#### - ppsp

Type: **LPCPROPSHEETPAGE**

Pointer to an array of [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structures that define the pages in the property sheet. If the **dwFlags** member does not include PSH_PROPSHEETPAGE, this member is ignored. Note that the **PROPSHEETPAGE** structure is variable in size. Applications that parse the array pointed to by **ppsp** must take the size of each page into account. This member is declared as a union with **phpage**.

#### - pszCaption

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Title of the property sheet dialog box. This member can specify either the identifier of a string resource or the address of a string that specifies the title. If the **dwFlags** member includes PSH_PROPTITLE, the string "Properties for" is inserted at the beginning of the title. This field is ignored for Wizard97 wizards. For Aero wizards, the string alone is used for the caption, regardless of whether the PSH_PROPTITLE flag is set.

#### - pszIcon

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Icon resource to use as the small icon in the title bar of the property sheet dialog box. This member can specify either the identifier of the icon resource or the address of the string that specifies the name of the icon resource. If the **dwFlags** member does not include PSH_USEICONID, this member is ignored. This member is declared as a union with **hIcon**.

## Remarks

If the user chooses a setting such as Large Fonts, which enlarges the dialog box, the watermark that is painted on the start and finish pages will be enlarged as well. The size and position of the original bitmap will remain the same. The additional area will be filled with the color of the pixel in the upper-left corner of the bitmap.

Note that several members of this structure are only supported for Comctl32.dll versions 4.71 and later. You can enable these members by including one of the following in your header.

`#define _WIN32_IE 0x0400 // For version 4.71`

or

`#define _WIN32_IE 0x0500 // For version 5.80`

However, you must initialize the structure with its size. If you use the size of the currently defined structure, the application may not run with the earlier versions of Comctl32.dll, which expect a smaller structure. This includes all systems with Windows 95 or Microsoft Windows NT 4.0 that do not have Internet Explorer 4.0 or later installed. You can run your application on pre-4.71 versions of Comctl32.dll by defining the appropriate [version number](https://learn.microsoft.com/windows/desktop/Controls/common-controls-intro). However, this may cause problems if your application also needs to run on systems with more recent versions.

You can remain compatible with all Comctl32.dll versions by using the current header files and setting the size of the **PROPSHEETHEADER** structure appropriately. Before you initialize the structure, use the [DllGetVersion](https://learn.microsoft.com/windows/desktop/api/shlwapi/nc-shlwapi-dllgetversionproc) function to determine which Comctl32.dll version is installed on the system. If it is version 4.71 or greater, use

`psh.dwSize = sizeof(PROPSHEETHEADER);`

to initialize the **dwSize** member. For earlier versions, the size of the pre-4.71 structure is given by the PROPSHEETHEADER_V1_SIZE constant. Use

`psh.dwSize = PROPSHEETHEADER_V1_SIZE;`

The PSH_WIZARD, PSH_WIZARD97, and PSH_WIZARD_LITE styles are mutually incompatible. Only one of these style flags should be set. PSH_AEROWIZARD should be combined with PSH_WIZARD.