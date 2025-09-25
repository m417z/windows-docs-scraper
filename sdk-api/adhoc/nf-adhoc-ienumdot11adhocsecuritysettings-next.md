# IEnumDot11AdHocSecuritySettings::Next

## Description

Gets the specified number of elements from the sequence and advances the current position by the number of items retrieved. If there are fewer than the requested number of elements left in the sequence, it retrieves the remaining elements.

## Parameters

### `cElt` [in]

The number of elements requested.

### `rgElt` [out]

A pointer to a variable that, on successful return, points an array of pointers to [IDot11AdHocSecuritySettings](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocsecuritysettings) interfaces. The array is of size *cElt*.

### `pcEltFetched` [out]

A pointer to a variable that specifies the number of elements returned in *rgElt*.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |

## See also

[IEnumDot11AdHocSecuritySettings](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-ienumdot11adhocsecuritysettings)