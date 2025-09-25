# IAzObjectPicker::GetPrincipals

## Description

The **GetPrincipals** method displays a dialog box from which users can choose one or more principals, and then returns the chosen list of principals and their corresponding [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs).

## Parameters

### `hParentWnd` [in]

A handle to the parent window of the dialog box.

### `bstrTitle` [in]

The display title of the dialog box.

### `pvSidTypes` [out]

A pointer to an array of elements of the [SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumeration that specify the types of the SIDs that correspond to the principals chosen by the user.

This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_I4** value that specifies an element of the [SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumeration.

### `pvNames` [out]

A pointer to an array of display names of the principals chosen by the user.

This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_BSTR** that contains a display name.

### `pvSids` [out]

A pointer to an array of string representations of the SIDs that correspond to the principals chosen by the user.

This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_BSTR** that contains a string representation of a SID.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).