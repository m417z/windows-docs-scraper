# ITfCompartmentMgr::GetCompartment

## Description

Obtains the compartment object for a specified compartment.

## Parameters

### `rguid` [in]

Contains a GUID that identifies the compartment.

### `ppcomp` [out]

Pointer to an [ITfCompartment](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcompartment) interface pointer that receives the compartment object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppcomp* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfCompartmentMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartmentmgr), [ITfCompartment interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartment), [Compartments](https://learn.microsoft.com/windows/desktop/TSF/compartments)