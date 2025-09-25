# RO_INIT_TYPE enumeration

## Description

Determines the concurrency model used for incoming calls to the objects created by this thread.

## Constants

### `RO_INIT_SINGLETHREADED:0`

### `RO_INIT_MULTITHREADED:1`

Initializes the thread for multi-threaded concurrency. The current thread is initialized in the MTA.

## Remarks

Pass the **RO_INIT_TYPE** enumeration to the [RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize) function to initialize a thread in the Windows Runtime.

## See also

[RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize)