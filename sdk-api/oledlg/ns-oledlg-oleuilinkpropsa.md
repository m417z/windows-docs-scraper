# OLEUILINKPROPSA structure

## Description

Contains information that is used to initialize the **Link** tab of the **Object Properties** dialog box. A reference to it is passed in as part of the [OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa) structure to the [OleUIObjectProperties](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiobjectpropertiesa) function. This tab shows the location, update status, and update time for a link. It allows the user to change the source of the link, toggle its update status between automatic and manual update, open the source, force an update of the link, or break the link (convert it to a static picture).

## Members

### `cbStruct`

The size of the structure, in bytes.

### `dwFlags`

Contains in/out flags specific to the **Links** page.

### `dwReserved1`

This member is reserved.

### `lpfnHook`

Pointer to the hook callback (not used in this dialog box).

### `lCustData`

Custom data to pass to hook (not used in this dialog box).

### `dwReserved2`

This member is reserved.

### `lpOP`

Used internally.

## See also

[OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa)

[OleUIObjectProperties](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiobjectpropertiesa)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUILINKPROPS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).