# IDDCX_ADAPTER_CAPS structure

## Description

The **IDDCX_ADAPTER_CAPS** structure provides information about the capabilities of the adapter.

## Members

### `Size`

Size, in bytes, of the structure.

### `Flags`

An [**IDDCX_ADAPTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags) value specifying the adapter flags used by the driver.

### `MaxDisplayPipelineRate`

Value that represents the total display bandwidth for the adapter. Each mode the driver reports to the OS also has a display pipeline rate associated with it and the OS ensures that the combined display pipeline rate of all the active modes will never exceed this value. The driver decides how many units it uses.

Some hardware have resource dependencies that allow them to support all modes in all configurations. For example, an adapter might be able to individually support a 4k mode on each of its two outputs but not 4k on each of the outputs at the same time. If driver does not have these restrictions then it can set all bandwidths to zero.

### `MaxMonitorsSupported`

The maximum number of monitors that can be connected at the same time.

### `EndPointDiagnostics`

An [**IDDCX_ENDPOINT_DIAGNOSTIC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_endpoint_diagnostic_info) structure containing endpoint diagnostics information. This information is used for telemetry; it is not used for runtime OS decisions.

### `StaticDesktopReencodeFrameCount`

The number of frames to request after the desktop goes idle if the driver's encoder requires multiple frames to continue improving quality.

## Remarks

**IDDCX_ADAPTER_CAPS** is a member of the [**IDARG_IN_ADAPTER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapter_init) structure that is used to create a WDDM graphics adapter.

## See also

[**IDARG_IN_ADAPTER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapter_init)

[**IDDCX_ADAPTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags)

[**IDDCX_ENDPOINT_DIAGNOSTIC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_endpoint_diagnostic_info)

[**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync)