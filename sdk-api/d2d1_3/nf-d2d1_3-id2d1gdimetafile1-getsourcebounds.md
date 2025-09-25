# ID2D1GdiMetafile1::GetSourceBounds

## Description

Gets the bounds of the metafile in source space in DIPs. This corresponds
to the frame rect in an EMF/EMF+.

## Parameters

### `bounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The bounds, in DIPs, of the metafile.

## Return value

Type: **HRESULT**

S_OK if successful, otherwise a failure HRESULT.

## See also

[ID2D1GdiMetafile](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafile)

[ID2D1GdiMetafile1](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1gdimetafile1)

[[MS-EMFPLUS]: Enhanced Metafile Format Plus Extensions](https://learn.microsoft.com/openspecs/windows_protocols/ms-emfplus/5f92c789-64f2-46b5-9ed4-15a9bb0946c6)

[[MS-EMF]: Enhanced Metafile Format](https://learn.microsoft.com/openspecs/windows_protocols/ms-emf/91c257d7-c39d-4a36-9b1f-63e3f73d30ca)