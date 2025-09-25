# TF_DA_COLORTYPE enumeration

## Description

Elements of the **TF_DA_COLORTYPE** enumeration specify the format of the color contained in the [TF_DA_COLOR](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_da_color) structure.

## Constants

### `TF_CT_NONE:0`

The structure contains no color data.

### `TF_CT_SYSCOLOR:1`

The color is specified as a system color index. For more information about the system color indexes, see [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor).

### `TF_CT_COLORREF:2`

The color is specified as an RGB value.

## See also

[GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)

[TF_DA_COLOR](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_da_color)