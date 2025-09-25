## Description

Adds a custom registry entry to the device interface registry key.

## Parameters

### `EntryName`

A null-terminated Unicode string representing the registry entry name.

### `SubkeyPath`

Optional null-terminated Unicode string representing a subkey under the device interface registry node.

### `dwRegType`

The data type of the registry entry. The **REG_NONE** type is not supported. For more information, see [Registry Value Types](https://learn.microsoft.com/windows/win32/sysinfo/registry-value-types).

### `pbData`

Pointer to the data for the registry entry.

### `cbData`

Size of the data in the buffer pointed to by *pbData*, in bytes.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_INVALIDARG | An input parameter is invalid. |
| E_ACCESSDENIED | Caller has insufficient permissions to add properties. |

## Remarks

Callers must have administrator-level permissions to use this API. UWP and packaged apps do not have permissions to call this method.

## See also