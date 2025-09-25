# PFNPROPSHEETCALLBACK callback function

## Description

An application-defined callback function that the system calls when the property sheet is being created and initialized.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet. This parameter is typically called *hWnd*.

### `unnamedParam2`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Message being received. This parameter is typically called *uMsg*.

This parameter is one of the following values.

| Value | Meaning |
| --- | --- |
| **PSCB_INITIALIZED (1)** | Indicates that the property sheet is being initialized. The *lParam* (*unnamedParam3*) value is zero for this message. |
| **PSCB_PRECREATE (2)** | Indicates that the property sheet is about to be created. The *hWnd* (*unnamedParam1*) parameter is **NULL**, and the *lParam* (*unnamedParam3*) parameter is the address of a dialog template in memory. This template is in the form of a [DLGTEMPLATE](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-dlgtemplate) or [DLGTEMPLATEEX](https://learn.microsoft.com/windows/win32/dlgbox/dlgtemplateex) structure followed by one or more [DLGITEMTEMPLATE](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-dlgitemtemplate) structures. This message is not applicable if you are using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/win32/controls/pss-propsheetheader)). |
| **PSCB_BUTTONPRESSED (3)** | [Version 6.0](https://learn.microsoft.com/windows/win32/Controls/common-control-versions) and later. Indicates the user pressed a button in the property sheet dialog box. To enable this, specify PSH_USECALLBACK in [PROPSHEETHEADER.dwFlags](https://learn.microsoft.com/windows/win32/controls/pss-propsheetheader) and specify the name of this callback function in **PROPSHEETHEADER.pfnCallback**. The *lParam* (*Arg3*) value is one of the following. Note that only PSBTN_CANCEL is valid when you are using the Aero wizard style (**PSH_AEROWIZARD**).<br><br>| Button pressed | lParam value | | --- | --- | | OK | PSBTN_OK | | Cancel | PSBTN_CANCEL | | Apply | PSBTN_APPLYNOW | | Close | PSBTN_FINISH |<br><br>Note that Comctl32.dll versions 6 and later are not redistributable. To use these versions of Comctl32.dll, specify the particular version in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/win32/controls/cookbook-overview). |

### `unnamedParam3`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Additional information about the message. This parameter is typically called *lParam*.

The meaning of this value depends on the *uMsg* (*unnamedParam2*) parameter:

* If *uMsg* is PSCB_INITIALIZED or PSCB_BUTTONPRESSED, the value of this parameter is zero.
* If *uMsg* is PSCB_PRECREATE, then this parameter will be a pointer to either a [DLGTEMPLATE](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-dlgtemplate) or [DLGTEMPLATEEX](https://learn.microsoft.com/windows/win32/dlgbox/dlgtemplateex) structure describing the property sheet dialog box. Test the signature of the structure to determine the type. If signature is equal to 0xFFFF then the structure is an extended dialog template, otherwise the structure is a standard dialog template. The following example demonstrates how to do this.

```cpp
    if (uMsg == PSCB_PRECREATE)
    {
         if (lParam)
         {
              DLGTEMPLATE *pDlgTemplate;
              DLGTEMPLATEEX *pDlgTemplateEx;

              pDlgTemplateEx = (DLGTEMPLATEEX *)lParam;
              if (pDlgTemplateEx->signature == 0xFFFF)
              {
                   // pDlgTemplateEx points to an extended
                   // dialog template structure.
              }
              else
              {
                   // This is a standard dialog template
                   //  structure.
                   pDlgTemplate = (DLGTEMPLATE *)lParam;
              }
         }
    }
    ```

## Return value

Type: **int**

Returns zero.

## Remarks

To enable a *PropSheetProc* callback function, use the [PROPSHEETHEADER](https://learn.microsoft.com/windows/win32/controls/pss-propsheetheader) structure when you call the [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function to create the property sheet. Use the *pfnCallback* member to specify an address of the callback function, and set the PSP_USECALLBACK flag in the *dwFlags* member.

*PropSheetProc* is a placeholder for the application-defined function name. The **PFNPROPSHEETCALLBACK** type is the address of a *PropSheetProc* callback function.