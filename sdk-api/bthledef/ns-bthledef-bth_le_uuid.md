## Description

The BTH_LE_UUID structure contains information about a Bluetooth Low Energy (LE) Universally Unique Identifier (UUID).

## Members

### `IsShortUuid`

Indicates if the Low Energy (LE) UUID a 16-bit shortened value, or if it is the long 128-bit value.

### `Value`

The value of the UUID.

### `Value.ShortUuid`

The short 16-bit value of the UUID. This member applies only if **IsShortUuid** is TRUE.

### `Value.LongUuid`

The long 128-bit value of the UUID. This member applies only if **IsShortUuid** is FALSE.

## See also

[BTH_LE_GATT_SERVICE](https://learn.microsoft.com/windows/desktop/api/bthledef/ns-bthledef-bth_le_gatt_service)