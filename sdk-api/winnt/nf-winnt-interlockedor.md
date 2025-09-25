# InterlockedOr function

## Description

Performs an atomic OR operation on the specified **LONG** values. The function prevents more than one thread from using the same variable simultaneously.

## Parameters

### `Destination` [in, out]

A pointer to the first operand. This value will be replaced with the result of the operation.

### `Value` [in]

The second operand.

## Return value

The function returns the original value of the *Destination* parameter.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

For the Intel Itanium-based systems and x64 architectures, this function is implemented using the compiler intrinsic. For the x86 architecture, use the [_InterlockedOr](https://learn.microsoft.com/previous-versions/b11125ze(v=vs.85)) compiler intrinsic directly.

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Itanium-based systems:** For performance-critical applications, use [InterlockedOrAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683643(v=vs.85)) or [InterlockedOrRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683646(v=vs.85)) instead.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedOr16](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedor16)

[InterlockedOr16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683629(v=vs.85))

[InterlockedOr16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972669(v=vs.85))

[InterlockedOr16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683631(v=vs.85))

[InterlockedOr64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683633(v=vs.85))

[InterlockedOr64Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683634(v=vs.85))

[InterlockedOr64NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972670(v=vs.85))

[InterlockedOr64Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683636(v=vs.85))

[InterlockedOr8](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedor8)

[InterlockedOr8Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683639(v=vs.85))

[InterlockedOr8NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972671(v=vs.85))

[InterlockedOr8Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683640(v=vs.85))

[InterlockedOrAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683643(v=vs.85))

[InterlockedOrNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972672(v=vs.85))

[InterlockedOrRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683646(v=vs.85))

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)