# D3DXVECTOR4\_16F structure

> [!Note]
> The D3DX10 utility library is deprecated. We recommend that you use [DirectXMath](https://learn.microsoft.com/windows/win32/dxmath/pg-xnamath-migration-d3dx) instead.

Same as a [**D3DXVECTOR4**](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-d3dxvector4), but it uses 16-bit floating point values for x, y, and z.

## Members

**x**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The x-component.

**y**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The y-component.

**z**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The z-component.

**w**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The w-component.

## Remarks

**D3DXVECTOR4\_16F** has the following C++ extensions.

### D3DXVECTOR4\_16F Extensions

```
typedef struct D3DXVECTOR4_16F
{
#ifdef __cplusplus
public:
    D3DXVECTOR4_16F() {};
    D3DXVECTOR4_16F( CONST FLOAT * );
    D3DXVECTOR4_16F( CONST D3DXFLOAT16 * );
    D3DXVECTOR4_16F( CONST D3DXVECTOR3_16F& xyz, CONST D3DXFLOAT16& w );
    D3DXVECTOR4_16F( CONST D3DXFLOAT16& x, CONST D3DXFLOAT16& y, CONST D3DXFLOAT16& z, CONST D3DXFLOAT16& w );

    // casting
    operator D3DXFLOAT16* ();
    operator CONST D3DXFLOAT16* () const;

    // binary operators
    BOOL operator == ( CONST D3DXVECTOR4_16F& ) const;
    BOOL operator != ( CONST D3DXVECTOR4_16F& ) const;

public:
#endif //__cplusplus
    D3DXFLOAT16 x, y, z, w;

} D3DXVECTOR4_16F, *LPD3DXVECTOR4_16F;
```

## Requirements

| Requirement | Value |
|-------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Math.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

