## Description

Determines whether two UUIDs match each other. If both are short UUIDs, or if both are long UUIDs, then they are compared directly. Otherwise, the short UUID will be converted to a long UUID using the Bluetooth BASE UUID, and then compared against the long one.

## Parameters

### `uuid1`

Type: \_In\_ **[BTH_LE_UUID](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bth_le_uuid)**

Left comparand.

### `uuid2`

Type: \_In\_ **[BTH_LE_UUID](https://learn.microsoft.com/windows/win32/api/bthledef/ns-bthledef-bth_le_uuid)**

Right comparand.

## Return value

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** if the values are equal, **FALSE** otherwise.

## Remarks

## See also