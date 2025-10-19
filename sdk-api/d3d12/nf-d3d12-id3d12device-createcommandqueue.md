## Description

Creates a command queue.

Also see [ID3D12Device9::CreateCommandQueue1](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device9-createcommandqueue1).

## Parameters

### `pDesc`

Type: [in] **const [D3D12_COMMAND_QUEUE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_command_queue_desc)***

Specifies a **D3D12_COMMAND_QUEUE_DESC** that describes the command queue.

### `riid`

Type: **REFIID**

The globally unique identifier (GUID) for the command queue interface. See **Remarks**. An input parameter.

### `ppCommandQueue`

Type: [out] **void****

A pointer to a memory block that receives a pointer to the [ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue) interface for the command queue.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **E_OUTOFMEMORY** if there is insufficient memory to create the command queue. See [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

The **REFIID**, or **GUID**, of the interface to the command queue can be obtained by using the __uuidof() macro. For example, __uuidof(ID3D12CommandQueue) will get the **GUID** of the interface to a command queue.

## Examples

The [D3D12HelloTriangle](https://learn.microsoft.com/windows/win32/direct3d12/working-samples) sample uses **ID3D12Device::CreateCommandQueue** as follows:

```cpp
D3D12_COMMAND_QUEUE_DESC queueDesc{};
queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

ThrowIfFailed(m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue)));
```

Refer to the [Example code in the D3D12 reference](https://learn.microsoft.com/windows/win32/direct3d12/notes-on-example-code).

## See also

* [ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)
* [ID3D12Device9::CreateCommandQueue1](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device9-createcommandqueue1)