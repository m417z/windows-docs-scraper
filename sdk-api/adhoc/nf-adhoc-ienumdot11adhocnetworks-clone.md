# IEnumDot11AdHocNetworks::Clone

## Description

Creates a new enumeration interface.

## Parameters

### `ppEnum` [out]

A pointer to a variable that, on successful return, points to an [IEnumDot11AdHocNetworks](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-ienumdot11adhocnetworks) interface.

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

[IEnumDot11AdHocNetworks](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-ienumdot11adhocnetworks)