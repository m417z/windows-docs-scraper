# IsReparseTagMicrosoft macro

## Description

The **IsReparseTagMicrosoft** macro determines whether a reparse point tag indicates a Microsoft reparse point.

## Parameters

### `_tag` [in]

Reparse point tag to be tested.

## Remarks

Only Microsoft reparse points can use Microsoft tags. Third-party reparse points must use non-Microsoft tags. However, third-party drivers can set Microsoft reparse points. For more information, see the Remarks section of the reference entry for the [**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer) structure.

For more information about reparse points, see the Microsoft Windows SDK documentation.

## See also

[**FSCTL_DELETE_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point)

[**FSCTL_GET_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point)

[**FSCTL_SET_REPARSE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FltTagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[**FltUntagFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[**IsReparseTagNameSurrogate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagnamesurrogate)

[**REPARSE_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[**REPARSE_GUID_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)