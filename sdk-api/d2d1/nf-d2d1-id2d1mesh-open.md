# ID2D1Mesh::Open

## Description

Opens the mesh for population.

## Parameters

### `tessellationSink` [out]

Type: **[ID2D1TessellationSink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1tessellationsink)****

When this method returns, contains a pointer to a pointer to an [ID2D1TessellationSink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1tessellationsink) that is used to populate the mesh. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Mesh](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1mesh)