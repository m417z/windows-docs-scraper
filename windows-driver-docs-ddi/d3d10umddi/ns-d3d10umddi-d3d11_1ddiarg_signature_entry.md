# D3D11_1DDIARG_SIGNATURE_ENTRY structure

## Description

Describes an entry for a signature.

## Members

### `SystemValue` [in]

The **D3D10_SB_NAME**-typed value that indicates the system name of the signature entry. The **D3D10_SB_NAME** enumeration is defined in the D3d10tokenizedprogramformat.hpp header file. One of the following values can be set.

|Value|System name|
|--- |--- |
|D3D10_SB_NAME_UNDEFINED (0)|The entry does not have a system name.|
|D3D10_SB_NAME_POSITION (1)|Position.|
|D3D10_SB_NAME_CLIP_DISTANCE (2)|Clip distance.|
|D3D10_SB_NAME_CULL_DISTANCE (3)|Cull distance.|
|D3D10_SB_NAME_RENDER_TARGET_ARRAY_INDEX (4)|Render target array index.|
|D3D10_SB_NAME_VIEWPORT_ARRAY_INDEX (5)|Viewport array index.|
|D3D10_SB_NAME_VERTEX_ID (6)|Vertex ID.|
|D3D10_SB_NAME_PRIMITIVE_ID (7)|Primitive ID.|
|D3D10_SB_NAME_INSTANCE_ID (8)|Instance ID.|
|D3D10_SB_NAME_IS_FRONT_FACE (9)|Is front face.|

### `Register` [in]

The number of the register for the signature entry.

### `Mask` [in]

The xyzw mask for the signature entry. The four least significant bits (LSBs) of the mask represent xyzw respectively.

### `RegisterComponentType`

A **D3D10_SB_REGISTER_COMPONENT_TYPE** type that indicates the register component type.

The **D3D10_SB_REGISTER_COMPONENT_TYPE** enumeration is defined in the D3d10tokenizedprogramformat.hpp header file.

### `MinPrecision`

A **D3D11_SB_OPERAND_MIN_PRECISION** type that indicates a minimum precision of source and destination operands.

The **D3D11_SB_OPERAND_MIN_PRECISION** enumeration is defined in the D3d10tokenizedprogramformat.hpp header file.