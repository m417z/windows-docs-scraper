# _D3DDDI_WAITFORSYNCHRONIZATIONOBJECTFROMCPU_FLAGS structure

## Description

**D3DDDI_WAITFORSYNCHRONIZATIONOBJECTFROMCPU_FLAGS** describes the type of input synchronization objects to wait for.

## Members

### `WaitAny`

|Value|Meaning|
|--- |--- |
|0 (FALSE)|[in] The wait condition is considered to be satisfied when all input synchronization objects are signaled to the corresponding input fence values or greater.|
|1 (TRUE)|[in] The wait condition is considered to be satisfied when any of the input synchronization objects is signaled to the corresponding input fence value or greater.|

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

The consolidated value of the bitfields in the nested structure.