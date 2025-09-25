# PEER_EVENT_RECORD_CHANGE_DATA structure

## Description

The [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1) structure points to the **PEER_EVENT_RECORD_CHANGE_DATA** structure if one of the following peer events is triggered:

* **PEER_GRAPH_EVENT_RECORD_CHANGE**
* **PEER_GROUP_EVENT_RECORD_CHANGE**

The **PEER_EVENT_RECORD_CHANGE_DATA** structure contains updated information that an application requests for data changes to a record or record type.

## Members

### `dwSize`

Specifies the size of a structure.

### `changeType`

Specifies the type of change to a record or record type.

### `recordId`

Specifies the unique ID of a changed record.

### `recordType`

Specifies the unique record type of a changed record.

## See also

[PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data)

[PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)

[PEER_RECORD_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_record_change_type)