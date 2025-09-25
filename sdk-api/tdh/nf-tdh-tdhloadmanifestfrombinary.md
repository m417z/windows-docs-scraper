# TdhLoadManifestFromBinary function

## Description

Takes a NULL-terminated path to a binary file that contains metadata resources needed to decode a specific event provider.

## Parameters

### `BinaryPath` [in]

Type: **PWSTR**

Path to the ETW provider binary that contains the metadata resources.

## Return value

Type: **ULONG**

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| -- | -- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_FILE_NOT_FOUND** | The file pointed to by *BinaryPath* was not found. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory allocations failed. |
| **ERROR_RESOURCE_NOT_FOUND** | The file does not contain any eventing metadata resources. |

## Remarks

The GUIDs
and BinaryPath string are cached.

When metadata is
requested for a given event or provider, but the provider is not installed in the system, the cache
of binaries will be searched.