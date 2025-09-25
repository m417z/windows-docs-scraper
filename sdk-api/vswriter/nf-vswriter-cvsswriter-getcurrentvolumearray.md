# CVssWriter::GetCurrentVolumeArray

## Description

The
**GetCurrentVolumeArray** method returns the names of the original volumes and the UNC paths of the original remote file shares that belong to the shadow copy set as an array of null-terminated wide character strings.**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

**GetCurrentVolumeArray** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

This method returns a pointer to an *n*-element array (where *n* is the value returned by
[CVssWriter::GetCurrentVolumeCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentvolumecount)) of null-terminated wide character strings that contain the names of the original volumes and the UNC paths of the original remote file shares that belong to the shadow copy set.**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

The derived class should not free the memory held by the returned array of volume names. The base class manages the life cycle of the array.

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)