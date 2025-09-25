# DXGI_MATRIX_3X2_F structure

## Description

Represents a 3x2 matrix. Used with [GetMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-getmatrixtransform) and [SetMatrixTransform](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-idxgiswapchain2-setmatrixtransform) to indicate the scaling and translation transform for [SwapChainPanel](https://learn.microsoft.com/uwp/api/windows.ui.xaml.controls.swapchainpanel) swap chains.

## Members

### `_11`

The value in the first row and first column of the matrix.

### `_12`

The value in the first row and second column of the matrix.

### `_21`

The value in the second row and first column of the matrix.

### `_22`

The value in the second row and second column of the matrix.

### `_31`

The value in the third row and first column of the matrix.

### `_32`

The value in the third row and second column of the matrix.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)