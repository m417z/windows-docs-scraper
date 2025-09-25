# WakeByAddressAll function

## Description

Wakes all threads that are waiting for the value of an address to change.

## Parameters

### `Address` [in]

The address to signal. If any threads have previously called [WaitOnAddress](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitonaddress) for this address, the system wakes all of the waiting threads.

## Remarks

Microsoft Store app developers may need to obtain `synchronization.lib` by installing the [Windows Software Development Kit (SDK)](https://developer.microsoft.com/windows/downloads/windows-sdk/).

Only threads within the same process can be woken.

## See also

[WaitOnAddress](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitonaddress)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)