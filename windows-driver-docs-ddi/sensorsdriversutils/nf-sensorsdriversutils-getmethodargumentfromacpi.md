# GetMethodArgumentFromAcpi function

## Description

The GetMethodArgumentFromAcpi function reads the requested ACPI entry by using the supplied method name.

## Parameters

### `Device`

Supplies the WDF device object.

### `MethodName`

Supplies the method name to read.

### `MethodNameLength`

Supplies the method name length in bytes.

### `MethodArgument`

Supplies the address at which to write the method argument.

### `MethodArgumentLength`

Supplies the length in bytes of the buffer in which to save the MethodArgument.

## Return value

This function returns NTSTATUS.

## Remarks

## See also