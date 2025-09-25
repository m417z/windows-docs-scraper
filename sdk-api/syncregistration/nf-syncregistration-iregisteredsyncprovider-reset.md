# IRegisteredSyncProvider::Reset

## Description

Resets a synchronization provider so that it looks like a new replica
in the next synchronization session.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The writer of a synchronization provider may choose not to implement this method.

## See also

[IRegisteredSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-iregisteredsyncprovider)