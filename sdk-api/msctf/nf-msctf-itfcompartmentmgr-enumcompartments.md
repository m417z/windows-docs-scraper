# ITfCompartmentMgr::EnumCompartments

## Description

The **ITfCompartmentMgr::EnumCompartments** method obtains an enumerator that contains the GUID of the compartments within the compartment manager.

## Parameters

### `ppEnum` [out]

Pointer to an **IEnumGUID** interface pointer that receives the enumerator object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *ppcEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfCompartmentMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartmentmgr), [ITfCompartment interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartment), [Compartments](https://learn.microsoft.com/windows/desktop/TSF/compartments)