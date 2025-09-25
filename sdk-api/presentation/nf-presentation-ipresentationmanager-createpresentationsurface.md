## Description

Creates a presentation surface for a piece of content that can be hosted in a visual tree and assigned a single front buffer.

## Parameters

### `compositionSurfaceHandle`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A handle to the composition surface to bind the presentation surface to.

### `presentationSurface`

Type: **[IPresentationSurface](https://learn.microsoft.com/windows/win32/api/presentation/nn-presentation-ipresentationsurface)**

The created presentation surface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

## See also