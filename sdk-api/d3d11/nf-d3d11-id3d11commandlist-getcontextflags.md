# ID3D11CommandList::GetContextFlags

## Description

Gets the initialization flags associated with the deferred context that created the command list.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The context flag is reserved for future use and is always 0.

## Remarks

The GetContextFlags method gets the flags that were supplied to the *ContextFlags* parameter of [ID3D11Device::CreateDeferredContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createdeferredcontext); however, the context flag is reserved for future use.

## See also

[ID3D11CommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11commandlist)