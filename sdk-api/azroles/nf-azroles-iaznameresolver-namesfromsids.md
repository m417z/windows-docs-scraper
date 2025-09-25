# IAzNameResolver::NamesFromSids

## Description

The **NamesFromSids** method gets the display names that correspond to the specified [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs).

## Parameters

### `vSids` [in]

An array of string representations of the SIDs to translate.

This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_BSTR** that contains a string representation of a SID.

### `pvSidTypes` [out]

A pointer to an array of elements of the [SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumeration that specify the types of SIDs being translated.

This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_I4** value that specifies an element of the [SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumeration.

### `pvNames` [out]

A pointer to an array of strings that contain the display names of the principals that correspond to the SIDs specified by the *vSids* parameter.

This is a variant that contains either a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) or the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object. Each element of the array holds a **VT_BSTR** that contains a display name. If a name could not be found for one or more of the SIDs, the corresponding array element contains an empty string.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. If the method cannot find the display names of any of the principals, it returns **CO_E_NOMATCHINGNAMEFOUND**. For a list of other common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).