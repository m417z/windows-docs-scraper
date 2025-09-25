# IBitsPeerCacheRecord::GetOriginUrl

## Description

Gets the origin URL of the cached file.

## Parameters

### `pVal` [in]

Null-terminated string that contains the origin URL of the cached file. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppOriginUrl* when done.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

This URL may be different than the URL originally specified in the BITS job if [IBackgroundCopyJobHttpOptions::SetSecurityFlags](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setsecurityflags) is set to BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT or BG_HTTP_REDIRECT_POLICY_DISALLOW.

## See also

[IBitsPeerCacheRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacherecord)