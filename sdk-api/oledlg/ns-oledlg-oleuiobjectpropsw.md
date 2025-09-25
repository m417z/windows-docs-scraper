# OLEUIOBJECTPROPSW structure

## Description

Contains information that is used to initialize the standard **Object Properties** dialog box. It contains references to interfaces used to gather information about the embedding or link, references to three structures that are used to initialize the default tabs - **General** ([OLEUIGNRLPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuignrlpropsa)), **View** ([OLEUIVIEWPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiviewpropsa)), and **Link** ([OLEUILINKPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuilinkpropsa)), if appropriate - and a standard property-sheet extensibility interface that allows the caller to add additional custom property sheets to the dialog box.

## Members

### `cbStruct`

The size of the structure, in bytes.

### `dwFlags`

Contains in/out global flags for the property sheet.

| Value | Meaning |
| --- | --- |
| **OPF_OBJECTISLINK** | Object is a link object and therefore has a link property page. |
| **OPF_NOFILLDEFAULT** | Do not fill in default values for the object. |
| **OPF_SHOWHELP** | The dialog box will display a **Help** button. |
| **OPF_DISABLECONVERT** | The **Convert** button will be disabled on the general property page. |

### `lpPS`

Pointer to the standard property sheet header ([PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)), used for extensibility.

### `dwObject`

Identifier for the object.

### `lpObjInfo`

Pointer to the interface to manipulate object.

### `dwLink`

Container-defined unique identifier for a single link. Containers can use the pointer to the link's container site for this value.

### `lpLinkInfo`

 Pointer to the interface to manipulate link.

### `lpGP`

 Pointer to the general page data.

### `lpVP`

Pointer to the view page data.

### `lpLP`

Pointer to the link page data.

## See also

[OLEUIGNRLPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuignrlpropsa)

[OLEUILINKPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuilinkpropsa)

[OLEUIVIEWPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiviewpropsa)

[OleUIObjectProperties](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiobjectpropertiesa)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUIOBJECTPROPS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).