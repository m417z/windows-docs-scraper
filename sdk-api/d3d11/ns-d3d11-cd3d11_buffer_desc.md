# CD3D11_BUFFER_DESC structure

## Description

Represents a buffer and provides convenience methods for creating buffers.

## Members

### `CD3D11_BUFFER_DESC`

TBD

### `~CD3D11_BUFFER_DESC`

TBD

### `operator` const D3D11_BUFFER_DESC&

TBD

### `D3D11_BUFFER_DESC`

##### - See Below.

## Remarks

Here is how D3D11.h defines **CD3D11_BUFFER_DESC**:

```

struct CD3D11_BUFFER_DESC : public D3D11_BUFFER_DESC
{
    CD3D11_BUFFER_DESC()
    {}
    explicit CD3D11_BUFFER_DESC( const D3D11_BUFFER_DESC& o ) :
        D3D11_BUFFER_DESC( o )
    {}
    explicit CD3D11_BUFFER_DESC(
        UINT byteWidth,
        UINT bindFlags,
        D3D11_USAGE usage = D3D11_USAGE_DEFAULT,
        UINT cpuaccessFlags = 0,
        UINT miscFlags = 0,
        UINT structureByteStride = 0 )
    {
        ByteWidth = byteWidth;
        Usage = usage;
        BindFlags = bindFlags;
        CPUAccessFlags = cpuaccessFlags ;
        MiscFlags = miscFlags;
        StructureByteStride = structureByteStride;
    }
    ~CD3D11_BUFFER_DESC() {}
    operator const D3D11_BUFFER_DESC&() const { return *this; }
};

```

## See also

[CD3D11 Helper Structures](https://learn.microsoft.com/windows/desktop/direct3d11/cd3d11-helper-classes)