# OLEUIGNRLPROPSA structure

## Description

Initializes the **General** tab of the **Object Properties** dialog box. A reference to it is passed in as part of the [OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa) structure to the [OleUIObjectProperties](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiobjectpropertiesa) function. This tab shows the type and size of an OLE embedding and allows it the user to tunnel to the **Convert** dialog box. This tab also shows the link destination if the object is a link.

## Members

### `cbStruct`

The size of the structure, in bytes. This field must be filled on input.

### `dwFlags`

Currently no flags associated with this member. It should be set to 0 (zero).

### `dwReserved1`

This member is reserved.

### `lpfnHook`

Pointer to a hook function that processes messages intended for the dialog box. The hook function must return zero to pass a message that it didn't process back to the dialog box procedure in the library. The hook function must return a nonzero value to prevent the library's dialog box procedure from processing a message it has already processed.

### `lCustData`

Application-defined data that the library passes to the hook function pointed to by the **lpfnHook** member during WM_INITDIALOG.

### `dwReserved2`

This member is reserved.

### `lpOP`

Used internally.

## See also

[OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa)

[OleUIObjectProperties](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiobjectpropertiesa)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUIGNRLPROPS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).