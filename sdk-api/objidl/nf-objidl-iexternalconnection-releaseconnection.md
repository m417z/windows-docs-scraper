# IExternalConnection::ReleaseConnection

## Description

Decrements the count of an object's strong external connections.

## Parameters

### `extconn` [in]

The type of external connection to the object. The only type of external connection currently supported by this interface is strong, which means that the object must remain alive as long as this external connection exists. Strong external connections are represented by the value EXTCONN_STRONG, which is defined in the enumeration [EXTCONN](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-extconn).

### `reserved` [in]

Information about the connection. This parameter is reserved for use by OLE. Its value can be zero, but not necessarily. Therefore, implementations of **ReleaseConnection** should not contain blocks of code whose execution depends on whether a zero value is returned.

### `fLastReleaseCloses` [in]

This parameter is **TRUE** if the connection being released is the last external lock on the object, and therefore the object should close. Otherwise, the object should remain open until closed by the user or another process.

## Return value

The method returns the count of connections. This value is intended to be used only for debugging purposes.

## Remarks

If *fLastReleaseCloses* equals **TRUE**, calling **ReleaseConnection** causes the object to shut itself down. Calling this method is the only way in which a DLL object, running in the same process space as the container application, will know when to close following a silent update.

## See also

[IExternalConnection](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iexternalconnection)