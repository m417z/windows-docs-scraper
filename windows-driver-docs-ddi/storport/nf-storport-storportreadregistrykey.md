## Description

The **StorPortReadRegistryKey** function is used by the miniport to read the specified registry key. The caller provides the absolute path to the key to be read.

## Parameters

### `HwDeviceExtension`

A pointer to the hardware device extension. This is specific to the miniport driver instance.

### `AbsolutePath`

The absolute path to the key to be read.

### `KeyName`

The key path under the absolute path.

### `ValueType`

The type of the registry key value in REG_XXXX format. Currently, only REG_DWORD value type is supported.

### `ValueData`

Pointer to the data buffer to receive the registry key value.

### `ValueDataLength`

The size of the *ValueData*, in bytes.

## Return value

Returns a STOR_STATUS code as defined in storport.h.

## Remarks

## See also