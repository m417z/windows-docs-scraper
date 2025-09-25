# OLEUIPASTESPECIALA structure

## Description

Contains information that the OLE User Interface Library uses to initialize the **Paste Special** dialog box, as well as space for the library to return information when the dialog box is dismissed.

## Members

### `cbStruct`

The size of the structure, in bytes. This member must be filled on input.

### `dwFlags`

On input, **dwFlags** specifies the initialization and creation flags. On exit, it specifies the user's choices. It may be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **PSF_SHOWHELP** | Dialog box will display a **Help** button. |
| **PSF_SELECTPASTE** | The **Paste** radio button will be selected at dialog box startup. This is the default, if PSF_SELECTPASTE or PSF_SELECTPASTELINK are not specified. Also, it specifies the state of the button on dialog termination. IN/OUT flag. |
| **PSF_SELECTPASTELINK** | The **PasteLink** radio button will be selected at dialog box startup. Also, specifies the state of the button on dialog termination. IN/OUT flag. |
| **PSF_CHECKDISPLAYASICON** | Whether the **Display As Icon** radio button was checked on dialog box termination. OUT flag. |
| **PSF_DISABLEDISPLAYASICON** | The **Display As Icon** check box will be disabled on initialization. |
| **HIDECHANGEICON** | Used to disable the change-icon button in the dialog box, which is available to users when they're pasting an OLE object by default. See **STAYONCLIPBOARDCHANGE** otherwise. |
| **STAYONCLIPBOARDCHANGE** | Used to tell the dialog box to stay up if the clipboard changes while the dialog box is up. If the user switches to another application and copies or cuts something, the dialog box will, by default, perform a cancel operation, which will remove the dialog box since the options it's in the middle of presenting to the user are no longer up-to-date with respect to what's really on the clipboard. |
| **NOREFRESHDATAOBJECT** | Used in conjunction with **STAYONCLIPBOARDCHANGE** (it doesn't do anything otherwise). If the clipboard changes while the dialog box is up and **STAYONCLIPBOARDCHANGE** is specified, then **NOREFRESHDATAOBJECT** indicates that the dialog box should NOT refresh the contents of the dialog box to reflect the new contents of the clipboard. This is useful if the application is using the paste-special dialog box on an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) besides the one on the clipboard, for example, as part of a right-click drag-and-drop operation. |

### `hWndOwner`

The window that owns the dialog box. This member should not be **NULL**.

### `lpszCaption`

Pointer to a string to be used as the title of the dialog box. If **NULL**, then the library uses **Paste Special**.

### `lpfnHook`

Pointer to a hook function that processes messages intended for the dialog box. The hook function must return zero to pass a message that it didn't process back to the dialog box procedure in the library. The hook function must return a nonzero value to prevent the library's dialog box procedure from processing a message it has already processed.

### `lCustData`

Application-defined data that the library passes to the hook function pointed to by the **lpfnHook** member. The library passes a pointer to the **OLEUIPASTESPECIAL** structure in the **lParam** parameter of the WM_INITDIALOG message; this pointer can be used to retrieve the **lCustData** member.

### `hInstance`

Instance that contains a dialog box template specified by the **lpTemplateName** member.

### `lpszTemplate`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the library's **Paste Special** dialog box template.

### `hResource`

Customized template handle.

### `lpSrcDataObj`

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface of the data object to be pasted (from the clipboard). This member is filled on input. If **lpSrcDataObj** is **NULL** when [OleUIPasteSpecial](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuipastespeciala) is called, then **OleUIPasteSpecial** will attempt to retrieve a pointer to an **IDataObject** from the clipboard. If **OleUIPasteSpecial** succeeds, it is the caller's responsibility to free the **IDataObject** returned in **lpSrcDataObj**.

### `arrPasteEntries`

The [OLEUIPASTEENTRY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipasteentrya) array which specifies acceptable formats. This member is filled on input.

### `cPasteEntries`

Number of [OLEUIPASTEENTRY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipasteentrya) array entries. This member is filled on input.

### `arrLinkTypes`

List of link types that are acceptable. Link types are referred to using [OLEUIPASTEFLAG](https://learn.microsoft.com/windows/desktop/api/oledlg/ne-oledlg-oleuipasteflag) in **arrPasteEntries**. This member is filled on input.

### `cLinkTypes`

Number of link types. This member is filled on input.

### `cClsidExclude`

Number of CLSIDs in **lpClsidExclude**. This member is filled on input.

### `lpClsidExclude`

Pointer to an array of CLSIDs to exclude from the list of available server objects for a Paste operation. Note that this does not affect **Paste Link**. An application can prevent embedding into itself by listing its own CLSID in this list. This field is filled on input.

### `nSelectedIndex`

Index of **arrPasteEntries** that the user selected. This member is filled on output.

### `fLink`

Whether **Paste** or **Paste Link** was selected by the user. This member is filled on output.

### `hMetaPict`

Handle to the Metafile containing the icon and icon title selected by the user. This member is filled on output.

### `sizel`

The size of object as displayed in its source, if the display aspect chosen by the user matches the aspect displayed in the source. If the user chooses a different aspect, then **sizel.cx** and **sizel.cy** are both set to zero. The size of the object as it is displayed in the source is retrieved from the ObjectDescriptor if **fLink** is **FALSE** and from the LinkSrcDescriptor if **fLink** is **TRUE**. This member is filled on output.

## See also

[OLEUIPASTEENTRY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipasteentrya)

[OLEUIPASTEFLAG](https://learn.microsoft.com/windows/desktop/api/oledlg/ne-oledlg-oleuipasteflag)

[OleUIPasteSpecial](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuipastespeciala)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUIPASTESPECIAL as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).