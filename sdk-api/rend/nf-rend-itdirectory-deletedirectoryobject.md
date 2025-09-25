# ITDirectory::DeleteDirectoryObject

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**DeleteDirectoryObject** method deletes an object from the server.

## Parameters

### `pDirectoryObject` [in]

Pointer to
[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject) that will be deleted from the directory.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDirectoryObject* parameter is not a valid pointer. |
| **RND_NOT_CONNECTED** | The [ITDirectory::Connect](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-connect) method has not been invoked or did not succeed. |
| **E_NOTIMPL** | This method is not implemented. |

## Remarks

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)