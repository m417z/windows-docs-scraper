## Description

The **USBCAMD_GetRegistryKeyValue** function retrieves the device-instance-specific registry key value.

## Parameters

### `Handle` [in]

Handle to a valid and open device registry key.

### `KeyNameString` [in]

Pointer to the string buffer describing the key type.

### `KeyNameStringLength` [in]

Specifies the length, in characters, of *KeyNameString*.

### `Data` [in]

Pointer to a caller-specified value or structure.

### `DataLength` [in]

Specifies the length, in bytes, of the value or structure at *Data.*

## Return value

**USBCAMD_GetRegistryKeyValue** returns STATUS_SUCCESS if the call was successful.

Other possible error codes include:

| Return code | Description |
|---|---|
| **STATUS_NO_MEMORY** | There was insufficient memory to continue. |