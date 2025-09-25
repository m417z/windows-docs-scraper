# IFunctionInstanceCollection::Remove

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Deletes the specified function instance and returns a pointer to the function instance being removed.

## Parameters

### `dwIndex` [in]

The index number within the collection.

### `ppIFunctionInstance` [out]

 A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer that receives the function instance.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of *dwIndex* is invalid. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## See also

[IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection)