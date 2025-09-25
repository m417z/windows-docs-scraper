# TF_DISPLAYATTRIBUTE structure

## Description

The **TF_DISPLAYATTRIBUTE** structure contains display attribute data for rendering text.

## Members

### `crText`

Contains a [TF_DA_COLOR](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_da_color) structure that defines the text foreground color.

### `crBk`

Contains a **TF_DA_COLOR** structure that defines the text background color.

### `lsStyle`

Contains a [TF_DA_LINESTYLE](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tf_da_linestyle) enumeration value that defines the underline style.

### `fBoldLine`

A BOOL value that specifies if the underline should be bold or normal weight. If this value is nonzero, the underline should be bold. If this value is zero, the underline should be normal.

### `crLine`

Contains a **TF_DA_COLOR** structure that defines the color of the underline.

### `bAttr`

Contains a [TF_DA_ATTR_INFO](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tf_da_attr_info) value that defines text conversion display attribute data.

## See also

[TF_DA_ATTR_INFO](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tf_da_attr_info)

[TF_DA_COLOR](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_da_color)

[TF_DA_LINESTYLE](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tf_da_linestyle)