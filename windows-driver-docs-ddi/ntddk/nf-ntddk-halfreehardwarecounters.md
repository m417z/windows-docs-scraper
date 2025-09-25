## Description

The **HalFreeHardwareCounters** routine frees a set of hardware performance counter resources that was acquired in a previous call to [**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) routine.

## Parameters

### `CounterSetHandle` [in]

A handle to the allocated counter resources. The caller acquired this handle in a previous call to [**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters).

## Return value

**HalFreeHardwareCounters** returns STATUS_SUCCESS if the call was successful. Possible error return values include the following:

| Return code | Description |
|--|--|
| **STATUS_INVALID_PARAMETER** | Parameter *CounterSetHandle* is not a valid counter resources handle. |

## Syntax

```cpp
NTSTATUS HalFreeHardwareCounters(
  _In_ HANDLE CounterSetHandle
);
```

## Remarks

Before calling this function, the client driver is expected to stop and clear the associated counter resources.

## See also

[**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters)