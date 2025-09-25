# OLEUIEDITLINKSA structure

## Description

Contains information that the OLE User Interface Library uses to initialize the **Edit Links** dialog box, and contains space for the library to return information when the dialog box is dismissed.

## Members

### `cbStruct`

The size of the structure, in bytes. This member must be filled on input.

### `dwFlags`

On input, **dwFlags** specifies the initialization and creation flags. It may be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **ELF_SHOWHELP** | Specifies that the dialog box will display a **Help** button. |
| **ELF_DISABLEUPDATENOW** | Specifies that the **Update Now** button will be disabled on initialization. |
| **ELF_DISABLEOPENSOURCE** | Specifies that the **Open Source** button will be disabled on initialization. |
| **ELF_DISABLECHANGESOURCE** | Specifies that the **Change Source** button will be disabled on initialization. |
| **ELF_DISABLECANCELLINK** | Specifies that the **Cancel Link** button will be disabled on initialization. |

### `hWndOwner`

The window that owns the dialog box. This member should not be **NULL**.

### `lpszCaption`

Pointer to a string to be used as the title of the dialog box. If **NULL**, then the library uses **Links**.

### `lpfnHook`

Pointer to a hook function that processes messages intended for the dialog box. The hook function must return zero to pass a message that it didn't process back to the dialog box procedure in the library. The hook function must return a nonzero value to prevent the library's dialog box procedure from processing a message it has already processed.

### `lCustData`

Application-defined data that the library passes to the hook function pointed to by the **lpfnHook** member. The library passes a pointer to the **OLEUIEDITLINKS** structure in the *lParam* parameter of the WM_INITDIALOG message; this pointer can be used to retrieve the **lCustData** member.

### `hInstance`

Instance that contains a dialog box template specified by the **lpTemplateName** member.

### `lpszTemplate`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the library's **Edit Links** dialog box template.

### `hResource`

Customized template handle.

### `lpOleUILinkContainer`

Pointer to the container's implementation of the [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera) Interface. The **Edit Links** dialog box uses this to allow the container to manipulate its links.

## See also

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUIEDITLINKS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).