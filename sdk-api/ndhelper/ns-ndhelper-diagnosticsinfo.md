# DiagnosticsInfo structure

## Description

The **DiagnosticsInfo** structure contains the estimate of diagnosis time, and flags for invocation.

## Members

### `cost`

Type: **long**

The length of time, in seconds, that the diagnosis should take to complete. A value of zero or a negative value means the cost is negligible. Any positive value will cause the engine to adjust the overall diagnostics process.

### `flags`

Type: **ULONG**

Reserved.