# IAppxManifestApplicationsEnumerator::GetCurrent

## Description

Gets the application at the current position of the enumerator.

## Parameters

### `application` [out, retval]

Type: **[IAppxManifestApplication](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestapplication)****

The current application.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_BOUNDS** | The enumerator has passed the last item in the collection. |

## Remarks

The enumerator returned can be empty. In this case, a call to [GetHasCurrent](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestapplicationsenumerator-gethascurrent) returns **false**. If the enumerator is not empty, it points to the first element, and this method returns the first item. Subsequently, the user should use [MoveNext](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestapplicationsenumerator-movenext) to move through the items, and call **GetHasCurrent** before using **GetCurrent** to access the item.

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also

[IAppxManifestApplicationsEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestapplicationsenumerator)