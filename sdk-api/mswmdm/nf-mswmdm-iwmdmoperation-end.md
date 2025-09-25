# IWMDMOperation::End

## Description

The **End** method indicates that a read or write operation is finished, whether successful or not, and it returns a completion code.

## Parameters

### `phCompletionCode` [in]

Completion code for the operation.

### `pNewObject` [in]

When sending to a device, a pointer to a new **IWMDMStorage** object representing the new object that has been sent to the device. When reading from a device, a pointer to the **IWMDMStorage** object that was read from the device.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The **End** method is called whether or not the transfer was successful, and is the last **IWMDMOperation** method called. This method can be used to signal the application to close all file handles and other objects required by the read or write operation.

#### Examples

The following C++ code closes a global file handle after a read or write action, and outputs a message.

```cpp

HRESULT End(HRESULT* phCompletionCode, IUnknown* pNewObject)
{
    // TODO: Display the message: "IWMDMOperation event--End."

    // Close the file handle now that we're done with it.
    if (m_File != INVALID_HANDLE_VALUE)
        if (!CloseHandle(m_File))
            // TODO: Display the message: "Couldn't close the file."

    // Reset global status flag.
    m_OperationStatus = OPERATION_UNINITIALIZED;
    return S_OK;
}

```

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)