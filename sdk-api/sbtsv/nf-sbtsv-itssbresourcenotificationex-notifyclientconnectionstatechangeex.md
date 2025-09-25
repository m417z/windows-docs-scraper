# ITsSbResourceNotificationEx::NotifyClientConnectionStateChangeEx

## Description

Notifies registered plug-ins about state changes in a client connection.

## Parameters

### `userName` [in]

The user name.

### `domain` [in]

The user domain.

### `initialProgram` [in]

The initial program.

### `poolName` [in]

The name of the pool.

### `targetName` [in]

The name of the target.

### `connectionChangeType` [in]

The type of change that has occurred. This parameter can be one of the following values.

#### CONNECTION_REQUEST_PENDING

A client request is pending a session logon
from
a
user.

#### CONNECTION_REQUEST_FAILED

RD Connection Broker failed to process the request.
This value is
issued just before
RD Connection Broker deletes the connection request from its store.

#### CONNECTION_REQUEST_TIMEDOUT

The
request timed out. This generally means
that either the user has canceled the request or was unable to log on
because of network connectivity issues. This value is
issued just before
RD Connection Broker deletes the connection request from its store.

#### CONNECTION_REQUEST_SUCCEEDED

The user successfully logged on to the target computer. This
value is issued just before
RD Connection Broker deletes the connection request from its store.

#### CONNECTION_REQUEST_CANCELLED

RD Connection Broker
canceled a connection request

 because the
connection
request was being processed while the
RD Connection Broker service was stopping.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourceNotification](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotification)

[ITsSbResourceNotificationEx](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotificationex)