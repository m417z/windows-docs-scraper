# IDirect3DDevice9::GetAvailableTextureMem

## Description

Returns an estimate of the amount of available texture memory.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The function returns an estimate of the available texture memory.

## Remarks

The returned value is rounded to the nearest MB. This is done to reflect the fact that video memory estimates are never precise due to alignment and other issues that affect consumption by certain resources. Applications can use this value to make gross estimates of memory availability to make large-scale resource decisions such as how many levels of a mipmap to attempt to allocate, but applications cannot use this value to make small-scale decisions such as if there is enough memory left to allocate another resource.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)