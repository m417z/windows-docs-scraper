# CD3D11_BLEND_DESC structure

## Description

Represents a blend-state structure and provides convenience methods for creating blend-state structures.

## Members

### `CD3D11_BLEND_DESC`

TBD

### `~CD3D11_BLEND_DESC`

TBD

### `operator` const D3D11_BLEND_DESC&

TBD

### `D3D11_BLEND_DESC`

##### - See Below.

## Remarks

Here is how D3D11.h defines **CD3D11_BLEND_DESC**:

```

struct CD3D11_BLEND_DESC : public D3D11_BLEND_DESC
{
    CD3D11_BLEND_DESC()
    {}
    explicit CD3D11_BLEND_DESC( const D3D11_BLEND_DESC& o ) :
        D3D11_BLEND_DESC( o )
    {}
    explicit CD3D11_BLEND_DESC( CD3D11_DEFAULT )
    {
        AlphaToCoverageEnable = FALSE;
        IndependentBlendEnable = FALSE;
        const D3D11_RENDER_TARGET_BLEND_DESC defaultRenderTargetBlendDesc =
        {
            FALSE,
            D3D11_BLEND_ONE, D3D11_BLEND_ZERO, D3D11_BLEND_OP_ADD,
            D3D11_BLEND_ONE, D3D11_BLEND_ZERO, D3D11_BLEND_OP_ADD,
            D3D11_COLOR_WRITE_ENABLE_ALL,
        };
        for (UINT i = 0; i < D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT; ++i)
            RenderTarget[ i ] = defaultRenderTargetBlendDesc;
    }
    ~CD3D11_BLEND_DESC() {}
    operator const D3D11_BLEND_DESC&() const { return *this; }
};

```

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)