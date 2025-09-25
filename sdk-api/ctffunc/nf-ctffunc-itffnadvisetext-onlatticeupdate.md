# ITfFnAdviseText::OnLatticeUpdate

## Description

Called when a lattice element within a context changes.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that represents the range of text that changed.

### `pLattice` [in]

Pointer to an [ITfLMLattice](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itflmlattice) object that represents the new lattice element.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[ITfFnAdviseText](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnadvisetext)

[ITfLMLattice](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itflmlattice)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)