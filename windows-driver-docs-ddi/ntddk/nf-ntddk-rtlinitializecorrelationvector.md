# RtlInitializeCorrelationVector function

## Description

Initializes the specified [correlation vector](https://github.com/Microsoft/CorrelationVector) with
the supplied GUID.

## Parameters

### `CorrelationVector` [in, out]

A pointer to a [CORRELATION_VECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-correlation_vector) structure that represents the correlation vector to be initialized.

### `Version` [in]

The version of the correlation vector. Possible values are:

* RTL_CORRELATION_VECTOR_VERSION_1
* RTL_CORRELATION_VECTOR_VERSION_2
* RTL_CORRELATION_VECTOR_VERSION_CURRENT

### `Guid` [in]

The GUID to initialize the correlation vector. The first 22 bytes
of the correlation vector are a base64 representation of the GUID. This value must not be NULL.

## Return value

Returns an NTSTATUS value that indicates the success of failure of the operation.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The correlation vector was successfully initialized. |
| **STATUS_INVALID_PARAMETER** | The supplied GUID is null. |

## See also

[CORRELATION_VECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-correlation_vector)