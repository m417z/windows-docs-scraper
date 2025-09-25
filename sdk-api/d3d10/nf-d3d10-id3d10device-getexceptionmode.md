# ID3D10Device::GetExceptionMode

## Description

Get the exception-mode flags.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that contains one or more exception flags; each flag specifies a condition which will cause an exception to be raised. The flags are listed in [D3D10_RAISE_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_raise_flag). A default value of 0 means there are no flags.

## Remarks

An exception-mode flag is used to elevate an error condition to a non-continuable exception.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)