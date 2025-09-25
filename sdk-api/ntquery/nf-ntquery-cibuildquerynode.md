# CIBuildQueryNode function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Builds one node of a query restriction tree for a Command object.

## Parameters

### `wcsProperty`

A pointer to a null-terminated string that specifies the friendly name for a property. The friendly name can be used in an Indexing Service query, column list, or sort order.

### `dbOperator`

The operation to be performed on the node. See [DBCOMMANDOP](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandop).

### `pvarPropertyValue`

A pointer to the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure for the value to use for the *wcsProperty* parameter.

### `ppTree`

A pointer to an output variable that receives the pointer to the [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure for the node created by this function.

### `cProperties`

The number of properties in the *pProperty* array.

### `pProperty`

A pointer to an array of [CIPROPERTYDEF](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-cipropertydef) structures, each of which describes a property that can be referred to by a friendly name. This array is populated when *pvarPropertyValue* contains a string that contains references to properties. This parameter can be **NULL** when *cProperties* equals zero.

### `LocaleID`

The locale ID used when converting properties. The *pvarPropertyValue* parameter itself contains a string that contains references to friendly property names, which are converted to uppercase for comparison and efficiency purposes.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **QPARSE_E_NO_SUCH_PROPERTY** | The function failed because the property name specified by *wcsProperty* was not found. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## Remarks

Use nodes created by the **CIBuildQueryNode** function to create or add to a query tree using the [CIBuildQueryTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-cibuildquerytree) function. Content properties are in turn passed to the [CITextToSelectTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttoselecttree) function to create the **SELECT** part of the full tree.

## See also

[CIBuildQueryTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-cibuildquerytree)

[CITextToFullTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttofulltree)

[CITextToFullTreeEx](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttofulltreeex)

[CITextToSelectTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttoselecttree)

[CITextToSelectTreeEx](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttoselecttreeex)

[DBCOMMANDOP](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandop)

[DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree)

