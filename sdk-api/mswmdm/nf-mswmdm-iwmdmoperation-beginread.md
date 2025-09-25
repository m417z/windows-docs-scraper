# IWMDMOperation::BeginRead

## Description

The **BeginRead** method indicates that a "read from device" action is beginning. Windows Media Device Manager only calls this method if the application calls [IWMDMStorageControl::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstoragecontrol-read) and passes in this **IWMDMOperation** interface.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

This method is called just before the Windows Media Device Manager calls [IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata).

#### Examples

The following C++ code example implements the **BeginRead** method and outputs a message when a read-from-device action is beginning.

```cpp

HRESULT BeginRead()
{
    // TODO: Display the message: "IWMDMOperation event--BeginRead."

    // If the global handle of the source file is uninitialized, fail.
    if (m_File == INVALID_HANDLE_VALUE)
        return E_FAIL;

    // Global status to let TransferObjectData know what kind of
    // operation is happening.
    m_OperationStatus = OPERATION_READ;
    return S_OK;
}

```

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMOperation::BeginWrite](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-beginwrite)