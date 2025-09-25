# ITAddressTranslation::TranslateDialog

## Description

The
**TranslateDialog** method displays an application-modal dialog box that allows the user to change the current location of a phone number about to be dialed, adjust location and calling card parameters, and see the effect.

## Parameters

### `hwndOwner` [in]

A handle to a window to which the dialog box is to be attached. Can be a **NULL** value to indicate that any window created during the function should have no owner window.

### `pAddressIn` [in]

A pointer to **BSTR** containing a phone number that is used to show the effect of the user's changes on the location parameters. The number must be in canonical format. This pointer can be left **NULL**, in which case the phone number portion of the dialog box is not displayed. If the *pAddressIn* parameter contains a subaddress or name field or additional addresses separated from the first address by ASCII CR and LF characters, only the first address is used in the dialog box.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *hwndOwner* parameter is not a valid handle or the *pAddressIn* parameter is not a valid phone number. |
| **E_POINTER** | The *pAddressIn* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | An unexpected error occurred. |
| **TAPI_E_REGISTRY_SETTING_CORRUPT** | The registry settings for address translation are not valid. |
| **TAPI_E_NODRIVER** | No TSP exists that can do translation for this address. |
| **TAPI_E_INUSE** | The dialog is already open and in use. |
| **TAPI_E_INVALADDRESS** | The current address is not valid. |
| **TAPI_E_OPERATIONFAILED** | TAPI was not able to complete the operation. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for *pAddressIn* and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

The
**TranslateDialog** method is a COM wrapper for the TAPI 2.1
[LineTranslateDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslatedialog) function.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation)

[LineTranslateDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linetranslatedialog)