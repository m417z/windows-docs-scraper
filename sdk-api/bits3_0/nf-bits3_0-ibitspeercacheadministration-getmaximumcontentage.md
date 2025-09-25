# IBitsPeerCacheAdministration::GetMaximumContentAge

## Description

Gets the age by when files are removed from the cache.

## Parameters

### `pSeconds` [out]

Age, in seconds. If the last time that the file was accessed is older than this age, BITS removes the file from the cache.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::SetMaximumContentAge](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setmaximumcontentage)