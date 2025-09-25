# OLEUICHANGESOURCEW structure

## Description

Contains information that is used to initialize the standard **Change Source** dialog box. It allows the user to modify the destination or source of a link. This may simply entail selecting a different file name for the link, or possibly changing the item reference within the file, for example, changing the destination range of cells within the spreadsheet that the link is to.

## Members

### `cbStruct`

The size of the structure, in bytes.

### `dwFlags`

On input, this field specifies the initialization and creation flags. On exit, it specifies the user's choices. It may be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **CSF_SHOWHELP** | Enables or shows the Help button. |
| **CSF_VALIDSOURCE** | Indicates that the link was validated. |
| **CSF_ONLYGETSOURCE** | Disables automatic validation of the link source when the user presses **OK**. If you specify this flag, you should validate the source when the dialog box returns **OK**. |

### `hWndOwner`

The window that owns the dialog box.

### `lpszCaption`

Pointer to a string to be used as the title of the dialog box. If **NULL**, then the library uses **Change Source**.

### `lpfnHook`

Pointer to a hook function that processes messages intended for the dialog box. The hook function must return zero to pass a message that it didn't process back to the dialog box procedure in the library. The hook function must return a nonzero value to prevent the library's dialog box procedure from processing a message it has already processed.

### `lCustData`

Application-defined data that the library passes to the hook function pointed to by the [OLEUICHANGEICON](https://learn.microsoft.com/windows/win32/api/oledlg/nf-oledlg-oleuichangeicona) structure in the *lParam* parameter of the WM_INITDIALOG message; this pointer can be used to retrieve the **lCustData** member.

### `hInstance`

Instance that contains a dialog box template specified by the **lpszTemplate** member. This member is ignored if the **lpszTemplate** member is **NULL** or invalid.

### `lpszTemplate`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the library's **Convert** dialog box template.

### `hResource`

Resource handle for a custom dialog box. If this member is **NULL**, then the library uses the standard **Convert** dialog box template, or if it is valid, the template named by the **lpszTemplate** member.

### `lpOFN`

Pointer to the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure, which contains information used by the operating system to initialize the system-defined **Open** or **Save As** dialog boxes.

### `dwReserved1`

This member is reserved.

### `lpOleUILinkContainer`

Pointer to the container's implementation of the [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera) interface, used to validate the link source. The **Edit Links** dialog box uses this to allow the container to manipulate its links.

### `dwLink`

Container-defined unique link identifier used to validate link sources. Used by **lpOleUILinkContainer**.

### `lpszDisplayName`

Pointer to the complete source display name.

### `nFileLength`

File moniker portion of **lpszDisplayName**.

### `lpszFrom`

Pointer to the prefix of the source that was changed from.

### `lpszTo`

Pointer to the prefix of the source to be changed to.

## See also

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OleUIChangeSource](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuichangesourcea)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUICHANGESOURCE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).