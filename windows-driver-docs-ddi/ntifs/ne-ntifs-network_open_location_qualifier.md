# NETWORK_OPEN_LOCATION_QUALIFIER enumeration

## Description

The NETWORK_OPEN_LOCATION_QUALIFIER enumeration type contains values that identify the kind of location restriction to attach to a file.

## Constants

### `NetworkOpenLocationAny`

Indicates that the file has no location restrictions. That is, a caller can open the file whether it resides remotely or locally.

### `NetworkOpenLocationRemote`

Indicates that the file is restricted to only opening remotely. That is, a caller can only open the file if it resides on a different computer from the computer that the caller resides on.

### `NetworkOpenLocationLoopback`

Indicates that the file is restricted to only opening locally. That is, a caller can only open the file if it resides on the same computer as the caller.