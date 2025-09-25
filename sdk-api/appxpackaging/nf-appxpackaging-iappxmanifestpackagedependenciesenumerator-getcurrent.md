# IAppxManifestPackageDependenciesEnumerator::GetCurrent

## Description

Gets the dependency package at the current position of the enumerator.

## Parameters

### `dependency` [out, retval]

Type: **[IAppxManifestPackageDependency](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackagedependency)****

The current dependency package.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_BOUNDS** | The enumerator has passed the last item in the collection. |

## Remarks

The enumerator returned can be empty. In this case, a call to [GetHasCurrent](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestpackagedependenciesenumerator-gethascurrent) returns **false**. If the enumerator is not empty, it points to the first element, and this method returns the first item. Subsequently, the user should use [MoveNext](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestpackagedependenciesenumerator-movenext) to move through the items, and call **GetHasCurrent** before using **GetCurrent** to access the item.

## See also

[IAppxManifestPackageDependenciesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackagedependenciesenumerator)