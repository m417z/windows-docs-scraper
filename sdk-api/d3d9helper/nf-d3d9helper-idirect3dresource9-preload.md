# IDirect3DResource9::PreLoad

## Description

Preloads a managed resource.

## Remarks

Calling this method indicates that the application will need this managed resource shortly. This method has no effect on nonmanaged resources.

**IDirect3DResource9::PreLoad** detects "thrashing" conditions where more resources are being used in each frame than can fit in video memory simultaneously. Under such circumstances **IDirect3DResource9::PreLoad** silently does nothing.

## See also

[IDirect3DResource9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dresource9)