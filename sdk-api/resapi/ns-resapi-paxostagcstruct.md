# PaxosTagCStruct structure

## Description

Contains the Paxos tag values of a cluster node, which stores information about the cluster configuration version of the node when the cluster uses a File Share witness.

## Members

### `__padding__PaxosTagVtable`

TBD

### `__padding__NextEpochVtable`

TBD

### `__padding__NextEpoch_DateTimeVtable`

TBD

### `NextEpoch_DateTime_ticks`

TBD

### `NextEpoch_Value`

The next epoch of the cluster configuration.

### `__padding__BoundryNextEpoch`

TBD

### `__padding__EpochVtable`

TBD

### `__padding__Epoch_DateTimeVtable`

TBD

### `Epoch_DateTime_ticks`

TBD

### `Epoch_Value`

The epoch of the cluster configuration.

### `__padding__BoundryEpoch`

TBD

### `Sequence`

The sequence of the cluster configuration.

### `__padding__BoundrySequence`

TBD

## See also

[ResUtilLeftPaxosIsLessThanRight](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-resutilleftpaxosislessthanright)

[ResUtilPaxosComparer](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-resutilpaxoscomparer)

[Resource DLL Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-structures)

[WitnessTagHelper](https://learn.microsoft.com/windows/desktop/api/resapi/ns-resapi-witnesstaghelper)

[WitnessTagUpdateHelper](https://learn.microsoft.com/windows/desktop/api/resapi/ns-resapi-witnesstagupdatehelper)