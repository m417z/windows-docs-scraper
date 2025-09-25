# KeQueryTotalCycleTimeThread function

## Description

The **KeQueryTotalCycleTimeThread** routine returns the accumulated cycle time for the specified thread.

## Parameters

### `Thread` [in, out]

A pointer to a dispatcher object of type KTHREAD.

### `CycleTimeStamp` [out]

A pointer to the cycle counter value at the time of the query.

## Return value

The accumulated cycle time for the thread.