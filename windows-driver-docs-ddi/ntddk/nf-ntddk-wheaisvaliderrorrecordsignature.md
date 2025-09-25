# WheaIsValidErrorRecordSignature function

## Description

The **WheaIsValidErrorRecordSignature** function verifies whether a WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records) is valid.

## Parameters

### `Record` [in]

A pointer to a WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records) that is formatted as a [WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure.

## Return value

**WheaIsValidErrorRecordSignature** returns a Boolean value that indicates whether the WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records) is valid. If it is valid, the function returns **TRUE**.

## Remarks

The **WheaIsValidErrorRecordSignature** function verifies that the specified [WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure contains valid values.

## See also

[Error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records)

[WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record)

[WHEA_ERROR_RECORD_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header)