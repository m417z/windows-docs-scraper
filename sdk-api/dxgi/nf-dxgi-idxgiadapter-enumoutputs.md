# IDXGIAdapter::EnumOutputs

## Description

Enumerate adapter (video card) outputs.

## Parameters

### `Output`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the output.

### `ppOutput` [out]

Type: **[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)****

The address of a pointer to an [IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput) interface at the position specified by the *Output* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

A code that indicates success or failure (see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error)). DXGI_ERROR_NOT_FOUND is returned if the index is greater than the number of outputs.

If the adapter came from a device created using D3D_DRIVER_TYPE_WARP, then the adapter has no outputs, so DXGI_ERROR_NOT_FOUND is returned.

## Remarks

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

When the **EnumOutputs** method succeeds and fills the *ppOutput* parameter with the address of the pointer to the output interface, **EnumOutputs** increments the output interface's reference count. To avoid a memory leak, when you finish using the
output interface, call the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to decrement the reference count.

**EnumOutputs** first returns the output on which the desktop primary is displayed. This output corresponds with an index of zero. **EnumOutputs** then returns other outputs.

#### Examples

Enumerating Outputs

Here is an example of how to use **EnumOutputs** to enumerate all the outputs on an adapter:

```

UINT i = 0;
IDXGIOutput * pOutput;
std::vector<IDXGIOutput*> vOutputs;
while(pAdapter->EnumOutputs(i, &pOutput) != DXGI_ERROR_NOT_FOUND)
{
    vOutputs.push_back(pOutput);
    ++i;
}

```

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)