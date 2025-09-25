# _interlockedbittestandset function

## Description

Tests the specified bit of the specified **LONG** value and sets it to 1. The operation is atomic.

## Parameters

### `Base` [in]

A pointer to a variable.

### `Offset` [in]

The bit position to be tested. The offset is from the least-significant bit position, with zero testing the least-significant bit, and 31 testing the most-significant bit.

## Return value

The original value of the specified bit.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is implemented using a compiler intrinsic where possible. For more information, see the WinBase.h header file and [_interlockedbittestandset](https://learn.microsoft.com/previous-versions/646k06sz(v=vs.85)).

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedBitTestAndReset](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-_interlockedbittestandreset)

[InterlockedBitTestAndReset64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-_interlockedbittestandreset64)

[InterlockedBitTestAndResetAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972636(v=vs.85))

[InterlockedBitTestAndResetRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972637(v=vs.85))

[InterlockedBitTestAndSet64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-_interlockedbittestandset64)

[InterlockedBitTestAndSetAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972638(v=vs.85))

[InterlockedBitTestAndSetRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972639(v=vs.85))

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)