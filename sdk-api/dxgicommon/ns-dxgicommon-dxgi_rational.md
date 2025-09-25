# DXGI_RATIONAL structure

## Description

Represents a rational number.

## Members

### `Numerator`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An unsigned integer value representing the top of the rational number.

### `Denominator`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An unsigned integer value representing the bottom of the rational number.

## Remarks

This structure is a member of the [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85)) structure.

The **DXGI_RATIONAL** structure operates under the following rules:

* 0/0 is legal and will be interpreted as 0/1.
* 0/anything is interpreted as zero.
* If you are representing a whole number, the denominator should be 1.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)