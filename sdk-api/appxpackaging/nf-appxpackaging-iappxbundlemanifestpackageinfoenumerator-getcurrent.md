# IAppxBundleManifestPackageInfoEnumerator::GetCurrent

## Description

Gets the \<Package> element at the current position of the enumerator.

## Parameters

### `packageInfo` [out, retval]

Type: **[IAppxBundleManifestPackageInfo](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestpackageinfo)****

The current \<Package> element.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_BOUNDS** | The enumerator has passed the last item in the collection. |

## Remarks

The enumerator’s position points to the first element by default. So, with a newly constructed enumerator that contains at least one element, [IAppxBundleManifestPackageInfoEnumerator::GetHasCurrent](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxbundlemanifestpackageinfoenumerator-gethascurrent) returns **TRUE** and **GetCurrent** returns the first element.

## See also

[IAppxBundleManifestPackageInfoEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestpackageinfoenumerator)