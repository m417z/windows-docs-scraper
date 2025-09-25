# RtlValidateCorrelationVector function

## Description

Validates the specified [correlation vector](https://github.com/Microsoft/CorrelationVector) to check whether it conforms to the Correlation Vector Specification (v2).
The function specifically checks if the first 22 bytes are a valid base64 representation of a 16 byte
buffer
and the remaining characters match the (\.\d+)+ regular expression.

## Parameters

### `Vector`

A pointer to a [**CORRELATION_VECTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-correlation_vector) structure that represents the correlation vector to be validated.

## Return value

Returns an NTSTATUS value that indicates the success of failure of the operation.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The correlation vector is valid. |
| **STATUS_INVALID_PARAMETER** | The supplied correlation vector is invalid. |