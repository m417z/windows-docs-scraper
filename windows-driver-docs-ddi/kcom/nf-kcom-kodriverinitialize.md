# KoDriverInitialize function

## Description

*This function is intended for internal use only.*

The **KoDriverInitialize** function initializes a driver object to handle the kernel streaming interface.

## Parameters

### `DriverObject` [in]

Pointer to a driver object to initialize that handles the kernel streaming interface.

### `RegistryPathName` [in]

Pointer to the registry path that is associated with the driver object.

### `CreateObjectHandler` [in]

Pointer to a function used to create new objects.

## Return value

Returns STATUS_SUCCESS if successful. Otherwise, it returns a memory allocation error.