# IFunctionInstanceCollection::Get

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the specified function instance and its index from the collection.

## Parameters

### `pszInstanceIdentity` [in]

The identifier of the function instance to be retrieved (see [GetID](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-getid)).

### `pdwIndex` [out]

The index number.

### `ppIFunctionInstance` [out]

 A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer that receives the function instance.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **S_FALSE** | The function instance identified by *pInstanceIdentity* is not present in the function instance collection. |
| **E_INVALIDARG** | The value of *pdwIndex* or *pInstanceIdentity* is invalid. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## See also

[IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection)