# DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS enumeration

## Description

Describes which levels of hardware composition are supported.

## Constants

### `DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_FULLSCREEN:1`

This flag specifies that swapchain composition can be facilitated in a performant manner using hardware for fullscreen applications.

### `DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_WINDOWED:2`

This flag specifies that swapchain composition can be facilitated in a performant manner using hardware for windowed applications.

### `DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_CURSOR_STRETCHED:4`

This flag specifies that swapchain composition facilitated using hardware can cause the cursor to appear stretched.

## Remarks

Values of this enumeration are returned from the [IDXGIOutput6::CheckHardwareCompositionSupport](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nf-dxgi1_6-idxgioutput6-checkhardwarecompositionsupport) method in the *pFlags* out parameter.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[IDXGIOutput6::CheckHardwareCompositionSupport method](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nf-dxgi1_6-idxgioutput6-checkhardwarecompositionsupport)