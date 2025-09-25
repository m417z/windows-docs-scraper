# ID3D11Device::GetExceptionMode

## Description

Get the exception-mode flags.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that contains one or more exception flags; each flag specifies a condition which will cause an exception to be raised. The flags are listed in [D3D11_RAISE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_raise_flag). A default value of 0 means there are no flags.

## Remarks

An exception-mode flag is used to elevate an error condition to a non-continuable exception.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)