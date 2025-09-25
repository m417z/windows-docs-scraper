# IRawCDImageCreator::get_ExpectedTableOfContents

## Description

Gets the SCSI-form table of contents for the resulting disc.

## Parameters

### `value` [out]

The SCSI-form table of contents for the resulting disc. Accuracy of this value depends on **IRawCDImageCreator::get_ExpectedTableOfContents** being called after all image properties have been set.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This method can only be called after at least one track has been added to the image.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)