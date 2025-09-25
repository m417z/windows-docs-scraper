# ExInterlockedAddLargeStatistic macro

## Description

The **ExInterlockedAddLargeStatistic** routine performs an interlocked addition of a ULONG increment value to a LARGE_INTEGER variable.

## Parameters

### `Addend` [in]

A pointer to the LARGE_INTEGER variable that is incremented by the value of *Increment*.

### `Increment` [in]

Specifies a ULONG value that is added to the variable that *Addend* points to.

## Remarks

Support routines that do interlocked operations must not cause a page fault. Neither their code nor any of the data they access can cause a page fault without bringing down the system.

**ExInterlockedAddLargeStatistic** masks interrupts, and can be safely used to synchronize an ISR with other driver code.

**ExInterlockedAddLargeStatistic** runs at any IRQL. The storage for the *Addend* parameter must be resident at all IRQLs.

## See also

[ExInterlockedAddLargeInteger](https://learn.microsoft.com/previous-versions/ff545335(v=vs.85))

[ExInterlockedAddUlong](https://learn.microsoft.com/previous-versions/ff545343(v=vs.85))