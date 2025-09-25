# IFunctionInstanceCollection::GetCount

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the number of function instances in the collection.

## Parameters

### `pdwCount` [out]

The number of function instances.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The *pdwCount* parameter is **NULL**. |

## Remarks

The **GetCount** and [Item](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollection-item) methods enables you to enumerate all of the function instances contained in a collection using a simple **for** or **while** loop.

## See also

[IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection)