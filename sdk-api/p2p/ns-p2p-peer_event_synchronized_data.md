# PEER_EVENT_SYNCHRONIZED_DATA structure

## Description

The **PEER_EVENT_SYNCHRONIZED_DATA** is pointed to by a [PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data) structure's union if a PEER_GRAPH_EVENT_RECORD_CHANGE or PEER_GROUP_EVENT_RECORD_CHANGE event is triggered. The **PEER_EVENT_SYNCHRONIZED_DATA** structure indicates the type of record that has been synchronized.

## Members

### `dwSize`

Specifies the size of the structure.

### `recordType`

Specifies the type of record that is being synchronized.

## Remarks

This event only occurs if an application has specified a record synchronization precedence in a previous call to [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen).

## See also

[PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data)