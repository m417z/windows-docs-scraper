# InterlockedAnd16 function

## Description

Performs an atomic AND operation on the specified **SHORT** values.

## Parameters

### `Destination` [in, out]

A pointer to the first operand. This value will be replaced with the result of the operation.

### `Value` [in]

The second operand.

## Return value

The function returns the original value of the *Destination* parameter.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

For the Intel Itanium-based systems and x64 architectures, this function is implemented using the compiler intrinsic. For the x86 architecture, use the [_InterlockedAnd16](https://learn.microsoft.com/previous-versions/dsx2t7yd(v=vs.85)) compiler intrinsic directly.

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Itanium-based systems:** For performance-critical applications, use [InterlockedAnd16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683521(v=vs.85)) or [InterlockedAnd16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683525(v=vs.85)) instead.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedAnd](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedand)

[InterlockedAnd16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683521(v=vs.85))

[InterlockedAnd16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972631(v=vs.85))

[InterlockedAnd16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683525(v=vs.85))

[InterlockedAnd64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedand64)

[InterlockedAnd64Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683529(v=vs.85))

[InterlockedAnd64NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972632(v=vs.85))

[InterlockedAnd64Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683530(v=vs.85))

[InterlockedAnd8](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedand8)

[InterlockedAnd8Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683535(v=vs.85))

[InterlockedAnd8NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972633(v=vs.85))

[InterlockedAnd8Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683537(v=vs.85))

[InterlockedAndAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683539(v=vs.85))

[InterlockedAndNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972634(v=vs.85))

[InterlockedAndRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683543(v=vs.85))

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)