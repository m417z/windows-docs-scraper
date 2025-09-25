# IExternalConnection::AddConnection

## Description

Increments the count of an object's strong external connections.

## Parameters

### `extconn` [in]

The type of external connection to the object. The only type of external connection currently supported by this interface is strong, which means that the object must remain alive as long as this external connection exists. Strong external connections are represented by the value EXTCONN_STRONG, which is defined in the enumeration [EXTCONN](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-extconn).

### `reserved` [in]

Information about the connection. This parameter is reserved for use by OLE. Its value can be zero, but not necessarily. Therefore, implementations of **AddConnection** should not contain blocks of code whose execution depends on whether a zero value is returned.

## Return value

The method returns the count of connections. This value is intended to be used only for debugging purposes.

## Remarks

An object created by a EXE object server relies on its stub manager to call **AddConnection** whenever a link client activates and therefore creates an external lock on the object. When the link client breaks the connection, the stub manager calls [IExternalConnection::ReleaseConnection](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iexternalconnection-releaseconnection) to release the lock.

DLL object applications exist in the same process space as their objects, so they do not use RPC (remote procedure calls) and do not have stub managers to keep track of external connections. Therefore, DLL servers that support external links to their objects must implement [IExternalConnection](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iexternalconnection) so that link clients can directly call the interface to inform them when connections are added or released.

The following is a typical implementation for the **AddConnection** method.

``` syntax
DWORD MyInterface::AddConnection(DWORD extconn, DWORD dwReserved)
{
    return extconn & EXTCONN_STRONG ? ++m_cStrong : 0;
}

```

## See also

[IExternalConnection](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iexternalconnection)

[IRunnableObject::LockRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-lockrunning)

[OleLockRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olelockrunning)