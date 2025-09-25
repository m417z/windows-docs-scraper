# ITfCompartment::GetValue

## Description

Obtains the data for a compartment.

## Parameters

### `pvarValue` [out]

Pointer to a **VARIANT** structure that receives the data. This receives VT_EMPTY if the compartment has no value. The caller must free this data when it is no longer required by calling [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The compartment has no value. *pvarValue* receives VT_EMPTY. |
| **E_UNEXPECTED** | The compartment has been cleared by a call to [ITfCompartmentMgr::ClearCompartment](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcompartmentmgr-clearcompartment). |
| **E_INVALIDARG** | *pvarValue* is invalid. |

## Remarks

The caller must recognize the supplied data format in order to use the data. The compartment installer must publish the data format to enable other clients to use it.

## See also

[ITfCompartment interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartment), [ITfCompartment::SetValue](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcompartment-setvalue), [ITfCompartmentMgr::ClearCompartment](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcompartmentmgr-clearcompartment), [VariantClear function](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-variantclear)