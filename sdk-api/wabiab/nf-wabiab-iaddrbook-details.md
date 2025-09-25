## Description

Displays a dialog box that shows details, and allows editing, of a particular entry in the Windows Address Book (WAB).

## Parameters

### `lpulUIParam`

Pointer to a variable of type ULONG_PTR that receives the returned parent window handle of the returned dialog box.

### `lpfnDismiss`

DISMISSMODELESS function pointer. This function is called when the modeless dialog box is dismissed. Not implemented.

### `lpvDismissContext`

Not implemented.

### `cbEntryID`

Value of type ULONG that specifies the size of *lpEntryID*.

### `lpEntryID`

Pointer to a variable of type ENTRYID that specifies the entry identifier of the entry on which to display details.

### `lpfButtonCallback`

Not supported by the Windows Address Book (WAB); must be NULL.

### `lpvButtonContext`

Not supported by the Windows Address Book (WAB); must be NULL.

### `lpszButtonText`

Not supported by the Windows Address Book (WAB); must be NULL.

### `ulFlags`

Not supported by the Windows Address Book (WAB); must be NULL.

## Return value

HRESULT

## Remarks

Windows Address Book (WAB) does not support the Button callbacks. The property sheets are extensible through the **IWABExtInit** and **IShellPropSheetExt Interface** interfaces.

## See also