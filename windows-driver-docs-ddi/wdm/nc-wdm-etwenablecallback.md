# ETWENABLECALLBACK callback function

## Description

The **EtwEnableCallback** function is an optional driver-supplied callback function that is used to receive enable or disable notifications.

## Parameters

### `SourceId` [in]

The GUID that identifies the session that enabled the provider.

### `ControlCode`

### `Level` [in]

The level at which the event is enabled. This parameter is a provider-defined value that specifies the verboseness of the events that the provider writes. The provider must write the event if this value is less than or equal to the level value that the event defines.

This value is passed in the *Level* parameter of the [EnableTraceEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex) function or the *EnableLevel* parameter of the [EnableTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletrace) function.

### `MatchAnyKeyword` [in]

The bitmask of keywords that the provider uses to determine the category of events that it writes.

This value is passed in the *MatchAnyKeyword* parameter of the [EnableTraceEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex) function or the *EnableFlag* parameter of the [EnableTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletrace) function. *MatchAnyKeyword* is a 64-bit value and is basically an extended version of the 32-bit *EnableFlag*.

### `MatchAllKeyword` [in]

This bitmask additionally restricts the category of events that the provider writes.

This value is passed in the *MatchAllKeywords* parameter of the **EnableTraceEx** function.

### `FilterData` [in, optional]

The provider-defined data. This parameter is optional. The provider determines the layout of the data and its purpose. For example, the provider can use this data to additionally filter the events that it writes or use it to perform some calculations before writing the events. For detailed information, see [Event Filter Descriptor](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_filter_descriptor).

### `CallbackContext` [in, out, optional]

The context of the callback function that is defined when the provider called [EtwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwregister) to register itself. This parameter is optional.

## Remarks

Use the EtwRegister function to specify a pointer to the **EtwEnableCallback** function.

Use the *FilterData* parameter of the callback function to supply the provider with sophisticated filtering abilities. The **EtwEnableCallback** function does not replace the enable-status function calls (**EtwEventEnabled** and **EtwProviderEnabled**). However, it serves as a supplement to them. However, unless your level and keywords are currently enabled, the event will not be written, regardless of the *FilterData* that the callback function provides.

Callers of **EtwEnableCallback** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[EnableTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletrace)

[EnableTraceEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex)

[EtwEventEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etweventenabled)

[EtwProviderEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwproviderenabled)

[EtwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwregister)

[Event Filter Descriptor](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_filter_descriptor)