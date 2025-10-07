# D3DX10\_ERR enumeration

Errors are represented by negative values and cannot be combined. The following is a list of values that can be returned by methods included with the D3DX utility library. See the individual method descriptions for lists of the values that each can return. These lists are not necessarily comprehensive.

## Constants

**D3DX10\_ERR\_CANNOT\_MODIFY\_INDEX\_BUFFER**

The index buffer cannot be modified.

**D3DX10\_ERR\_INVALID\_MESH**

The mesh is invalid.

**D3DX10\_ERR\_CANNOT\_ATTR\_SORT**

Attribute sort (D3DXMESHOPT\_ATTRSORT) is not supported as an optimization technique.

**D3DX10\_ERR\_SKINNING\_NOT\_SUPPORTED**

Skinning is not supported.

**D3DX10\_ERR\_TOO\_MANY\_INFLUENCES**

Too many influences specified.

**D3DX10\_ERR\_INVALID\_DATA**

The data is invalid.

**D3DX10\_ERR\_LOADED\_MESH\_HAS\_NO\_DATA**

The mesh has no data.

**D3DX10\_ERR\_DUPLICATE\_NAMED\_FRAGMENT**

A fragment with that name already exists.

**D3DX10\_ERR\_CANNOT\_REMOVE\_LAST\_ITEM**

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
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-enums)

