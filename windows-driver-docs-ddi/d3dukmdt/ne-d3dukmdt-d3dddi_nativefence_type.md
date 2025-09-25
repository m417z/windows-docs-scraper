## Description

A **D3DDDI_NATIVEFENCE_TYPE** enumeration value specifies the type of native fence that the OS.

## Constants

### `D3DDDI_NATIVEFENCE_TYPE_DEFAULT:0`

Indicates full CPU and GPU interoperability. See [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects) for details. Supported starting in Windows 11, version 22H2 (WDDM 3.2).

### `D3DDDI_NATIVEFENCE_TYPE_INTRA_GPU:1`

Special fence type for engine-to-engine synchronization that doesn't support any CPU access or CPU wait/signal operations. See [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects) for details. Not currently supported.

## Remarks

A **D3DDDI_NATIVEFENCE_TYPE** enumeration value dictates the type of native fence that the OS creates. They differ in functionality, performance characteristics, and storage requirements for **CurrentValue** and **MonitoredValue**.

For detailed information about these differences and about native GPU fences in general, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**D3DDDI_NATIVEFENCEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_nativefenceinfo)

[**D3DKMTCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatenativefence)