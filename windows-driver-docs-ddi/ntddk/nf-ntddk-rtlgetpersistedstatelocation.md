# RtlGetPersistedStateLocation function

## Description

Retrieves the redirected location for the specified SourceID from the redirection map.

## Parameters

### `SourceID` [_In_]

The identifier to lookup in the redirection map.

### `CustomValue` [_In_opt_]

Optional. The value to retrieve, if it's different than the default value.

### `DefaultPath` [_In_opt_]

Optional. If an entry for the **SourceID** value cannot be found in the map, returns this value.

### `StateLocationType` [_In_]

A [**STATE_LOCATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_state_location_type)-type value that indicates the type of State to look up; registry or file system.

### `TargetPath` [_In_]

A pointer to a Unicode string that receives the value. If the call is successful. The string is null-terminated.

### `BufferLengthIn` [_In_]

The size of the string pointed to by _TargetPath_, in bytes.

### `BufferLengthOut` [_Out_opt_]

Optional. If specified, returns the number of bytes written to the buffer in case the call is successful; number of bytes required if the call fails with the STATUS_BUFFER_OVERFLOW error code.

## Return value

Returns an NTSTATUS value that indicates the success of failure of the operation. Otherwise returns an appropriate [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also

[**STATE_LOCATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_state_location_type)