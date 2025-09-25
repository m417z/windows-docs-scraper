## Description

The **FSCTL_GET_REFS_VOLUME_DATA** control code retrieves information about an ReFS volume.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

A [**REFS_VOLUME_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-refs_volume_data_buffer) structure that contains information about the ReFS volume.

### Output buffer length

Number of bytes in the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

## See also

[**REFS_VOLUME_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-refs_volume_data_buffer)