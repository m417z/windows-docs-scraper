# DRT_STATUS enumeration

## Description

The **DRT_STATUS** enumeration defines the status of a local DRT instance.

## Constants

### `DRT_ACTIVE:0`

The local node is connected to the DRT mesh and participating in the DRT system. This is also an indication that remote nodes exist and are present in the cache of the local node.

### `DRT_ALONE:1`

The local node is participating in the DRT system, but is waiting for remote nodes to join the DRT mesh. This is an indication that remote nodes do not exist, or are not yet present in the cache of the local node.

### `DRT_NO_NETWORK:10`

The local node does not have network connectivity.

### `DRT_FAULTED:20`

A critical error has occurred in the local DRT instance. The [DrtClose](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtclose) function must be called, after which an attempt to re-open the DRT can be made.

## See also

[DrtClose](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtclose)

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)