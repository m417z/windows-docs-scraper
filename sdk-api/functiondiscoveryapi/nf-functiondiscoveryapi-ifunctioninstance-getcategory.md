# IFunctionInstance::GetCategory

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the category and subcategory strings for the function instance.

## Parameters

### `ppszCoMemCategory` [out]

The null-terminated identifier string of the category. See [Category Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/category-definitions).

Be sure to free this buffer using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `ppszCoMemSubCategory` [out]

The null-terminated identifier string of the subcategory. See [Subcategory Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/subcategory-definitions).

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## Remarks

The category and subcategory of a function instance always refer to the provider category from which a function instance comes.

## See also

[IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance)