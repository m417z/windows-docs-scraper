# IPerPropertyBrowsing::GetPredefinedValue

## Description

Retrieves the value of the specified property that is associated with a predefined string name. This property is associated with a predefined string name as returned from [IPerPropertyBrowsing::GetPredefinedStrings](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedstrings). The predefined string is identified by a token returned from **GetPredefinedStrings**.

## Parameters

### `dispID` [in]

The dispatch identifier of the property for which a predefined value is requested.

### `dwCookie` [in]

A token identifying which value to return. The token was previously returned in the *pCaCookiesOut* array filled by [GetPredefinedStrings](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedstrings).

### `pVarOut` [out]

A pointer to the **VARIANT** value for the property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | This object does not support predefined strings or predefined values. |
| **E_POINTER** | The address in *pVarOut* is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Callers

The caller is responsible for freeing any allocations contained in the **VARIANT**. Unless the **vt** member of **VARIANT** is VT_VARIANT, the caller can free memory using a single call to **VariantClear**. Otherwise, the caller must recursively free the contained **VARIANT** values before freeing the outer **VARIANT**.

### Notes to Implementers

Support for predefined names and values is not required. If your object does not support these names, return E_NOTIMPL from this method. If this method is not implemented, [IPerPropertyBrowsing::GetPredefinedStrings](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedstrings) must not be implemented either.

This method allocates any memory needed inside the **VARIANT**.

## See also

[IPerPropertyBrowsing](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iperpropertybrowsing)