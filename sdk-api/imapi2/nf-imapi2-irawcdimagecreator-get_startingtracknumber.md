# IRawCDImageCreator::get_StartingTrackNumber

## Description

Retrieves the starting track number.

## Parameters

### `value` [out]

Pointer to a **LONG** value that represents the starting track number.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

If this property holds a value other than 1, all tracks added to the image must be audio tracks.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)

[IRawCDImageCreator::put_StartingTrackNumber](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-put_startingtracknumber)