# DlGetRegistryParameters function

## Description

Retrieves device-specific configuration information under the adapter key in the registry at startup.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `ParameterName`

Pointer to a NULL-terminated Unicode string that names the value entry to be retrieved from the registry.

### `IsParameterFileName`

If the value is TRUE, the data value normally returned is treated as a file name.

### `CallbackRoutine`

### `Context`

Pointer to a caller-determined context parameter.

## Return value

This function returns VP_STATUS.

## Remarks

## See also