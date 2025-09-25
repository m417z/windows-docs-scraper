# IWMDMOperation::BeginWrite

## Description

The **BeginWrite** method indicates that a "write to device" action is beginning. Windows Media Device Manager only calls this method if the application calls **IWMDMStorageControl/2/3::Insert/2/3** and passes in this interface.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

This method is called just before the Windows Media Device Manager calls [IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata) to begin writing data to the device.

#### Examples

The following C++ code example implements the **BeginWrite** method and outputs a message when a write-to-device action is beginning.

```cpp

HRESULT BeginWrite()
{
    // TODO: Display the message: "IWMDMOperation event--BeginWrite."

    // If the global handle of the destination file is uninitialized, fail.
    if (m_File == INVALID_HANDLE_VALUE)
        return E_FAIL;

    // Global status to let TransferObjectData know what kind of
    // operation is happening.
    m_OperationStatus = OPERATION_WRITE;
    return S_OK;
}

```

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMOperation::BeginRead](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-beginread)