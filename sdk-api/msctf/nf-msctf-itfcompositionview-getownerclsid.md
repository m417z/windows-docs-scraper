# ITfCompositionView::GetOwnerClsid

## Description

Obtains the class identifier of the text service that created the composition object.

## Parameters

### `pclsid` [out]

Pointer to a CLSID that receives the class identifier of the text service that owns the composition.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *pclsid* is invalid. |
| **E_UNEXPECTED** | The composition has been terminated. |

## Remarks

This method can be used to enable a text service to filter compositions that it does not own.

## See also

[ITfCompositionView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompositionview)