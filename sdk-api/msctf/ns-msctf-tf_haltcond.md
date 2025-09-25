# TF_HALTCOND structure

## Description

The **TF_HALTCOND** structure is used to contain conditions of a range shift.

## Members

### `pHaltRange`

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that halts the shift. If the range shift encounters this range during the shift, the shift halts. This member can be **NULL**.

### `aHaltPos`

Contains one of the [TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor) values that specifies which anchor of **pHaltRange** the anchor will get shifted to if **pHaltRange** is encountered during the range shift. This member is ignored if **pHaltRange** is **NULL**.

### `dwFlags`

Contains a set of flags that modify the behavior of the range shift. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| TF_HF_OBJECT | The range shift halts if an embedded object is encountered. |

## See also

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::ShiftEnd](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftend)

[ITfRange::ShiftStart](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-shiftstart)

[TfAnchor](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfanchor)