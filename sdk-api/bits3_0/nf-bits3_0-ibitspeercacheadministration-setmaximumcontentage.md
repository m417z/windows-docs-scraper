# IBitsPeerCacheAdministration::SetMaximumContentAge

## Description

Specifies when files are removed from the cache based on age.

## Parameters

### `Seconds` [in]

Age, in seconds. If the last time that the file was accessed is older than this age, BITS removes the file from the cache. The age is reset each time the file is accessed. The maximum value is 10,368,000 seconds (120 days) and the minimum value is 86,400 seconds (1 day). The default is 7,776,000 seconds (90 days).

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **S_FALSE** | The configuration preference has been saved successfully, but the preference will not be used because a configured Group Policy setting overrides the preference. |

## Remarks

This value is used only if the MaxContentAge group policy is not set.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::GetMaximumContentAge](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-getmaximumcontentage)

[IBitsPeerCacheAdministration::SetMaximumCacheSize](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setmaximumcachesize)