# D3D12_STATE_OBJECT_CONFIG structure

## Description

Defines general properties of a state object.

## Members

### `Flags`

A value from the [D3D12_STATE_OBJECT_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_state_object_flags) flags enumeration that specifies the requirements for the state object.

## Remarks

The presence of this subobject in a state object is optional. If present, all exports in the state object must be associated with the same subobject (or one with a matching definition). This consistency requirement does not apply across existing collections that are included in a larger state object.