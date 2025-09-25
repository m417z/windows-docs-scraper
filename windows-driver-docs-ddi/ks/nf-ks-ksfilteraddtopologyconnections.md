# KsFilterAddTopologyConnections function

## Description

The **KsFilterAddTopologyConnections** function adds new topology connections to a filter.

## Parameters

### `Filter` [in]

*A pointer* to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) to which to add the new connections.

### `NewConnectionsCount` [in]

The number of connections in *NewTopologyConnections*.

### `NewTopologyConnections` [in]

A pointer to an array of [KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection) structures containing the new topology connections.

## Return value

**KsFilterAddTopologyConnections** returns STATUS_SUCCESS or an error code indicating failure of the attempt to add topology connections.

## Remarks

Note that the filter control mutex must be held before calling this function.

For more information about mutexes, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection)