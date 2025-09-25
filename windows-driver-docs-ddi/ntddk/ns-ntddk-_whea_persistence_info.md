# _WHEA_PERSISTENCE_INFO structure

## Description

The WHEA_PERSISTENCE_INFO union describes data that is used by the error record persistence interface for storing an error record.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Signature`

The signature of the error record when it is stored in the platform's persistent data storage. This member contains the value 'RE'.

### `DUMMYSTRUCTNAME.Length`

The length, in bytes, of the error record when it is stored in the platform's persistent data storage.

### `DUMMYSTRUCTNAME.Identifier`

An identifier that uniquely identifies the error record when it is stored in the platform's persistent data storage. The data type for this identifier is WHEA_ERROR_RECORD_ID.

### `DUMMYSTRUCTNAME.Attributes`

Attribute flags that describe the error record. No attributes are currently defined.

### `DUMMYSTRUCTNAME.DoNotLog`

A single bit that indicates that WHEA should not log an entry in the system event log for the error record.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use. This member must be zero.

### `AsULONGLONG`

A ULONGLONG representation of the contents of the WHEA_PERSISTENCE_INFO union.

## Remarks

A WHEA_PERSISTENCE_INFO union is contained within the [WHEA_ERROR_RECORD_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header) structure.

## See also

[WHEA_ERROR_RECORD_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header)