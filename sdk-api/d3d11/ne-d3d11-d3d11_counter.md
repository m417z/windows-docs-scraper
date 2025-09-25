# D3D11_COUNTER enumeration

## Description

Options for performance counters.

## Constants

### `D3D11_COUNTER_DEVICE_DEPENDENT_0:0x40000000`

Define a performance counter that is dependent on the hardware device.

## Remarks

Independent hardware vendors may define their own set of performance counters for their devices, by giving the enumeration value a number that is greater than the value for D3D11_COUNTER_DEVICE_DEPENDENT_0.

This enumeration is used by [D3D11_COUNTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_counter_desc) and [D3D11_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_counter_info).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)