# IDebugControl3::GetNumberEventFilters

## Description

The **GetNumberEventFilters** method returns the number of [event filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters) currently used by the engine.

## Parameters

### `SpecificEvents` [out]

Receives the number of [events](https://learn.microsoft.com/windows-hardware/drivers/debugger/events) that can be controlled using the specific event filters. These events are enumerated using some of the [DEBUG_FILTER_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) constants.

### `SpecificExceptions` [out]

Receives the number of [exceptions](https://learn.microsoft.com/windows-hardware/drivers/) that can be controlled using the specific exception filters. The first specific exception filter is the default exception filter. The exceptions controlled by the other specific exception filters will always have their own filter and will not inherit their behavior from the default specific exception filter. These exception filters are identified by their exception code. See [Specific Exceptions](https://learn.microsoft.com/windows-hardware/drivers/debugger/specific-exceptions) for a list of the specific exception filters.

### `ArbitraryExceptions` [out]

Receives the number of arbitrary exception filters currently used by the engine. These exception filters are identified by their exception code.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about event filters, see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).