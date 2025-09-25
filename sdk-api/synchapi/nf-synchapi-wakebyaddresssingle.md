# WakeByAddressSingle function

## Description

Wakes one thread that is waiting for the value of an address to change.

## Parameters

### `Address` [in]

The address to signal. If another thread has previously called [WaitOnAddress](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitonaddress) for this address, the system wakes the waiting thread. If multiple threads are waiting for this address, the system wakes the first thread to wait.

## Remarks

Microsoft Store app developers may need to obtain `synchronization.lib` by installing the [Windows Software Development Kit (SDK)](https://developer.microsoft.com/windows/downloads/windows-sdk/).

Only a thread within the same process can be woken.

## See also

[WaitOnAddress](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitonaddress)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)