# InterlockedXor16 function

## Description

Performs an atomic XOR operation on the specified **SHORT** values. The function prevents more than one thread from using the same variable simultaneously.

## Parameters

### `Destination` [in, out]

A pointer to the first operand. This value will be replaced with the result of the operation.

### `Value` [in]

The second operand.

## Return value

The function returns the original value of the *Destination* parameter.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

For the Intel Itanium-based systems and x64 architectures, this function is implemented using the compiler intrinsic. For the x86 architecture, use the [_InterlockedXor16](https://learn.microsoft.com/previous-versions/a8swb4hb(v=vs.85)) compiler intrinsic directly.

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Itanium-based systems:** For performance-critical applications, use [InterlockedXor16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684026(v=vs.85)) or [InterlockedXor16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684033(v=vs.85)) instead.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedXor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedxor)

[InterlockedXor16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684026(v=vs.85))

[InterlockedXor16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972674(v=vs.85))

[InterlockedXor16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684033(v=vs.85))

[InterlockedXor64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedxor64)

[InterlockedXor64Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684107(v=vs.85))

[InterlockedXor64NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972675(v=vs.85))

[InterlockedXor64Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684108(v=vs.85))

[InterlockedXor8](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedxor8)

[InterlockedXor8Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684112(v=vs.85))

[InterlockedXor8NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972676(v=vs.85))

[InterlockedXor8Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684113(v=vs.85))

[InterlockedXorAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684117(v=vs.85))

[InterlockedXorNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972677(v=vs.85))

[InterlockedXorRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms684118(v=vs.85))

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)