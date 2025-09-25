# __MIDL___MIDL_itf_wdtf_0000_0001_0001 enumeration

## Description

The **TTraceLevel** enumeration defines a set of levels for tracing in WDTF. The meaning on each level depends on registry settings for the [ITracer](https://learn.microsoft.com/windows-hardware/drivers/ddi/) interface.

## Constants

### `Trace0_Off`

Tracing is off.

### `Trace1_Low`

The tracing level is low. Generally, only the top layer of traces and failure and warning information is traced.

### `Trace2_Medium`

The tracing level is medium. This level is the default level. It includes all of the traces in **Trace1_Low** plus standard traces at all layers of WDTF.

### `Trace3_High`

The tracing level is high. This level includes all of the traces in **Trace2_Medium** plus noisy traces at all layers of WDTF.

### `Trace4_All`

All tracing is enabled. Currently, this tracing level is the same as **Trace3_High**.

### `Trace5_Custom`

A custom trace level. Currently, this value is set to **Trace0_Off**.

### `Trace6_Custom`

A custom trace level. Currently, this value is set to **Trace0_Off**.

### `Trace7_Custom`

A custom trace level. Currently, this value is set to **Trace0_Off**.

### `Trace8_Custom`

A custom trace level. Currently, this value is set to **Trace0_Off**.

### `Trace_Default`

The default tracing level. This level tells the [ITracer](https://learn.microsoft.com/windows-hardware/drivers/ddi/) interface to look for the actual level in the registry. **ITracer** will look in the TraceLevel path for the implementation that you called the [ITracing::SetTraceLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/) method on. For most implementations, this value is set to **Trace2_Medium** when you install WDTF.

## Remarks

Use the [ITracing::SetTraceLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/) method to change the trace level of an instance of a WDTF interface at runtime. For more information about how to change the registry default values, see [ITracer](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[ITracer](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ITracing](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ITracing::SetTraceLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/)