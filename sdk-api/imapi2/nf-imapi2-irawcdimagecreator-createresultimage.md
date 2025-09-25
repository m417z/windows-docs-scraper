# IRawCDImageCreator::CreateResultImage

## Description

Creates the final **IStream** object based on the current settings.

## Parameters

### `resultStream` [out, optional]

Pointer to the finalized IStream object.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

**IRawCDImageCreator::CreateResultImage** can only be called once, and will result in the object becoming read-only. All properties associated with this object can be read but not modified. The resulting **IStream** object will be a disc image which starts at MSF 95:00:00, to allow writing of a single image to media with multiple starting addresses.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)