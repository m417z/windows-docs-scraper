# WaitOnAddress function

## Description

Waits for the value at the specified address to change.

## Parameters

### `Address` [in]

The address on which to wait. If the value at *Address* differs from the value at *CompareAddress*, the function returns immediately. If the values are the same, the function does not return until another thread in the same process signals that the value at Address has changed by calling [WakeByAddressSingle](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakebyaddresssingle) or [WakeByAddressAll](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakebyaddressall) or the timeout elapses, whichever comes first.

### `CompareAddress` [in]

A pointer to the location of the previously observed value at *Address*. The function returns when the value at *Address* differs from the value at *CompareAddress*.

### `AddressSize` [in]

The size of the value, in bytes. This parameter can be `1`, `2`, `4`, or `8`.

### `dwMilliseconds` [in, optional]

The number of milliseconds to wait before the operation times out. If this parameter is **INFINITE**, the thread waits indefinitely.

## Return value

`TRUE` if the wait succeeded. If the operation fails, the function returns `FALSE`. If the wait fails, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain extended error information. In particular, if the operation times out, **GetLastError** returns **ERROR_TIMEOUT**.

## Remarks

Microsoft Store app developers may need to obtain `synchronization.lib` by installing the [Windows Software Development Kit (SDK)](https://developer.microsoft.com/windows/downloads/windows-sdk/).

The **WaitOnAddress** function can be used by a thread to wait for a particular value to change from some undesired value to any other value. **WaitOnAddress** is more efficient than using the [Sleep](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleep) function inside a `while` loop because **WaitOnAddress** does not interfere with the thread scheduler. **WaitOnAddress** is also simpler to use than an event object because it is not necessary to create and initialize an event and then make sure it is synchronized correctly with the value. **WaitOnAddress** is not affected by low-memory conditions, other than potentially waking the thread early as noted below.

Any thread within the same process that changes the value at the address on which threads are waiting should call [WakeByAddressSingle](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakebyaddresssingle) to wake a single waiting thread or [WakeByAddressAll](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakebyaddressall) to wake all waiting threads. If **WakeByAddressSingle** is called, other waiting threads continue to wait.

**Note:** **WaitOnAddress** is guaranteed to return when the address is signaled, but it is also allowed to return for other reasons. For this reason, after **WaitOnAddress** returns the caller should compare the new value with the original undesired value to confirm that the value has actually changed. For example, the following circumstances can result in waking the thread early:

* Low memory conditions
* A previous wake on the same address was abandoned
* Executing code on a checked build of the operating system

#### Examples

The following example shows how to use **WaitOnAddress**.

``` cpp
ULONG g_TargetValue; // global, accessible to all threads
ULONG CapturedValue;
ULONG UndesiredValue;

UndesiredValue = 0;
CapturedValue = g_TargetValue;
while (CapturedValue == UndesiredValue) {
      WaitOnAddress(&g_TargetValue, &UndesiredValue, sizeof(ULONG), INFINITE);
      CapturedValue = g_TargetValue;
}
```

## See also

[WakeByAddressAll](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakebyaddressall)

[WakeByAddressSingle](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-wakebyaddresssingle)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)