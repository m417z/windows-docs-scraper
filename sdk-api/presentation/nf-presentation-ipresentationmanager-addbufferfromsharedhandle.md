## Description

Adds a shared DXGI resource to the presentation manager to be tracked as a presentation buffer.

## Parameters

### `dxgiSharedResourceHandle`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The handle to a shared DXGI resource.

### `presentationBuffer`

Type: **[IPresentationBuffer](https://learn.microsoft.com/windows/win32/api/presentation/nn-presentation-ipresentationbuffer)**

The returned presentation buffer that references the DXGI resource.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

## See also