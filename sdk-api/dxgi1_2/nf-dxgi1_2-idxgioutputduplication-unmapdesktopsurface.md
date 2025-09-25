# IDXGIOutputDuplication::UnMapDesktopSurface

## Description

Invalidates the pointer to the desktop image that was retrieved by using [IDXGIOutputDuplication::MapDesktopSurface](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-mapdesktopsurface).

## Return value

**UnMapDesktopSurface** returns:

* S_OK if it successfully completed.
* DXGI_ERROR_INVALID_CALL if the application did not map the desktop surface by calling [IDXGIOutputDuplication::MapDesktopSurface](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutputduplication-mapdesktopsurface).
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGIOutputDuplication](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutputduplication)