# ITfCompartmentMgr::ClearCompartment

## Description

Removes the specified compartment.

## Parameters

### `tid` [in]

Contains a [TfClientId](https://learn.microsoft.com/windows/desktop/TSF/tfclientid) value that identifies the client.

### `rguid` [in]

Contains a GUID that identifies the compartment.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **CONNECT_E_NOCONNECTION** | The compartment cannot be found. |
| **E_FAIL** | An unspecified error occurred. |
| **E_UNEXPECTED** | The owner must clear this compartment. |

## See also

[ITfCompartmentMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartmentmgr), [ITfCompartment interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompartment), [Compartments](https://learn.microsoft.com/windows/desktop/TSF/compartments)