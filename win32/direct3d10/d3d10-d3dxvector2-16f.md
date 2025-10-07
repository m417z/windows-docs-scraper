# D3DXVECTOR2\_16F structure

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Describes a two-component vector including operator overloads and type casts. Same as a [**D3DXVECTOR2**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector2), but it uses 16-bit floating point values for x, y, and z.

## Members

**x**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The x-component.

**y**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The y-component.

## Remarks

**D3DXVECTOR2\_16F** has the following C++ extensions.

### D3DXVECTOR2\_16F Extensions

```

typedef struct D3DXVECTOR2_16F
{
#ifdef __cplusplus
public:
    D3DXVECTOR2_16F() {};
    D3DXVECTOR2_16F( CONST FLOAT * );
    D3DXVECTOR2_16F( CONST D3DXFLOAT16 * );
    D3DXVECTOR2_16F( CONST D3DXFLOAT16 &x, CONST D3DXFLOAT16 &y );

    // casting
    operator D3DXFLOAT16* ();
    operator CONST D3DXFLOAT16* () const;

    // binary operators
    BOOL operator == ( CONST D3DXVECTOR2_16F& ) const;
    BOOL operator != ( CONST D3DXVECTOR2_16F& ) const;

public:
#endif //__cplusplus
    D3DXFLOAT16 x, y;

} D3DXVECTOR2_16F, *LPD3DXVECTOR2_16F;
```

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

