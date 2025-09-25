## Description

Identifies the type of DXGI adapter.

## Constants

### `DXGI_ADAPTER_FLAG3_NONE:0`

Specifies no flags.

### `DXGI_ADAPTER_FLAG3_REMOTE:1`

Value always set to 0. This flag is reserved.

### `DXGI_ADAPTER_FLAG3_SOFTWARE:2`

Specifies a software adapter. For more info about this flag, see [new info in Windows 8 about enumerating adapters](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-programming-guide-dxgi).

**Direct3D 11:** This enumeration value is supported starting with Windows 8.

### `DXGI_ADAPTER_FLAG3_ACG_COMPATIBLE:4`

Specifies that the adapter's driver has been confirmed to work in an OS process where Arbitrary Code Guard (ACG) is enabled (i.e. dynamic code generation is disallowed).

### `DXGI_ADAPTER_FLAG3_SUPPORT_MONITORED_FENCES:8`

Specifies that the adapter supports monitored fences. These adapters support the [ID3D12Device::CreateFence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device) and [ID3D11Device5::CreateFence](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11device5) functions.

### `DXGI_ADAPTER_FLAG3_SUPPORT_NON_MONITORED_FENCES:0x10`

Specifies that the adapter supports non-monitored fences. These adapters support the [ID3D12Device::CreateFence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device) function together with the [D3D12_FENCE_FLAG_NON_MONITORED](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_fence_flags) flag.

**Note** For adapters that support both monitored and non-monitored fences, non-monitored fences are only supported when created with the [D3D12_FENCE_FLAG_SHARED](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_fence_flags) and **D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER** flags. Monitored fences should always be used by supporting adapters unless communicating with an adapter that only supports non-monitored fences.

### `DXGI_ADAPTER_FLAG3_KEYED_MUTEX_CONFORMANCE:0x20`

Specifies that the adapter claims keyed mutex conformance. This signals a stronger guarantee that the [IDXGIKeyedMutex](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgikeyedmutex) interface behaves correctly.

### `DXGI_ADAPTER_FLAG3_FORCE_DWORD:0xffffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The **DXGI_ADAPTER_FLAG3** enumerated type is used by the **Flags** member of the [DXGI_ADAPTER_DESC3](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/ns-dxgi1_6-dxgi_adapter_desc3) structure to ientify the type of DXGI adapter.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)