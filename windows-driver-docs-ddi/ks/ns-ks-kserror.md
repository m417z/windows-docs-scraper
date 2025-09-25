# KSERROR structure

## Description

The **KSERROR** structure is used to report streaming errors in both kernel and user mode to their respective quality managers.

## Members

### `Context`

Specifies a context parameter that was originally passed to the connection.

### `Status`

Specifies the NTSTATUS error.

## Remarks

Streaming error notifications can be generated against the quality management sink, if assigned. The same method of proxying quality management complaints is used for forwarding error reports for DirectShow graphs.

For more information, see [Quality Management](https://learn.microsoft.com/windows-hardware/drivers/stream/quality-management).

## See also

[**KSDEGRADE**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksdegrade-structure)

[**KSDEGRADE_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksdegrade_standard)

[**KSPROPERTY_QUALITY_ERROR**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-quality-error)