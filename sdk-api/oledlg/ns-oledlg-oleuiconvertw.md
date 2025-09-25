# OLEUICONVERTW structure

## Description

Contains information that the OLE User Interface Library uses to initialize the **Convert** dialog box, and space for the library to return information when the dialog box is dismissed.

## Members

### `cbStruct`

The size of the structure, in bytes. This member must be filled on input.

### `dwFlags`

On input, this field specifies the initialization and creation flags. On exit, it specifies the user's choices. It may be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **CF_SHOWHELPBUTTON** | Dialog box will display a **Help** button. This flag is set on input. |
| **CF_SETCONVERTDEFAULT** | Class whose CLSID is specified by **clsidConvertDefault** will be used as the default selection. This selection appears in the class listbox when the **Convert To** radio button is selected. This flag is set on input. |
| **CF_SETACTIVATEDEFAULT** | Class whose CLSID is specified by **clsidActivateDefault** will be used as the default selection. This selection appears in the class listbox when the **Activate As** radio button is selected. This flag is set on input. |
| **CF_SELECTCONVERTTO** | On input, this flag specifies that **Convert To** will be initially selected (default behavior). This flag is set on output if **Convert To** was selected when the user dismissed the dialog box. |
| **CF_SELECTACTIVATEAS** | On input, this flag specifies that **Activate As** will be initially selected. This flag is set on output if **Activate As** was selected when the user dismissed the dialog box. |
| **CF_DISABLEDISPLAYASICON** | The **Display As Icon** button will be disabled on initialization. |
| **CF_DISABLEACTIVATEAS** | The **Activate As** radio button will be disabled on initialization. |
| **CF_HIDECHANGEICON** | The **Change Icon** button will be hidden in the **Convert** dialog box. |
| **CF_CONVERTONLY** | The **Activate As** radio button will be disabled in the **Convert** dialog box. |

### `hWndOwner`

The window that owns the dialog box. This member should not be **NULL**.

### `lpszCaption`

Pointer to a string to be used as the title of the dialog box. If **NULL**, then the library uses **Convert**.

### `lpfnHook`

Pointer to a hook function that processes messages intended for the dialog box. The hook function must return zero to pass a message that it didn't process back to the dialog box procedure in the library. The hook function must return a nonzero value to prevent the library's dialog box procedure from processing a message it has already processed.

### `lCustData`

Application-defined data that the library passes to the hook function pointed to by the **lpfnHook** member. The library passes a pointer to the **OLEUICONVERT** structure in the *lParam* parameter of the WM_INITDIALOG message; this pointer can be used to retrieve the **lCustData** member.

### `hInstance`

Instance that contains a dialog box template specified by the **lpszTemplate** member. This member is ignored if the **lpszTemplate** member is **NULL** or invalid.

### `lpszTemplate`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the library's **Convert** dialog box template.

### `hResource`

Resource handle for a custom dialog box. If this member is **NULL**, then the library uses the standard **Convert** dialog box template, or if it is valid, the template named by the **lpszTemplate** member.

### `clsidConvertDefault`

The CLSID to use as the default class when **Convert To** is selected. This member is ignored if the **dwFlags** member does not include CF_SETCONVERTDEFAULT. This member is set on input.

### `clsidActivateDefault`

The CLSID to use as the default class when **Activate As** is selected. This member is ignored if the **dwFlags** member does not include CF_SETACTIVATEDEFAULT. This member is set on input.

### `clsidNew`

The CLSID of the selected class. This member is set on output.

### `clsid`

The CLSID of the object to be converted or activated. This member is set on input.

### `dvAspect`

Aspect of the object. This must be either DVASPECT_CONTENT or DVASPECT_ICON. If **dvAspect** is DVASPECT_ICON on input, then the **Display As Icon** box is checked and the object's icon is displayed. This member is set on input and output. For more information, see [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect).

### `wFormat`

Data format of the object to be converted or activated.

### `fIsLinkedObject`

**TRUE** if the object is linked. This member is set on input.

### `hMetaPict`

The [METAFILEPICT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metafilepict) containing the iconic aspect. This member is set on input and output.

### `lpszUserType`

Pointer to the User Type name of the object to be converted or activated. If this value is **NULL**, then the dialog box will retrieve the User Type name from the registry. This string is freed on exit.

### `fObjectsIconChanged`

**TRUE** if the object's icon changed. (that is, if [OleUIChangeIcon](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuichangeicona) was called and not canceled.). This member is set on output.

### `lpszDefLabel`

Pointer to the default label to use for the icon. If **NULL**, the short user type name will be used. If the object is a link, the caller should pass the display name of the link source. This is freed on exit.

### `cClsidExclude`

Number of CLSIDs in *lpClsidExclude*.

### `lpClsidExclude`

Pointer to the list of CLSIDs to exclude from the list.

## See also

[OleUIChangeIcon](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuichangeicona)

[OleUIConvert](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiconverta)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUICONVERT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).