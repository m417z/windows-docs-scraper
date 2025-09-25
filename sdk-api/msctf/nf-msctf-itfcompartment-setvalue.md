# ITfCompartment::SetValue

## Description

Sets the data for a compartment.

## Parameters

### `tid` [in]

Contains a [TfClientId](https://learn.microsoft.com/windows/desktop/TSF/tfclientid) value that identifies the client.

### `pvarValue` [in]

Pointer to a VARIANT structure that contains the data to be set. Only VT_I4, VT_UNKNOWN and VT_BSTR data types are allowed.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *pvarValue* is invalid. |
| **E_UNEXPECTED** | The compartment was cleared by a call to [ITfCompartmentMgr::ClearCompartment](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcompartmentmgr-clearcompartment), this method was called during a [ITfCompartmentEventSink::OnChange](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcompartmenteventsink-onchange) notification or only the owner can clear this compartment. |

## See also

[ITfCompartment interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartment), [ITfCompartment::GetValue](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcompartment-getvalue), [ITfCompartmentMgr::ClearCompartment](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcompartmentmgr-clearcompartment), [VariantClear function](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-variantclear)