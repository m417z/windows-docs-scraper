## Description

Displays the common address book dialog box.

## Parameters

### `lpulUIParam`

Pointer to a variable of type ULONG_PTR that specifies the handle of the parent window of the dialog box. On input, a window handle must always be passed. On output, if the DIALOG_SDI flag is set in the *lpAdrParms* parameter **ADRPARM** structure, the window handle of the modeless dialog box is returned.

### `lpAdrParms`

Pointer to a variable of type **ADRPARM** that specifies the presentation and behavior of the addressing dialog box.

### `lppAdrList`

Address of a pointer to a variable of type **ADRLIST** that specifies the current recipient list. On output, *lppAdrList* receives the address of a pointer to the **ADRLIST** where the **IAddrBook::Address** is stored. The user can set **lppAdrList** to **NULL** on input.

## Return value

HRESULT

## Remarks

The behavior of the addressing dialog box is specified by flags and parameters in *lpAdrParms*. The Windows Address Book (WAB) does not support some of the customization features of the MAPI **Address** method. The Windows Address Book (WAB) also does not support the MAPI send options dialog button.

## See also