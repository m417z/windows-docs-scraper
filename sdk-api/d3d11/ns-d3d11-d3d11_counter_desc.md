# D3D11_COUNTER_DESC structure

## Description

Describes a counter.

## Members

### `Counter`

Type: **[D3D11_COUNTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_counter)**

Type of counter (see [D3D11_COUNTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_counter)).

### `MiscFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved.

## Remarks

This structure is used by [ID3D11Counter::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11counter-getdesc), [ID3D11Device::CheckCounter](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkcounter) and [ID3D11Device::CreateCounter](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createcounter).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)