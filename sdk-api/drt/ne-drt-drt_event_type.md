# DRT_EVENT_TYPE enumeration

## Description

The **DRT_EVENT_TYPE** enumeration defines the set of events that can be raised by the Distributed Routing Table.

## Constants

### `DRT_EVENT_STATUS_CHANGED:0`

The status of the local DRT instance has changed.

### `DRT_EVENT_LEAFSET_KEY_CHANGED:1`

A key or node was changed from the DRT leaf set of the local node.

### `DRT_EVENT_REGISTRATION_STATE_CHANGED:2`

A locally published key is no longer resolvable by other nodes.

## Remarks

The event handle passed to [DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen) is signaled with an event specified by the **DRT_EVENT_TYPE** enumeration.

## See also

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)