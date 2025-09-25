# CVssWriter::GetCurrentVolumeCount

## Description

The
**GetCurrentVolumeCount** method returns the number of volumes in the shadow copy set.

**GetCurrentVolumeCount** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

This method returns the number of volumes returned in the shadow copy set. This value will also be the size of the array of null-terminated wide character strings containing volume names returned by
[CVssWriter::GetCurrentVolumeArray](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentvolumearray).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::GetCurrentVolumeArray](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentvolumearray)

[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)