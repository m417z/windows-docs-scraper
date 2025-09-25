# IRawCDImageCreator::get_StartOfLeadout

## Description

Retrieves the value that defines the LBA for the start of the Leadout. This method can be utilized to determine if the image can be written to a piece of media by comparing it against the **LastPossibleStartOfLeadout** for the media.

## Parameters

### `value` [out]

Pointer to a **LONG** value that represents the LBA for the start of the Leadout.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

Use of this method requires that at least 1 track has been added to the image.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)