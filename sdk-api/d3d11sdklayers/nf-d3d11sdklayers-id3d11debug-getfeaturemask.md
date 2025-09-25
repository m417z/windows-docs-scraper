# ID3D11Debug::GetFeatureMask

## Description

Get a bitfield of flags that indicates which debug features are on or off.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask of feature-mask flags bitwise ORed together. If a flag is present, then that feature will be set to on, otherwise the feature will be set to off. See [ID3D11Debug::SetFeatureMask](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11debug-setfeaturemask) for a list of possible feature-mask flags.

## See also

[ID3D11Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11debug)