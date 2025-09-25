# IRawCDImageCreator::get_LastUsedUserSectorInImage

## Description

Retrieves the number of total used sectors on the current media, including any overhead between existing tracks.

## Parameters

### `value` [out]

Pointer to a **LONG** value that indicates the number of total used sectors on the media.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This value represents the LBA of the last sector with data that is considered part of a track, and does not include the overhead of the leadin, leadout, or the two-seconds between MSF 00:00:00 and MSF 00:02:00.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)