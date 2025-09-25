# IAppxBundleManifestOptionalBundleInfoEnumerator::GetCurrent

## Description

Gets the optional bundle information at the current position of the enumerator.

## Parameters

### `optionalBundle` [out, retval]

The optional bundle information.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_BOUNDS** | The enumerator has passed the last item in the collection. |

## See also

[IAppxBundleManifestOptionalBundleInfoEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestoptionalbundleinfoenumerator)