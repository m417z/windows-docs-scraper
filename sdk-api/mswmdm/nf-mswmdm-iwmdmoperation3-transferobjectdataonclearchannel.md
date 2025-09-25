# IWMDMOperation3::TransferObjectDataOnClearChannel

## Description

The **TransferObjectDataOnClearChannel** method is a more efficient implementation of [IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata).

## Parameters

### `pData`

Pointer to an unencrypted byte buffer.

### `pdwSize`

Pointer to a variable specifying the buffer size.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

If the application supports this method, it is called in preference to the **TransferObjectData**.

See **TransferObjectData** to learn about the basics of this function. The difference between this method and **TransferObjectData** is that this method does not require the sender or receiver to encrypt or decrypt data, which requires extra processing time. Licensed content can still be sent using this method, since the content is always encrypted during transport anyway.

If the application supports this method, it is called in preference to the **TransferObjectData**.

## See also

[IWMDMOperation3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation3)