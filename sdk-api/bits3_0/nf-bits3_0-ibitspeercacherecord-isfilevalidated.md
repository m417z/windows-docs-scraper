# IBitsPeerCacheRecord::IsFileValidated

## Description

Determines whether the file has been validated.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | File has been validated. |
| **S_FALSE** | File has not been validated. |

## Remarks

The file is available to serve after you validate the file. To validate the file, call the [IBackgroundCopyFile3::SetValidationState](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyfile3-setvalidationstate) method. The file is implicitly validated if the application calls [IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) without calling **SetValidationState**. To remove the file from the cache after validation, see [IBitsPeerCacheAdministration::DeleteUrl](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-deleteurl) and [IBitsPeerCacheAdministration::DeleteRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-deleterecord).

## See also

[IBitsPeerCacheRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacherecord)