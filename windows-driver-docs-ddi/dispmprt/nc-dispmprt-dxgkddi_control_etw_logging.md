# DXGKDDI_CONTROL_ETW_LOGGING callback function

## Description

The *DxgkDdiControlEtwLogging* function enables or disables Event Tracing for Windows (ETW) event logging.

## Parameters

### `Enable` [in]

A Boolean value that indicates whether *DxgkDdiControlEtwLogging* enables or disables ETW event logging. **TRUE** indicates that it enables and **FALSE** indicates that it disables.

### `Flags` [in]

A valid bitwise OR of values. Currently, no flags are defined.

### `Level` [in]

A value that indicates the level of event logging.