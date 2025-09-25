# DRT_ADDRESS_FLAGS enumeration

## Description

The **DRT_ADDRESS_FLAGS** enumeration defines the set of responses that may be returned by an intermediate node when performing a search for a key.

## Constants

### `DRT_ADDRESS_FLAG_ACCEPTED:0x01`

The response provided by this machine was successfully used to make progress towards the search target.

### `DRT_ADDRESS_FLAG_REJECTED:0x02`

The response provided by this machine was not used in the search. This machine may have provided the address of a node publishing a key numerically farther from the target than other nodes already contacted.

### `DRT_ADDRESS_FLAG_UNREACHABLE:0x04`

This machine did not respond.

### `DRT_ADDRESS_FLAG_LOOP:0x08`

The response provided by this machine was not used in the search. This machine provided the address of a node that has already been contacted.

### `DRT_ADDRESS_FLAG_TOO_BUSY:0x10`

This machine indicated that it does not have sufficient resources to process the query.

### `DRT_ADDRESS_FLAG_BAD_VALIDATE_ID:0x20`

This machine is not publishing the key expected by the local DRT instance. As a result, it may not be able to provide useful information.

### `DRT_ADDRESS_FLAG_SUSPECT_UNREGISTERED_ID:0x40`

This machine has reason to believe that the target key has been unregistered.

### `DRT_ADDRESS_FLAG_INQUIRE:0x80`

This machine was asked to provide proof of ownership of its key.