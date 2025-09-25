# TdhUnloadManifestFromMemory function (tdh.h)

## Description

Unloads the manifest from memory.

## Parameters

### `pData` [in]

Type: **const void***

Pointer to the data to be stored.

### `cbData` [in]

Type: **ULONG**

Size of the data in the buffer pointed to by *pData*, in bytes.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| -- | -- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_FILE_NOT_FOUND** | The file pointed to by *pData* was not found. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory allocations failed. |
| **ERROR_RESOURCE_NOT_FOUND** | The file does not contain any eventing metadata resources. |

## Remarks

## See also