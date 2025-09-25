# DlSetRegistryParameters function

## Description

Writes information under the adapter key in the registry.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `ValueName`

Pointer to a buffer containing a null-terminated Unicode string that names the value entry for which data is being written in the registry.

### `ValueData`

Pointer to a buffer containing the values to be written for the *ValueName* entry.

### `ValueLength`

Specifies the size, in bytes, of the data to be written to the registry.

## Return value

This function returns VP_STATUS.

## Remarks

## See also