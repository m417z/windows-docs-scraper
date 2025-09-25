# ExtSelectClipRgn function

## Description

The **ExtSelectClipRgn** function combines the specified region with the current clipping region using the specified mode.

## Parameters

### `hdc` [in]

A handle to the device context.

### `hrgn` [in]

A handle to the region to be selected. This handle must not be **NULL** unless the RGN_COPY mode is specified.

### `mode` [in]

The operation to be performed. It must be one of the following values.

| Value | Meaning |
| --- | --- |
| **RGN_AND** | The new clipping region combines the overlapping areas of the current clipping region and the region identified by *hrgn*. |
| **RGN_COPY** | The new clipping region is a copy of the region identified by *hrgn*. This is identical to [SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn). If the region identified by *hrgn* is **NULL**, the new clipping region is the default clipping region (the default clipping region is a null region). |
| **RGN_DIFF** | The new clipping region combines the areas of the current clipping region with those areas excluded from the region identified by *hrgn*. |
| **RGN_OR** | The new clipping region combines the current clipping region and the region identified by *hrgn*. |
| **RGN_XOR** | The new clipping region combines the current clipping region and the region identified by *hrgn* but excludes any overlapping areas. |

## Return value

The return value specifies the new clipping region's complexity; it can be one of the following values.

| Return code | Description |
| --- | --- |
| **NULLREGION** | Region is empty. |
| **SIMPLEREGION** | Region is a single rectangle. |
| **COMPLEXREGION** | Region is more than one rectangle. |
| **ERROR** | An error occurred. |

## Remarks

If an error occurs when this function is called, the previous clipping region for the specified device context is not affected.

The **ExtSelectClipRgn** function assumes that the coordinates for the specified region are specified in device units.

Only a copy of the region identified by the *hrgn* parameter is used. The region itself can be reused after this call or it can be deleted.

## See also

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn)