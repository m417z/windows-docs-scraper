# CB\_CONNECTION\_INFO structure

Contains information about an incoming connection request. This structure is used with the [**IConnectionBrokerClient::GetTargetInfo**](https://learn.microsoft.com/windows/win32/termserv/iconnectionbrokerclient-gettargetinfo) method.

## Members

**UserName**

The name of the user requesting a session.

**Domain**

The name of the domain that **UserName** is a member of.

**InitialProgram**

The fully qualified path and file name of the initial program that is started when the session is started. Set this member to an empty string if no initial program should be started.

**Resource**

A value of the [**CB\_RESOURCE\_TYPE**](https://learn.microsoft.com/windows/win32/termserv/cb-resource-type) enumeration that specifies the type of resource that the incoming connection is connecting to. If the **PluginName** member is **NULL**, this member is used to by the Remote Desktop Connection Broker to determine which plug-in to invoke for determining the target computer.

**PluginName**

The name of the plug-in to invoke to determine the target computer. If this parameter is **NULL**, the **Resource** member is used to determine which plug-in to invoke.

**FarmName**

The name of the farm that contains the computers, one of which will be the target computer where the connection will be redirected.

**dwVendorInfoLength**

This member is reserved for future use.

**pVendorSpecificInfo**

This member is reserved for future use.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Header<br> | Cbclient.h |

## See also

[**IConnectionBrokerClient::GetTargetInfo**](https://learn.microsoft.com/windows/win32/termserv/iconnectionbrokerclient-gettargetinfo)

