# IRawCDImageCreator::AddSubcodeRWGenerator

## Description

Allows the addition of custom R-W subcode, provided by the **IStream**. The provided object must have a size equal to the number of sectors in the raw disc image * 96 bytes when the final image is created.

## Parameters

### `subcode` [in, optional]

The subcode data (with 96 bytes per sector), where the 2 most significant bits must always be zero (as they are the P/Q bits).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

May be added anytime prior to calling [IRawCDImageCreator::CreateResultImage](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-createresultimage). If [IRawCDImageCreator::put_ResultingImageType](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-put_resultingimagetype) is set to return PQ only, then this call will fail as no RW subcode will be used in the resulting image.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)

[IRawCDImageCreator::CreateResultImage](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-createresultimage)

[IRawCDImageCreator::put_ResultingImageType](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-put_resultingimagetype)