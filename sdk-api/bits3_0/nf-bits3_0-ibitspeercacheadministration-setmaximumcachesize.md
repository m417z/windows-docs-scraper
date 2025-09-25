# IBitsPeerCacheAdministration::SetMaximumCacheSize

## Description

Specifies the maximum size of the cache.

## Parameters

### `Bytes` [in]

Maximum size of the cache, as a percentage of available hard disk drive space.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **S_FALSE** | The configuration preference has been saved successfully, but the preference will not be used because a configured Group Policy setting overrides the preference. |

## Remarks

This value is used only if the MaxCacheSize group policy is not set.

If the maximum cache size is reached, BITS removes the least recently accessed files until the necessary disk space is freed. If you specify a value that is less than the current cache size, BITS removes files from the cache until the requested size is met. BITS removes the files based on [age](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setmaximumcontentage). Files that are larger than the cache size are not cached.

By default, the maximum cache size is 1% of the disk size. BITS does not use the limit to reserve disk space for the cache. BITS will use up to the specified limit for the cache, if the disk space is available. The maximum value you can specify is 80% of the disk size.

If the request is to reduce the size of the cache and BITS is currently downloading a file from the cache, BITS will not remove the file until the download is complete.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::GetMaximumCacheSize](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-getmaximumcachesize)

[IBitsPeerCacheAdministration::SetMaximumContentAge](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setmaximumcontentage)