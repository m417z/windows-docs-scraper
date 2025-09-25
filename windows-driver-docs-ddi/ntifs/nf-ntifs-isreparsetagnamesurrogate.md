# IsReparseTagNameSurrogate macro

## Description

The **IsReparseTagNameSurrogate** macro determines whether a tag's associated reparse point is a surrogate for another named entity, such as a volume mount point.

## Parameters

### `_tag` [in]

Reparse point tag to be tested.

## Remarks

If the name surrogate bit is set in the reparse tag, the file or directory represents another named entity in the system, such as a volume mount point.

For more information about reparse points and volume mount points, see the Microsoft Windows SDK documentation.

## See also

[**FSCTL_DELETE_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point)

[**FSCTL_GET_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point)

[**FSCTL_SET_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FltTagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[**FltUntagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[**IsReparseTagMicrosoft**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagmicrosoft)

[**REPARSE_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)