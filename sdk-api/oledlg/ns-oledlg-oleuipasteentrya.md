# OLEUIPASTEENTRYA structure

## Description

An array of entries to be specified in the [OLEUIPASTESPECIAL](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipastespeciala) structure for the **Paste Special** dialog box. Each entry includes a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure which specifies the formats that are acceptable, a string that is to represent the format in the dialog box's listbox, a string to customize the result text of the dialog box, and a set of flags from the [OLEUIPASTEFLAG](https://learn.microsoft.com/windows/desktop/api/oledlg/ne-oledlg-oleuipasteflag) enumeration. The flags indicate if the entry is valid for pasting only, linking only or both pasting and linking. If the entry is valid for linking, the flags indicate which link types are acceptable by OR'ing together the appropriate OLEUIPASTE_LINKTYPE*n* values.

## Members

### `fmtetc`

Format that is acceptable. The **Paste Special** dialog box checks if this format is offered by the object on the clipboard and if so, offers it for selection to the user.

### `lpstrFormatName`

Pointer to the string that represents the format to the user. Any %s in this string is replaced by the FullUserTypeName of the object on the clipboard and the resulting string is placed in the list box of the dialog box. Only one %s is allowed. The presence or absence of %s specifies whether the result-text is to indicate that data is being pasted or that an object that can be activated by an application is being pasted. If %s is present, the resulting text says that an object is being pasted. Otherwise, it says that data is being pasted.

### `lpstrResultText`

Pointer to the string used to customize the resulting text of the dialog box when the user selects the format corresponding to this entry. Any %s in this string is replaced by the application name or FullUserTypeName of the object on the clipboard. Only one %s is allowed.

### `dwFlags`

Values from [OLEUIPASTEFLAG](https://learn.microsoft.com/windows/desktop/api/oledlg/ne-oledlg-oleuipasteflag) enumeration.

### `dwScratchSpace`

Scratch space available to routines that loop through an [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) to mark if the PasteEntry format is available. This field can be left uninitialized.

## See also

[OLEUIPASTEFLAG](https://learn.microsoft.com/windows/desktop/api/oledlg/ne-oledlg-oleuipasteflag)

[OLEUIPASTESPECIAL](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipastespeciala)

[OleUIPasteSpecial](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuipastespeciala)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUIPASTEENTRY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).