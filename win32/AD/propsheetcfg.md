# PROPSHEETCFG structure

The **PROPSHEETCFG** structure is used to contain property sheet configuration data. This structure is contained in the [**CFSTR\_DS\_PROPSHEETCONFIG**](https://learn.microsoft.com/windows/win32/ad/cfstr-ds-propsheetconfig) clipboard format.

> [!Note]
> This structure is not defined in a published header file. To use this structure, you must define it yourself in the exact format shown.

## Members

**lNotifyHandle**

Contains the notification handle. This is identical to the handle passed for the *handle* parameter in the [**IExtendPropertySheet2::CreatePropertyPages**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)) method.

**hwndParentSheet**

Contains the window handle of the parent property sheet.

**hwndHidden**

Contains the handle of the hidden window.

**wParamSheetClose**

Contains an application-defined 32-bit value. This value is passed back to the application in the *wParam* of the [**WM\_DSA\_SHEET\_CLOSE\_NOTIFY**](https://learn.microsoft.com/windows/win32/ad/wm-dsa-sheet-close-notify) message.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |

## See also

[**CFSTR\_DS\_PROPSHEETCONFIG**](https://learn.microsoft.com/windows/win32/ad/cfstr-ds-propsheetconfig)

[**WM\_DSA\_SHEET\_CLOSE\_NOTIFY**](https://learn.microsoft.com/windows/win32/ad/wm-dsa-sheet-close-notify)

