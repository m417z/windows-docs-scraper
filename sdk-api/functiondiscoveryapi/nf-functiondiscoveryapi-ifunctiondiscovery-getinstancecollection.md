# IFunctionDiscovery::GetInstanceCollection

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the specified collection of function instances, based on category and subcategory.

## Parameters

### `pszCategory` [in]

The identifier of the category to be enumerated. See [Category Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/category-definitions).

### `pszSubCategory` [in]

The identifier of the subcategory to be enumerated. See [Subcategory Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/subcategory-definitions). This parameter can be **NULL**.

### `fIncludeAllSubCategories` [in]

If **TRUE**, this method recursively enumerates all the subcategories of the category specified in *pszCategory*, returning a collection containing function instances from all the subcategories of *pszCategory*.

If **FALSE**, this method restricts itself to returning function instances in the category specified by *pszCategory* and the subcategory specified by *pszSubCategory*.

### `ppIFunctionInstanceCollection` [out]

A pointer to an [IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection) interface pointer that receives the function instance collection containing the requested function instances. The collection is empty if no qualifying function instances are found.

## Return value

Possible return values include, but are not limited to, the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of *pszCategory* is invalid. The value returned in *ppIFunctionInstanceCollection* parameter is **NULL**. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)**<br><br>0x80070002 | The value of *pszCategory* or *pszSubCategory* is unknown. |
| **E_PENDING** | The call was executed for a provider that returns results asynchronously. |

## Remarks

Some function discovery providers return their query results with the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface. **GetInstanceCollection** does not find function instances that are returned in this way and will fail with E_PENDING. It is recommended that clients use the [CreateInstanceQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancequery) method of the [IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery) interface to find function instances for such providers.

If the method succeeds but no function instances were found that matched the query parameters, then **S_OK** is returned and *ppFunctionInstanceCollection* points to an empty collection (the collection's [GetCount](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollection-getcount) method returns 0).

Subcategory queries are only supported for layered categories and some provider categories. The [Registry Provider](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/registry-provider), the PnP-X association provider, and the publication provider support subcategory queries. Custom providers can be explicitly designed to support subcategory queries. For other providers, function instance collections can be filtered using query constraints. For a list of query constraints, see [Constraint Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/constraint-definitions).

#### Examples

The following code returns the function instances associated with the SSDP provider in the Microsoft.Networking.Devices namespace.

```cpp
hr = spDisco->GetInstanceCollection(FCTN_CATEGORY_NETWORKDEVICES,
                                   FCTN_SUBCAT_NETWORKDEVICES_SSDP,
                                   FALSE,
                                   &spFunctionInstanceCollection);

```

See interface constraints on [IFunctionInstanceQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancequery) to filter on multiple interfaces at one time or to filter on providers that do not support subcategory queries.

## See also

[IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery)