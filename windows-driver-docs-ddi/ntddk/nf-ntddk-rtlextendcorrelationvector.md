# RtlExtendCorrelationVector function

## Description

This routine extends the supplied [correlation vector](https://github.com/Microsoft/CorrelationVector). For
a correlation vector of the form X.i, the extended value is
X.i.0.

## Parameters

### `CorrelationVector` [in, out]

A pointer to a [CORRELATION_VECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-correlation_vector) structure that represents the correlation vector to be extended.

## Return value

Returns an NTSTATUS value that indicates the success of failure of the operation.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The correlation vector was successfully incremented. |
| **STATUS_INVALID_PARAMETER** | Extending the correlation vector resulted in a buffer overflow because as the extended value is no longer a valid correlation vector. |