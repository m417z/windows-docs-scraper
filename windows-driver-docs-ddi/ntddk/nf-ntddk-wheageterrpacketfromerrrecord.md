# WheaGetErrPacketFromErrRecord function

## Description

The **WheaGetErrPacketFromErrRecord** function returns a pointer to the hardware error packet that is contained within a WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). The hardware error packet is formatted as a [WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85)) structure.

## Parameters

### `Record` [in]

A pointer to a WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records) that is formatted as a [WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure.

## Return value

**WheaGetErrPacketFromErrRecord** returns a pointer to the [WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85)) structure within the [WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure. If the function does not locate the WHEA_ERROR_PACKET structure, it returns **NULL**.

## Remarks

The **WheaGetErrPacketFromErrRecord** function returns a pointer to the hardware error packet that is contained within an error record.

## See also

[Error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records)

[WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[WHEA_ERROR_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record)