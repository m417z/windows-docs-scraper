# KSSTATE enumeration

## Description

The KSSTATE enumeration lists possible states of a kernel streaming object.

## Constants

### `KSSTATE_STOP`

Indicates that the object is in minimum resource consumption mode.

### `KSSTATE_ACQUIRE`

Indicates that the object is acquiring resources.

### `KSSTATE_PAUSE`

Indicates that the object is preparing to make instant transition to Run state.

### `KSSTATE_RUN`

Indicates that the object is actively streaming.