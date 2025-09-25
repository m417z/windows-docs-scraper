# IDXGIOutputDuplication::MapDesktopSurface

## Description

Provides the CPU with efficient access to a desktop image if that desktop image is already in system memory.

## Parameters

### `pLockedRect` [out]

A pointer to a [DXGI_MAPPED_RECT](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_mapped_rect) structure that receives the surface data that the CPU needs to directly access the surface data.

## Return value

**MapDesktopSurface** returns:

* S_OK if it successfully retrieved the surface data.
* DXGI_ERROR_ACCESS_LOST if the desktop duplication interface is invalid. The desktop duplication interface typically becomes invalid when a different type of image is displayed on the desktop. Examples of this situation are:
  + Desktop switch
  + Mode change
  + Switch from DWM on, DWM off, or other full-screen applicationIn this situation, the application must release the [IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication) interface and create a new **IDXGIOutputDuplication** for the new content.
* DXGI_ERROR_INVALID_CALL if the application already has an outstanding map on the desktop image. The application must call [UnMapDesktopSurface](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-unmapdesktopsurface) before it calls **MapDesktopSurface** again. DXGI_ERROR_INVALID_CALL is also returned if the application did not own the desktop image when it called **MapDesktopSurface**.
* DXGI_ERROR_UNSUPPORTED if the desktop image is not in system memory. In this situation, the application must first transfer the image to a staging surface and then lock the image by calling the [IDXGISurface::Map](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface-map) method.
* E_INVALIDARG if the *pLockedRect* parameter is incorrect; for example, if *pLockedRect* is **NULL**.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

You can successfully call **MapDesktopSurface** if the **DesktopImageInSystemMemory** member of the [DXGI_OUTDUPL_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_desc) structure is set to **TRUE**. If **DesktopImageInSystemMemory** is **FALSE**, **MapDesktopSurface** returns DXGI_ERROR_UNSUPPORTED. Call [IDXGIOutputDuplication::GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-getdesc) to retrieve the **DXGI_OUTDUPL_DESC** structure.

## See also

[IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication)