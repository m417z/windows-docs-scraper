## Description

The **DXGKARG_COLLECTDBGINFO** structure describes information for a debug report when [**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2) is called.

## Members

### `Reason`

[in] The [bug-check code](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2) for which to return debug information in the buffer that **pBuffer** points to. These are possible values:

| Value | Meaning |
| ----- | ------- |
| **VIDEO_TDR_TIMEOUT_DETECTED** 0x117|A [**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine) operation has reset a logical adapter. |
| **VIDEO_ENGINE_TIMEOUT_DETECTED** 0x141|A [**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine) operation has reset one or more nodes within a physical adapter. Available starting in Windows 8. |

### `pBuffer`

[out] A pointer to a buffer that receives the debug information for the reason that **Reason** specifies.

### `BufferSize`

The maximum size, in bytes, to copy to the buffer that **pBuffer** points to.

### `pExtension`

A pointer to an OS-allocated [**DXGKARG_COLLECTDBGINFO_EXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo_ext) structure that the driver optionally populates with debug extension information.

### `TdrType`

[in] A [**DXGK_TDR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_tdr_type) value that specifies the type of TDR that occurred.

### `TdrPayloadSize`

[in] The size, in bytes, of the TDR payload that **TdrPayload** points to.

### `TdrPayload`

[in] A pointer to a buffer that contains the payload specific to certain **TdrType** values, as indicated the following table. This buffer can be NULL.

| TdrType | Associated structure |
| ------- | -------------------- |
| DXGK_TDR_TYPE_ENGINE_TIMEOUT | **TdrPayload** points to a [**DXGK_TDR_PAYLOAD_ENGINE_TIMEOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_tdr_payload_engine_timeout) structure. |
| DXGK_TDR_TYPE_VSYNC_TIMEOUT | **TdrPayload** points to a [**DXGK_TDR_PAYLOAD_VSYNC_TIMEOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_tdr_payload_vsync_timeout) structure. |

## Remarks

The layout of **DXGKARG_COLLECTDBGINFO2** is backwards compatible with [**DXGKARG_COLLECTDBGINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo) to allow the [**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2) implementation to re-use existing [**DxgkDdiCollectDbgInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo) helpers as needed. For this reason, the **Reason**, **pBuffer**, **BufferSize**, and **pExtension** fields have the same semantics.

For some TDR types (specified in **TdrType**), the OS provides additional information in the **TdrPayload** buffer of **TdrPayloadSize** bytes. It can be NULL, and the driver is expected to handle this case without crashing.

When the payload isn't NULL, it can be cast to a structure that corresponds to the TDR type. The OS might grow these structures in a backwards compatible manner, adding new fields at the end. The driver must check **TdrPayloadSize** prior to accessing **TdrPayload** fields to make sure the OS implements the desired payload version or later.

Memory that **TdrPayload** points to is only valid for the duration of the [**DxgkddiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2) call. The driver shouldn't store a pointer to **TdrPayload** past the end of **DxgkddiCollectDbgInfo2** call.

For more information, see [TDR debuggability improvements](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-debuggability-improvements).

## See also

[**DXGK_TDR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_tdr_type)

[**DxgkDdiCollectDbgInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo)

[**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2)