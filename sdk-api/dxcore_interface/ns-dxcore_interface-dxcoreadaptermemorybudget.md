## Description

Describes the memory budget for an adapter.

## Members

### `budget`

Type: **uint64_t**

Specifies the OS-provided adapter memory budget, in bytes, that your application should target. If *currentUsage* is greater than *budget*, then your application may incur stuttering or performance penalties due to background activity by the OS, which is intended to provide other applications with a fair usage of adapter memory.

### `currentUsage`

Type: **uint64_t**

Specifies your application's current adapter memory usage, in bytes.

### `availableForReservation`

Type: **uint64_t**

Specifies the amount of adapter memory, in bytes, that your application has available for reservation. To reserve this adapter memory, your application should call [IDXCoreAdapter::SetState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-setstate) with *state* set to [DXCoreAdapterState::AdapterMemoryBudget](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ne-dxcore_interface-dxcoreadapterstate).

### `currentReservation`

Type: **uint64_t**

Specifies the amount of adapter memory, in bytes, that is reserved by your application. The OS uses the reservation as a hint to determine your application's minimum working set. Your application should attempt to ensure that its adapter memory usage can be trimmed to meet this requirement.

## See also

[DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters)