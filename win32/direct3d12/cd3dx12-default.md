# CD3DX12\_DEFAULT structure

Passes D3D12\_DEFAULT into a constructor for each helper structure. This structure is simply used as a mechanism to set default parameters on the other helper structures.

## Remarks

This struct is declared as follows:

``` syntax
struct CD3DX12_DEFAULT {};
extern const DECLSPEC_SELECTANY CD3DX12_DEFAULT D3D12_DEFAULT;
```

Passes D3D12\_DEFAULT into a constructor for each helper struct. For example, the following constructor is declared in d3dx12.h:

CD3DX12\_CPU\_DESCRIPTOR\_HANDLE(CD3DX12\_DEFAULT) { ptr = 0; }

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

