# LPD3DHAL_VALIDATETEXTURESTAGESTATECB callback function

## Description

The **D3dValidateTextureStageState** function returns the number of passes where the hardware can perform the blending operations specified in the current state.

## Parameters

### `unnamedParam1`

*pvtssd* [in]

Points to a [D3DHAL_VALIDATETEXTURESTAGESTATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_validatetexturestagestatedata) structure that contains the information required for the driver to determine and return the number of passes required to perform the blending operations.

## Return value

**D3dValidateTextureStageState** returns one of the following callback codes:

## Remarks

Microsoft Direct3D drivers that support texturing must implement **D3dValidateTextureStageState**.

The driver's implementation of this function must evaluate the current texture state for all texture stages associated with the context. If the driver's hardware can perform the specified blending operations, then the driver should return the number of passes on the state data that its hardware requires. If the hardware cannot perform the specified blending operations, then the driver should return one of the following error codes in the **ddrval** member of the D3DHAL_VALIDATETEXTURESTAGESTATEDATA structure at **pvtssd**:

|Error Code|Meaning|
|--- |--- |
|D3DERR_CONFLICTINGTEXTUREFILTER|The hardware cannot do both trilinear filtering and multitexturing at the same time.|
|D3DERR_TOOMANYOPERATIONS|The hardware cannot handle the specified number of operations.|
|D3DERR_UNSUPPORTEDALPHAARG|The hardware does not support a specified alpha argument.|
|D3DERR_UNSUPPORTEDALPHAOPERATION|The hardware does not support a specified alpha operation.|
|D3DERR_UNSUPPORTEDCOLORARG|The hardware does not support a specified color argument.|
|D3DERR_UNSUPPORTEDCOLOROPERATION|The hardware does not support a specified color operation.|
|D3DERR_UNSUPPORTEDFACTORVALUE|The hardware does not support a D3DTA_TFACTOR greater than 1.0.|
|D3DERR_WRONGTEXTUREFORMAT|The hardware does not support the current state in the selected texture format.|

Direct3D calls **D3dValidateTextureStageState** in response to an application request through a call to **IDirect3DDevice7::ValidateDevice**. The number of passes returned by the driver is propagated back to the application, which can then decide whether it will proceed with rendering using the current state or if it must change the blending operations to render faster or to render at all. There are no limits to the number of passes that a driver can return.

A driver that returns more than one pass is responsible for properly executing the passes on all state and primitive data when rendering.

Requests that are likely to fail **D3dValidateTextureStageState**:

* Using diffuse iterated values as ARGs, or the BLENDDIFFUSE operation is sparsely supported on current hardware. Many parts can introduce only iterated color data at the last texture operation stage.

* Trying to specify the texture for each stage as its arg1 in preference to arg2.

* Attempting to use diffuse or scalar values at arbitrary multitexture blending stages. For many cards, these values can be used only at the final texture blending state; for others, only at the first stage.

* Attempting to do more in the first texture than merely replicate alpha to color channels or invert the input. For many cards, the blending units associated with the first texture are incapable of handling operations more complex than these. The samples below try to use only the second texture's blending unit, if it is possible to do so. The first unit is presumed to be in its default state in the samples.

```cpp
     dev.SetTextureStageState( n, D3DTSS_COLORARG1, D3DTA_TEXTURE );   *
     dev.SetTextureStageState( n, D3DTSS_COLOROP, D3DTOP_SELECTARG1 ); *
     ```

* Performing operations for the output alpha that are more intricate than, or substantially different from, the operations specified for the color channels is less likely to be supported.

* Attempting to use D3DTA_TFACTOR and D3DTA_DIFFUSE simultaneously. Some hardware does not support this.

* Attempting the simultaneous use of multiple textures and MIP mapped trilinear filtering. Many cards do not support these operations at the same time. If trilinear filtering has been requested for a texture involved in multitexture operations and it fails validation, turn off trilinear and try again. In this case, it may be best to do multipass rendering instead.

## See also

[D3DHAL_VALIDATETEXTURESTAGESTATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_validatetexturestagestatedata)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)