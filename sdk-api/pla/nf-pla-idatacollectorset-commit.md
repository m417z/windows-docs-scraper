# IDataCollectorSet::Commit

## Description

Saves, updates, or validates the data collector set. You can also use this method to flush a trace session.

## Parameters

### `name` [in]

A unique name used to save the data collector set. The name is of the form **[***Namespace***\]***Name*. For details, see Remarks.

### `server` [in]

The computer on which you want to save the set. You can specify a computer name, a fully qualified domain name, or an IP address (IPv4 or IPv6 format). If **NULL**, the set is saved to the local computer.

### `mode` [in]

Indicates whether you want to save, update, flush, or validate the data collector set. For possible values, see the [CommitMode](https://learn.microsoft.com/windows/win32/api/pla/ne-pla-commitmode) enumeration.

### `validation` [out]

An [IValueMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemap) interface that you use to retrieve the validation error of each property whose value is not valid or is ignored. The [IValueMap::Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemap-get_count) property is zero if there were no errors or warnings.

## Return value

Returns S_OK if the method call was successful. You must check the value map for errors (see Remarks). If the method returns S_OK and there are no validation errors, then the set was successfully committed. The following table shows possible error values when calling this method.

| Return code/value | Description |
| --- | --- |
| **E_ACCESSDENIED** | The user must be running as an administrator. |
| **E_NOINTERFACE** | The specified namespace is not supported (for example, if you specified the System namespace when committing the data collector set on a computer running an operating system prior to Windows Vista). |
| **HRESULT_FROM_WIN32(RPC_S_SERVER_UNAVAILABLE)** | The RPC server is not available. The method is unable to save the data collector set remotely. To commit remotely to a computer running Windows Vista, enable Performance Logs and Alerts in **Windows Firewall Settings** on the remote computer. |
| **PLA_E_DCS_ALREADY_EXISTS**<br><br>0x803000B7 | You are trying to commit a new set, but a set with the specified name already exists. |

## Remarks

If you save the set, use the specified *name* and *server* parameter values when calling the [IDataCollectorSet::Query](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-query) method to retrieve the set.

The *name* parameter can contain an optional namespace; however, you should always specify the namespace. If you do not specify the namespace, PLA uses "Service" for computers running Windows Vista and "Legacy" for computers running operating systems prior to Windows Vista. The following table lists the possible namespace values.

| Namespace | Description |
| --- | --- |
| Autosession | Contains ETW [AutoLogger](https://learn.microsoft.com/windows/desktop/ETW/configuring-and-starting-an-autologger-session) sessions. The collector starts when the computer starts, cannot be stopped, and the status is undefined. |
| Legacy | Same as Service but on computers running an operating system that is prior to Windows Vista. |
| Service | Contains all data collector sets created by the user. These sets can be scheduled and can be set to run as anyone. The user needs the **Log on as a batch job** account right (see Administrative Tools, Local Security Policy, Local Policies, User Rights Assignment). If you do not specify credentials, the set will run as LocalSystem (if the user is an administrator). |
| Session | Contains [Event Tracing for Windows](https://learn.microsoft.com/windows/desktop/ETW/event-tracing-portal) (ETW) trace sessions. These sets cannot be scheduled. If you use this namespace, the set must contain only one data collector and it must be a trace data collector. |
| System | Contains read-only data collector sets that cannot be scheduled; however, you can start these sets manually. If you do not specify credentials, the set will run as the current user. |

Note that the Service namespace can be used in place of the Legacy namespace on computers running operating systems prior to Windows Vista.

To determine the validation errors that occurred, retrieve the [IValueMapItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ivaluemapitem) interface for each error in the value map collection. The [IValueMapItem::Key](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_key) property contains the XPath of the element in error, for example, /AlertDataCollector/TaskArguments. The [IValueMapItem::Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_value) property contains the HRESULT value, which can be an error or warning (success code). The [IValueMapItem::Description](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ivaluemapitem-get_description) property contains the message text associated with the error.

Typically, any errors that occur will be one of the following HRESULT values in the value map collection.

| Error | Description |
| --- | --- |
| PLA_S_PROPERTY_IGNORED | The property is not used. PLA uses this warning to disable the item in its UI so the user knows the property is being ignored. |
| PLA_E_PROPERTY_CONFLICT | The property conflicts with another property, for example, both [LogAppend](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logappend) and [LogCircular](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_logcircular) are **VARIANT_TRUE**. |

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-delete)

[IDataCollectorSet::Query](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-query)