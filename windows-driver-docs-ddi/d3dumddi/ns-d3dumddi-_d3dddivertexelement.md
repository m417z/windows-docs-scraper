# _D3DDDIVERTEXELEMENT structure

## Description

The D3DDDIVERTEXELEMENT structure describes an element in the array for a vertex shader declaration.

## Members

### `Stream` [in]

The number of the stream.

### `Offset` [in]

The offset (if any), in bytes, from the beginning of the stream to the start of the data.

### `Type` [in]

One of several predefined data types that define the data size. For more information about these types, see the D3DDECLTYPE enumeration type in the Microsoft Windows SDK documentation.

### `Method` [in]

The tessellator processing method. This method determines how the tessellator interprets and operates on the vertex data. For more information about these methods, see the D3DDECLMETHOD enumeration type in the Windows SDK documentation.

### `Usage` [in]

The intended use of the vertex data. For more information about the possible uses, see the D3DDECLUSAGE enumeration type in the Windows SDK documentation.

### `UsageIndex` [in]

A modification to the usage data that is specified in the **Usage** member. This modification enables multiple usage types to be specified.

## See also

[CreateVertexShaderDecl](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createvertexshaderdecl)