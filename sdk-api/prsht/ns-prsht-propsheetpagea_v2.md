# PROPSHEETPAGEA_V2 structure

## Description

Defines a page in a property sheet.

> [!NOTE]
> This structure is not intended to be used directly in your code. Instead, use the [PROPSHEETPAGE](https://learn.microsoft.com/windows/win32/controls/pss-propsheetpage) structure.

## Members

### `pszHeaderTitle`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Title of the header area. To use this member under the Wizard97-style wizard, you must also do the following:

* Set the PSP_USEHEADERTITLE flag in the **dwFlags** member.
* Set the PSH_WIZARD97 flag in the **dwFlags** member of the page's [PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2) structure.
* Make sure that the PSP_HIDEHEADER flag in the **dwFlags** member is not set.

### `pszHeaderSubTitle`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Subtitle of the header area. To use this member, you must do the following:

* Set the PSP_USEHEADERSUBTITLE flag in the **dwFlags** member.
* Set the PSH_WIZARD97 flag in the **dwFlags** member of the page's [PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2) structure.
* Make sure that the PSP_HIDEHEADER flag in the **dwFlags** member is not set.

**Note** This member is ignored when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).

#### - dwFlags

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that indicate which options to use when creating the property sheet page. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **PSP_DEFAULT** | Uses the default meaning for all structure members. This flag is not supported when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)). |
| **PSP_DLGINDIRECT** | Creates the page from the dialog box template in memory pointed to by the **pResource** member. The [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function assumes that the template that is in memory is not write-protected. A read-only template will cause an exception in some versions of Windows. |
| **PSP_HASHELP** | Enables the property sheet **Help** button when the page is active. This flag is not supported when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)). |
| **PSP_HIDEHEADER** | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and later. Causes the wizard property sheet to hide the header area when the page is selected. If a watermark has been provided, it will be painted on the left side of the page. This flag should be set for welcome and completion pages, and omitted for interior pages. This flag is not supported when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)). |
| **PSP_PREMATURE** | [Version 4.71](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Causes the page to be created when the property sheet is created. If this flag is not specified, the page will not be created until it is selected the first time. This flag is not supported when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)). |
| **PSP_RTLREADING** | Reverses the direction in which **pszTitle** is displayed. Normal windows display all text, including **pszTitle**, left-to-right (LTR). For languages such as Hebrew or Arabic that read right-to-left (RTL), a window can be *mirrored* and all text will be displayed RTL. If PSP_RTLREADING is set, **pszTitle** will instead read RTL in a normal parent window, and LTR in a mirrored parent window. |
| **PSP_USECALLBACK** | Calls the function specified by the **pfnCallback** member when creating or destroying the property sheet page defined by this structure. |
| **PSP_USEFUSIONCONTEXT** | [Version 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and later. Use an activation context. To use an activation context, you must set this flag and assign the activation context handle to **hActCtx**. See the Remarks. |
| **PSP_USEHEADERSUBTITLE** | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Displays the string pointed to by the **pszHeaderSubTitle** member as the subtitle of the header area of a Wizard97 page. To use this flag, you must also set the PSH_WIZARD97 flag in the **dwFlags** member of the associated [PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2) structure. The PSP_USEHEADERSUBTITLE flag is ignored if PSP_HIDEHEADER is set. In Aero-style wizards, the title appears near the top of the client area. |
| **PSP_USEHEADERTITLE** | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. Displays the string pointed to by the **pszHeaderTitle** member as the title in the header of a Wizard97 interior page. You must also set the PSH_WIZARD97 flag in the **dwFlags** member of the associated [PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2) structure. The PSP_USEHEADERTITLE flag is ignored if PSP_HIDEHEADER is set. This flag is not supported when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)). |
| **PSP_USEHICON** | Uses **hIcon** as the small icon on the tab for the page. This flag is not supported when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)). |
| **PSP_USEICONID** | Uses **pszIcon** as the name of the icon resource to load and use as the small icon on the tab for the page. This flag is not supported when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)). |
| **PSP_USEREFPARENT** | Maintains the reference count specified by the **pcRefParent** member for the lifetime of the property sheet page created from this structure. |
| **PSP_USETITLE** | Uses the **pszTitle** member as the title of the property sheet dialog box instead of the title stored in the dialog box template. This flag is not supported when using the Aero-style wizard ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)). |

