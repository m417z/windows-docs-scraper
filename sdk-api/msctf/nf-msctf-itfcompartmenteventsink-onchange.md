# ITfCompartmentEventSink::OnChange

## Description

Called when compartment data changes.

## Parameters

### `rguid` [in]

Contains a GUID that identifies the compartment that changed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When this method is called, the data has changed. The new data can be obtained at this time by calling [ITfCompartment::GetValue](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcompartment-getvalue).

[ITfCompartment::SetValue](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcompartment-setvalue) will return E_UNEXPECTED if called from within this notification.

## See also

[ITfCompartment::GetValue](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcompartment-getvalue), [ITfCompartment::SetValue](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcompartment-setvalue), [ITfCompartmentEventSink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartmenteventsink)