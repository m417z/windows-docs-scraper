## Description

**IDARG_OUT_RELEASEANDACQUIRESYSTEMBUFFER** contains the information resulting from a buffer release and acquire operation.

## Members

### `pMetaData` [out]

Pointer to a [**IDDCX_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata) structure containing per-frame metadata and frame information.

### `pBufferInfo` [out]

Pointer to a [**IDDCX_SYSTEM_BUFFER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_system_buffer_info) structure containing a buffer's surface information.

## Remarks

An indirect display driver (IDD) passes a pointer to a **IDARG_OUT_RELEASEANDACQUIRESYSTEMBUFFER** when it calls [**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquiresystembuffer).

> [!NOTE]
> The IDARG_OUT_RELEASEANDACQUIRESYSTEMBUFFER structure contains pointers to two other structures that should be set by the driver as in the following example code:

```
IDDCX_METADATA MetaData = {};
IDDCX_SYSTEM_BUFFER_INFO SystemBufferInfo = {};
IDARG_OUT_RELEASEANDACQUIRESYSTEMBUFFER system_Buffer = { &MetaData, &SystemBufferInfo };
HRESULT hr = IddCxSwapChainReleaseAndAcquireSystemBuffer(m_hSwapChain, &system_Buffer);
```

## See also

[**IDDCX_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata)

[**IDDCX_SYSTEM_BUFFER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_system_buffer_info)

[**IddCxSwapChainReleaseAndAcquireSystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquiresystembuffer)