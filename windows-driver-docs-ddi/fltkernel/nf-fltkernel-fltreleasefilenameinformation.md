# FltReleaseFileNameInformation function

## Description

**FltReleaseFileNameInformation** releases a file name information structure.

## Parameters

### `FileNameInformation` [in]

Pointer to the FLT_FILE_NAME_INFORMATION structure to be released. This parameter is required and cannot be **NULL**.

## Return value

None

## Remarks

**FltReleaseFileNameInformation** decrements the reference count on a file name information ([FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information)) structure returned by a previous call to [FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation), [FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation), [FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe), or [FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname). When this reference count reaches zero, the structure is freed.

To increment the reference count on a file name information structure, call [FltReferenceFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencefilenameinformation).

## See also

[FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information)

[FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation)

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation)

[FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe)

[FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname)

[FltReferenceFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencefilenameinformation)