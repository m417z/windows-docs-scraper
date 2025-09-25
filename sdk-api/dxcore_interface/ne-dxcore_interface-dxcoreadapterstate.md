## Description

Defines constants that specify kinds of DXCore adapter states. Pass one of these constants to the [IDXCoreAdapter::QueryState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-querystate) method to retrieve the adapter state item for a state kind; pass a constant to the [IDXCoreAdapter::SetState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-setstate) method to set an adapter's info for a state item.

## Constants

### `IsDriverUpdateInProgress:0`

Specifies the *IsDriverUpdateInProgress* adapter state, which when `true` indicates that a driver update has been initiated on the adapter but it has not yet completed. If the driver update has already completed, then the adapter will have been invalidated, and your [QueryState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-querystate) call will return a **HRESULT** of **DXGI_ERROR_DEVICE_REMOVED**.

When calling [QueryState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-querystate), the *IsDriverUpdateInProgress* state item has type **uint8_t**, representing a Boolean value.

**Important**. This state item is not supported for [SetState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-setstate).

### `AdapterMemoryBudget:1`

Specifies the *AdapterMemoryBudget* adapter state, which retrieves or requests the adapter memory budget on the adapter.

When calling [QueryState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-querystate), the *AdapterMemoryBudget* adapter state has type [DXCoreAdapterMemoryBudgetNodeSegmentGroup](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ns-dxcore_interface-dxcoreadaptermemorybudgetnodesegmentgroup) for *inputStateDetails*, and type [DXCoreAdapterMemoryBudget](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ns-dxcore_interface-dxcoreadaptermemorybudget) for *outputBuffer*.

**Important**. This state item is not supported for [SetState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-setstate).

### `AdapterMemoryUsageBytes:2`

This query takes Physical Adapter Index and Dedicated vs. Shared as input; and outputs the Committed and Resident Memory Dedicated or Shared portions of GPU Memory, respectively.

### `AdapterMemoryUsageByProcessBytes:3`

This query takes Engine ID, Physical Adapter Index, and Process Handle as input; and outputs Committed Memory and Resident Memory on Dedicated or Shared portions of GPU Memory, respectively.

### `AdapterEngineRunningTimeMicroseconds:4`

This query takes Engine ID and Physical Adapter Index as input; and outputs Engine Running Time as output.

### `AdapterEngineRunningTimeByProcessMicroseconds:5`

This query takes Engine ID, Physical Adapter Index, and Process Handle as input; and outputs Engine Running Time as output.

### `AdapterTemperatureCelsius:6`

This query takes Physical Adapter Index as input, and outputs Current GPU Temperature in Degrees Celsius.

### `AdapterInUseProcessCount:7`

This returns the number of processes using this adapter, and the PIDs in it, respectively.

### `AdapterInUseProcessSet:8`

This returns the number of processes using this adapter, and the PIDs in it, respectively.

### `AdapterEngineFrequencyHertz:9`

This query takes in the physical adapter and engine indices, and outputs the clock frequency of the respective engine in hertz. The output structure also includes the maximum frequency for the engine, with and without overclocking.

```
uint64_t GetEngineFrequency(com_ptr adapter, uint32_t physicalIndex, uint32_t engineIndex)
{
    DXCoreAdapterEngineIndex index;
    index.PhysicalAdapterIndex = physicalIndex;
    index.EngineIndex = engineIndex;

    DXCoreFrequencyQueryOutput frequencyData = {};

    winrt::check_hresult(adapter->QueryState(DXCoreAdapterState::AdapterEngineFrequencyHertz, &index, &frequencyData));

    return frequencyData.Frequency;
}
```

### `AdapterMemoryFrequencyHertz:10`

This query takes in the physical adapter index, and outputs the clock frequency of its memory in hertz. The output structure also includes the maximum frequency for the memory, with and without overclocking.

```
uint64_t GetEngineFrequency(com_ptr adapter, uint32_t physicalIndex, uint32_t engineIndex)
{
uint64_t GetMemoryFrequency(com_ptr adapter, uint32_t physicalIndex)
{
    DXCoreFrequencyQueryOutput frequencyData = {};

    winrt::check_hresult(adapter->QueryState(DXCoreAdapterState::AdapterMemoryFrequencyHertz, &physicalIndex, &frequencyData));

    return frequencyData.frequency;
}
```

## See also

[IDXCoreAdapter::QueryState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-querystate), [IDXCoreAdapter::SetState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-setstate), [DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters)