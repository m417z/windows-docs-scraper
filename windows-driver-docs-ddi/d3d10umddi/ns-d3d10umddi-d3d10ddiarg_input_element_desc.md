# D3D10DDIARG_INPUT_ELEMENT_DESC structure

## Description

The D3D10DDIARG_INPUT_ELEMENT_DESC structure describes an element of a layout.

## Members

### `InputSlot` [in]

The number of the input slot for the element.

### `AlignedByteOffset` [in]

The aligned offset, in bytes, for the element.

### `Format` [in]

A DXGI_FORMAT-typed value that indicates the format of the element.

### `InputSlotClass` [in]

A value that specifies the type of element. This member must be set to one of the following values from the D3D10_DDI_INPUT_CLASSIFICATION enumeration.

|Value|Meaning|
|--- |--- |
|D3D10_DDI_INPUT_PER_VERTEX_DATA (0)|The InstanceDataStepRate member holds the number of instances to render.|
|D3D10_DDI_INPUT_PER_INSTANCE_DATA (1)|InstanceDataStepRate is set to zero.|

### `InstanceDataStepRate` [in]

The number of instances to render before incrementing to the next data element, if the **InputSlotClass** member is set to D3D10_DDI_INPUT_PER_INSTANCE_DATA. **InstanceDataStepRate** is set to zero if **InputSlotClass** is set to D3D10_DDI_INPUT_PER_VERTEX_DATA.

### `InputRegister` [in]

The number of the input register for the element.

## See also

[D3D10DDIARG_CREATEELEMENTLAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createelementlayout)