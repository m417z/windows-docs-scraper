# TF_DA_COLOR structure

## Description

The **TF_DA_COLOR** structure contains color data used in the display attributes for a range of text.

## Members

### `type`

Specifies the color type as defined in the [TF_DA_COLORTYPE](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tf_da_colortype) enumeration.

### `nIndex`

Specifies the color as a system color index as defined in [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor). This member is used only if **type** is equal to TF_CT_SYSCOLOR.

### `cr`

Specifies the color as an RGB value. This member is used only if **type** is equal to TF_CT_COLORREF.

## See also

[GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)

[TF_DA_COLORTYPE](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tf_da_colortype)