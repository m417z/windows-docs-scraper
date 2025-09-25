## Description

The **FSCTL_SECURITY_ID_CHECK** control code verifies security identifiers (SIDs) against specified access rights in bulk.

## Parameters

### Major code

FSCTL_SECURITY_ID_CHECK

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

## See also

[**BULK_SECURITY_TEST_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-bulk_security_test_data)