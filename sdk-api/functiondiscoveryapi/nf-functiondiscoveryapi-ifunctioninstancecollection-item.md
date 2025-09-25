# IFunctionInstanceCollection::Item

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the specified function instance, by index.

## Parameters

### `dwIndex` [in]

The zero-based index of the function instance to be retrieved.

### `ppIFunctionInstance` [out]

A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer that receives the function instance.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The *ppFunctionInstance* parameter is **NULL** or *dwIndex* is out of range. |

## Remarks

The [GetCount](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollection-getcount) and **Item** methods enables you to enumerate all of the function instances contained in a collection using a simple **for** or **while** loop.

## See also

[IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection)