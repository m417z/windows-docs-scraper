# CB\_REQUEST\_STATUS enumeration

Specifies the status of an asynchronous request. This enumeration is used with the [**IConnectionBrokerRequest::CheckStatus**](https://learn.microsoft.com/windows/win32/termserv/iconnectionbrokerrequest-checkstatus) method.

## Constants

**CB\_STATUS\_INVALID**

The request object is not initialized.

**CB\_STATUS\_INITIATING\_REQUEST**

Not used.

**CB\_STATUS\_REQUEST\_COMPLETED**

The request is complete.

**CB\_STATUS\_REQUEST\_FAILED**

The request failed.

**CB\_STATUS\_REQUEST\_ABORTED**

The request was aborted.

**CB\_STATUS\_FINDING\_DESTINATION**

Not used.

**CB\_STATUS\_LOADING\_DESTINATION**

Not used.

**CB\_STATUS\_BRINGING\_SESSION\_ONLINE**

Not used.

**CB\_STATUS\_REDIRECTING\_TO\_DESTINATION**

Not used.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Header<br> | Cbclient.h |

## See also

[**IConnectionBrokerRequest::CheckStatus**](https://learn.microsoft.com/windows/win32/termserv/iconnectionbrokerrequest-checkstatus)

