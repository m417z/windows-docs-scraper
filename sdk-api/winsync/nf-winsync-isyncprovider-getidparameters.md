# ISyncProvider::GetIdParameters

## Description

Gets the ID format schema of the provider.

## Parameters

### `pIdParameters` [out]

Returns the ID format schema of the provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **Provider-determined error codes.** |  |

## Remarks

This method is used to get the ID format schema from the two providers that are participating in synchronization. A synchronization session should use this method to verify that the two providers have the same ID format schema, so that they can synchronize with one another.

## See also

[ID_PARAMETERS Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-id_parameters)

[ISyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncprovider)