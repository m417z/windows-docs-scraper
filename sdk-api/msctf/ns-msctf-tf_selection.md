# TF_SELECTION structure

## Description

The **TF_SELECTION** structure contains text selection data.

## Members

### `range`

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that specifies the selected text.

### `style`

A [TF_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_selectionstyle) structure that contains selection data.

## See also

[ITfContext::GetSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getselection)

[ITfContext::SetSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-setselection)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[TF_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_selectionstyle)