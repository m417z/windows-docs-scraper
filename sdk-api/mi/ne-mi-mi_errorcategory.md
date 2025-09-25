# MI_ErrorCategory enumeration

## Description

This enumeration defines error categories for the CIM extensions.

## Constants

### `MI_ERRORCATEGORY_NOT_SPECIFIED:0`

Use only when not enough is known about the error to assign it to another error category. Avoid using this category if you have any information about the error, even if that information is incomplete.

### `MI_ERRORCATEGORY_OPEN_ERROR:1`

An error that occurs when opening.

### `MI_ERRORCATEGORY_CLOS_EERROR:2`

An error that occurs when closing.

### `MI_ERRORCATEGORY_DEVICE_ERROR:3`

An error that occurs when a device reports an error.

### `MI_ERRORCATEGORY_DEADLOCK_DETECTED:4`

An error that occurs when a deadlock is detected.

### `MI_ERRORCATEGORY_INVALID_ARGUMENT:5`

An error that occurs when an argument that is not valid is specified.

### `MI_ERRORCATEGORY_INVALID_DATA:6`

An error that occurs when data that is not valid is specified.

### `MI_ERRORCATEGORY_INVALID_OPERATION:7`

An error that occurs when an operation that is not valid is requested.

### `MI_ERRORCATEGORY_INVALID_RESULT:8`

An error that occurs when a result that is not valid is returned.

### `MI_ERRORCATEGORY_INVALID_TYPE:9`

An error that occurs when a .NET Framework type that is not valid is specified.

### `MI_ERRORCATEGORY_METADATA_ERROR:10`

An error that occurs when metadata contains an error.

### `MI_ERRORCATEGORY_NOT_IMPLEMENTED:11`

An error that occurs when a referenced application programming interface (API) is not implemented.

### `MI_ERRORCATEGORY_NOT_INSTALLED:12`

An error that occurs when an item is not installed.

### `MI_ERRORCATEGORY_OBJECT_NOT_FOUND:13`

An error that occurs when an object cannot be found.

### `MI_ERRORCATEGORY_OPERATION_STOPPED:14`

An error that occurs when an operation has stopped. For example, the user interrupts the operation.

### `MI_ERRORCATEGORY_OPERATION_TIMEOUT:15`

An error that occurs when an operation has exceeded its timeout limit.

### `MI_ERRORCATEGORY_SYNTAX_ERROR:16`

An error that occurs when a command is syntactically incorrect.

### `MI_ERRORCATEGORY_PARSER_ERROR:17`

An error that occurs when a parser encounters an error.

### `MI_ERRORCATEGORY_ACCESS_DENIED:18`

An error that occurs when an operation is not permitted.

### `MI_ERRORCATEGORY_RESOURCE_BUSY:19`

An error that occurs when a resource already exists.

### `MI_ERRORCATEGORY_RESOURCE_EXISTS:20`

An error that occurs when a resource is busy.

### `MI_ERRORCATEGORY_RESOURCE_UNAVAILABLE:21`

An error that occurs when a resource is unavailable.

### `MI_ERRORCATEGORY_READ_ERROR:22`

An error that occurs when reading.

### `MI_ERRORCATEGORY_WRITE_ERROR:23`

### `MI_ERRORCATEGORY_FROM_STDERR:24`

### `MI_ERRORCATEGORY_SECURITY_ERROR:25`

An error that occurs when a security violation occurs.

### `MI_ERRORCATEGORY_PROTOCOL_ERROR:26`

### `MI_ERRORCATEGORY_CONNECTION_ERROR:27`

### `MI_ERRORCATEGORY_AUTHENTICATION_ERROR:28`

### `MI_ERRORCATEGORY_LIMITS_EXCEEDED:29`

### `MI_ERRORCATEGORY_QUOTA_EXCEEDED:30`

### `MI_ERRORCATEGORY_NOT_ENABLED:31`