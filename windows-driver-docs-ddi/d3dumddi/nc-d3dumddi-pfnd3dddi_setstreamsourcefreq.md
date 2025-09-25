# PFND3DDDI_SETSTREAMSOURCEFREQ callback function

## Description

The *SetStreamSourceFreq* function sets the frequency divisor of a stream source that is bound to a vertex buffer.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETSTREAMSOURCEFREQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setstreamsourcefreq) structure that specifies how the frequency divisor for the stream source is set.

## Return value

*SetStreamSourceFreq* returns S_OK or an appropriate error result if the frequency divisor for the portion of the vertex stream source is not successfully set.

## Remarks

A user-mode display driver for a device that supports vertex shader version 3.0 and later must implement vertex stream frequency division. For version 2.0 and earlier models of vertex shader (including fixed function), the vertex shader is called once for each vertex. For each call, the input vertex registers are initialized with unique vertex elements from the vertex streams. However, if the driver uses vertex stream frequency division, the vertex shader (3.0 and later) can be called to initialize applicable input registers at a less frequent rate.

After the stream's frequency divisor is set--for example, to 2--the driver must fetch data from the stream and pass this data into applicable input vertex registers every 2 vertices. This divisor affects each element in the stream.

The driver uses the frequency divisor to compute the vertex offset into the vertex buffer according to the following formula:

```cpp
VertexOffset = ((VertexIndex / Divider) * StreamStride) + StreamOffset
```

For each vertex stream that is used, if the driver receives a start-vertex value during a call to the driver's [DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive) function, the driver also divides this start-vertex value by the frequency divisor and factors the result in the formula. This start-vertex value is provided in the **VStart** member of the [D3DDDIARG_DRAWPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive) structure. The following formula includes the start-vertex value:

```cpp
VertexOffset = (StartVertex / Divider) +
       ((VertexIndex / Divider) * StreamStride) + StreamOffset
```

Note that the preceding formulas use integer division.

The driver ignores the setting of a stream's frequency divisor either for indexed primitives or if the driver supports only a vertex shader model that is earlier than version 3.0 (including fixed function).

## See also

[D3DDDIARG_DRAWPRIMITIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_drawprimitive)

[D3DDDIARG_SETSTREAMSOURCEFREQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setstreamsourcefreq)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[DrawPrimitive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_drawprimitive)