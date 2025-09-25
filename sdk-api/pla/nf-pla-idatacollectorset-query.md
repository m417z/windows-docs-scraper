# IDataCollectorSet::Query

## Description

Retrieves the specified data collector set.

## Parameters

### `name` [in]

The name of the data collector set to retrieve. The name is case-insensitive and is of the form **[***Namespace***\]***Name*. For details on the optional namespace, see Remarks.

### `server` [in]

The computer on which the set exists. You can specify a computer name, a fully qualified domain name, or an IP address (IPv4 or IPv6 format). If **NULL**, the set is retrieved from the local computer.

## Return value

Returns S_OK if successful. The following table shows possible error values.

| Return code/value | Description |
| --- | --- |
| **PLA_E_DCS_NOT_FOUND**<br><br>0x80300002 | The specified data collector set was not found. |
| **E_NOINTERFACE**<br><br>0x80300002 | You must retrieve a data collector set into an empty instance or into an instance that uses the same namespace. |
| **HRESULT_FROM_WIN32(RPC_S_SERVER_UNAVAILABLE)** | The RPC server is not available. The method is unable to query the data collector set remotely. To query the data collector set from a remote computer running Windows Vista, enable Performance Logs and Alerts in **Windows Firewall Settings** on the remote computer. |
| **HRESULT_FROM_WIN32(ERROR_BAD_NETPATH)** | Unable to find the remote computer. |

## Remarks

The contents of the retrieved data collector set overwrites the contents of this instance. The instance must be empty (newly created) or be from the same namespace.

Specify the same *name* and *server* parameter values that you specified when calling the [IDataCollectorSet::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-commit) method to save the set.

The *name* parameter can contain an optional namespace; however, you should always specify the namespace. If you do not specify the namespace, PLA uses "Service" for computers running Windows Vista and "Legacy" for computers running operating systems prior to Windows Vista. The following table lists the possible namespace values.

| Namespace | Description |
| --- | --- |
| Autosession | Contains ETW [AutoLogger](https://learn.microsoft.com/windows/desktop/ETW/configuring-and-starting-an-autologger-session) sessions. The collector starts when the computer starts, cannot be stopped, and the status is undefined. |
| Legacy | Same as Service but on computers running an operating system that is prior to Windows Vista. |
| Service | Contains all data collector sets created by the user. These sets can be scheduled and can be set to run as anyone (the user needs the batch logon account right). If you do not specify credentials, the set will run as LocalSystem (if the user is an administrator). |
| Session | Contains [Event Tracing for Windows](https://learn.microsoft.com/windows/desktop/ETW/event-tracing-portal) (ETW) trace sessions. These sets cannot be scheduled. If you use this namespace, the set must contain only one data collector and it must be a trace data collector. |
| System | Contains read-only data collector sets that cannot be scheduled; however, you can start these sets manually. If you do not specify credentials, the set will run as the current user. |

Note that the Service namespace can be used in place of the Legacy namespace on computers running operating systems prior to Windows Vista.

To query all committed sets on a computer, call the [IDataCollectorSetCollection::GetDataCollectorSets](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorsetcollection-getdatacollectorsets) method.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-commit)

[IDataCollectorSet::Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-delete)