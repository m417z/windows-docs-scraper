# D3DXERR enumeration

Errors are represented by negative values and cannot be combined. The following is a list of values that can be returned by methods included with the D3DX utility library. See the individual method descriptions for lists of the values that each can return. These lists are not necessarily comprehensive.

## Constants

**D3DXERR\_CANNOTMODIFYINDEXBUFFER**

The index buffer cannot be modified.

**D3DXERR\_INVALIDMESH**

The mesh is invalid.

**D3DXERR\_CANNOTATTRSORT**

Attribute sort (D3DXMESHOPT\_ATTRSORT) is not supported as an optimization technique.

**D3DXERR\_SKINNINGNOTSUPPORTED**

Skinning is not supported.

**D3DXERR\_TOOMANYINFLUENCES**

Too many influences specified.

**D3DXERR\_INVALIDDATA**

The data is invalid.

**D3DXERR\_LOADEDMESHASNODATA**

The mesh has no data.

**D3DXERR\_DUPLICATENAMEDFRAGMENT**

A fragment with that name already exists.

**D3DXERR\_CANNOTREMOVELASTITEM**

The last item cannot be deleted.

## Remarks

The facility code \_FACDD is used to generate error codes, as in the following macros.

```
#define _FACDD                  0x876
#define MAKE_DDHRESULT( code )  MAKE_HRESULT( 1, _FACDD, code )
enum _D3DXERR {
    D3DXERR_CANNOTMODIFYINDEXBUFFER = MAKE_DDHRESULT(2900),
    D3DXERR_INVALIDMESH             = MAKE_DDHRESULT(2901),
    ...
    };
```

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------|
| Header<br> | D3dx9.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

