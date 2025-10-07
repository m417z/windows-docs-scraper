# CommandListCast function

This function template casts a constant pointer to any command list into a const pointer to an ID3D12CommandList.

This cast is useful for passing strongly-typed command list pointers into [**ExecuteCommandLists**](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-executecommandlists).

## Parameters

*pp*

Type: **t\_CommandListType \* const \***

The strongly-typed command list to cast.

The template argument **t\_CommandListType** specifies any strongly-typed command list object.

## Return value

Type: **ID3D12CommandList \* const \***

The strongly-typed command list, reinterpreted as an [**ID3D12CommandList**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandlist).

## Remarks

CommandListCast performs a **reinterpret\_cast**. The cast is valid as long as the const-ness of the command list is respected.

The CommandListCast function is defined as the following:

```C++
template <typename t_CommandListType>
inline ID3D12CommandList * const * CommandListCast(t_CommandListType * const * pp)
{
    return reinterpret_cast<ID3D12CommandList * const *>(pp);
}

```

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |
| Library<br> | D3D12.lib |
| DLL<br> | D3D12.dll |

## See also

[Helper Functions for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-functions-for-d3d12)

