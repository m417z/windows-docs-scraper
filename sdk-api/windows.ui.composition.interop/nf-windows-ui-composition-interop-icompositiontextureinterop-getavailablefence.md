## Description

Retrieves a Direct3D synchronization fence/value pair that indicates when the composition texture will become available, if that info is known. The value returned depends on the availability state of the composition texture. An availability state specifies whether, and when, it's safe to render to the composition texture.

See the **Remarks** section of [IDCompositionTexture::GetAvailableFence](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositiontexture-getavailablefence) for the availability states, their descriptions, and how **GetAvailableFence** behaves for each state.

If a composition texture becomes available, then your app must be careful to issue rendering only to the exact subregion of the Direct3D texture that it refers to.

## Parameters

### `fenceValue`

Type: \_Out\_ **UINT64\***

The returned fence value.

### `iid`

Type: \_In\_ **REFIID**

An interface identifier.

### `availableFence`

Type: \_Outptr\_result\_maybenull\_ **void\*\***

The returned available fence, or `nullptr`, depending on the availability state of the composition texture. For details, see the **Remarks** section of [IDCompositionTexture::GetAvailableFence](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositiontexture-getavailablefence).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) error code.

## Remarks

## See also

* [ICompositionTextureInterop interface](https://learn.microsoft.com/windows/win32/api/windows.ui.composition.interop/nn-windows-ui-composition-interop-icompositiontextureinterop)
* [IDCompositionTexture::GetAvailableFence](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositiontexture-getavailablefence)