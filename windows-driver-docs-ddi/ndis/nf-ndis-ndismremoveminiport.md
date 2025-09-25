# NdisMRemoveMiniport function

## Description

The
**NdisMRemoveMiniport** function removes the specified miniport driver adapter that the miniport driver
has determined is unrecoverable from the system.

## Parameters

### `MiniportHandle`

The handle to the initialized miniport adapter that the miniport driver has determined is
unrecoverable.

## Return value

**NdisMRemoveMiniport** can return either of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport adapter has been removed. |
| **NDIS_STATUS_FAILURE** | An attempt to remove the miniport adapter failed. |

## Remarks

If a miniport driver has determined that a particular miniport adapter has failed and is
unrecoverable, the miniport driver can call
**NdisMRemoveMiniport** to remove the miniport adapter from the local computer system. In this call,
the miniport driver passes the handle to the miniport adapter to remove.

For example, if a miniport driver detects that a miniport adapter is resetting very frequently and is
causing the computer to freeze every few seconds, the driver can request NDIS to remove the miniport
adapter.