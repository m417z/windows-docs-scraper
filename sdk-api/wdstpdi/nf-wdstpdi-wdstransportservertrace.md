# WdsTransportServerTrace function

## Description

Sends a debugging message.

## Parameters

### `hProvider` [in]

Handle to the provider. This handle was given to the provider in the [WdsTransportProviderInitialize](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportproviderinitialize) function.

### `Severity` [in]

Severity level of the message.

#### WDS_MC_TRACE_VERBOSE (0x00010000)

#### WDS_MC_TRACE_INFO (0x00020000)

#### WDS_MC_TRACE_WARNING (0x00040000)

#### WDS_MC_TRACE_ERROR (0x00080000)

#### WDS_MC_TRACE_FATAL (0x00010000)

### `pwszFormat` [in]

A pointer to a null-terminated string value that contains a formatted string.

### `...`

Additional arguments.

## Return value

If the function succeeds, the return is **S_OK**.