#### - dwSize

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size, in bytes, of this structure.

#### - hActCtx

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) or later. An activation context handle. Set this member to the handle that is returned when you create the activation context with [CreateActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createactctxa). The system will activate this context before creating the dialog box. You do not need to use this member if you use a global manifest. See the Remarks.

#### - hIcon

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the icon to use as the icon in the tab of the page. If the **dwFlags** member does not include PSP_USEHICON, this member is ignored. This member is declared as a union with **pszIcon**.

#### - hInstance

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the instance from which to load an icon or string resource. If the **pszIcon**, **pszTitle**, **pszHeaderTitle**, or **pszHeaderSubTitle** member identifies a resource to load, **hInstance** must be specified.

#### - lParam

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

When the page is created, a copy of the page's **PROPSHEETPAGE** structure is passed to the dialog box procedure with a [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. The **lParam** member is provided to allow you to pass application-specific information to the dialog box procedure. It has no effect on the page itself. For more information, see [Property Sheet Creation](https://learn.microsoft.com/windows/desktop/Controls/property-sheets).

#### - pResource

Type: **LPCDLGTEMPLATE**

Pointer to a dialog box template in memory. The [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function assumes that the template is not write-protected. A read-only template will cause an exception in some versions of Windows. To use this member, you must set the PSP_DLGINDIRECT flag in the **dwFlags** member. This member is declared as a union with **pszTemplate**.

#### - pcRefParent

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the reference count value. To use this member, you must set the PSP_USEREFPARENT flag in the **dwFlags** member.

**Note** When a property sheet page is created, the value pointed to by **pcRefParent** is incremented. You create a property sheet page implicitly by setting the PSH_PROPSHEETPAGE flag in the **dwFlags** member of [PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2) and calling the [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function. You can do it explicitly by using the [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) function. When a property sheet page is destroyed, the value pointed to by the **pcRefParent** member is decremented. This takes place automatically when the property sheet is destroyed. You can explicitly destroy a property sheet page by using the [DestroyPropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-destroypropertysheetpage) function.

#### - pfnCallback

Type: **LPFNPSPCALLBACK**

Pointer to an application-defined callback function that is called when the page is created and when it is about to be destroyed. For more information about the callback function, see [PropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnpspcallbacka). To use this member, you must set the PSP_USECALLBACK flag in the **dwFlags** member.

#### - pfnDlgProc

Type: **DLGPROC**

Pointer to the dialog box procedure for the page. Because the pages are created as modeless dialog boxes, the dialog box procedure must not call the [EndDialog](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enddialog) function.

#### - pszIcon

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Icon resource to use as the icon in the tab of the page. This member can specify either the identifier of the icon resource or the address of the string that specifies the name of the icon resource. To use this member, you must set the PSP_USEICONID flag in the **dwFlags** member. This member is declared as a union with **hIcon**.

#### - pszTemplate

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Dialog box template to use to create the page. This member can specify either the resource identifier of the template or the address of a string that specifies the name of the template. If the PSP_DLGINDIRECT flag in the **dwFlags** member is set, **pszTemplate** is ignored. This member is declared as a union with **pResource**.

#### - pszTitle

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Title of the property sheet dialog box. This title overrides the title specified in the dialog box template. This member can specify either the identifier of a string resource or the address of a string that specifies the title. To use this member, you must set the PSP_USETITLE flag in the **dwFlags** member.

## Remarks

Comctl32.dll version 6 and later are not redistributable. To use Comctl32.dll version 6 or later, specify the .dll file in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).