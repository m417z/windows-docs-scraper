# D3D12_FEATURE_DATA_FORMAT_SUPPORT structure

## Description

Describes which resources are supported by the current graphics driver for a given format.

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the format to return info about.

### `Support1`

A combination of [D3D12_FORMAT_SUPPORT1](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_format_support1)-typed values that are combined by using a bitwise OR operation. The resulting value specifies which resources are supported.

### `Support2`

A combination of [D3D12_FORMAT_SUPPORT2](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_format_support2)-typed values that are combined by using a bitwise OR operation. The resulting value specifies which unordered resource options are supported.

## Remarks

Refer to [Typed unordered access view loads](https://learn.microsoft.com/windows/desktop/direct3d11/typed-unordered-access-view-loads) for an example use of this structure.

Also see [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature).

### Hardware support for DXGI Formats

To view tables of DXGI formats and hardware features, refer to:

* [DXGI Format Support for Direct3D Feature Level 12.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/hardware-support-for-direct3d-12-1-formats)
* [DXGI Format Support for Direct3D Feature Level 12.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/hardware-support-for-direct3d-12-0-formats)
* [DXGI Format Support for Direct3D Feature Level 11.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-1-feature-level-hardware)
* [DXGI Format Support for Direct3D Feature Level 11.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-0-feature-level-hardware)
* [Hardware Support for Direct3D 10Level9 Formats](https://learn.microsoft.com/previous-versions/ff471324(v=vs.85))
* [Hardware Support for Direct3D 10.1 Formats](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-1-hardware)
* [Hardware Support for Direct3D 10 Formats](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-0-hardware)

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)

[Typed unordered access view loads](https://learn.microsoft.com/windows/desktop/direct3d11/typed-unordered-access-view-loads)