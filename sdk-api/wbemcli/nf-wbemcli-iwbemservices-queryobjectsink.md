# IWbemServices::QueryObjectSink

## Description

The **IWbemServices::QueryObjectSink** method
allows the caller to obtain a notification handler that is exported by Windows Management. This allows the caller
to write notifications and events directly to Windows Management. The caller should only write extrinsic events to
Windows Management. For more information, see
[Determining the Type of Event to Receive](https://learn.microsoft.com/windows/desktop/WmiSdk/determining-the-type-of-event-to-receive).

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0.

### `ppResponseHandler` [out]

Receives the interface pointer to the notification handler. This is set to point to **NULL** when there is an error. The returned pointer has a positive reference count, and the caller must call **IWbemServices::Release** on the pointer when it is no longer needed. A **NULL** value can be returned if no notification handler is available. This is not an error.

**Note** The value of the *ppResponseHandler* parameter cannot be **NULL** when it is passed to this method.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

**Note** Firing events using **QueryObjectSink**
is permitted by default for Administrators only. Extending the permission to other users requires giving them
**WBEM_FULL_WRITE** permission.

## See also

[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[Querying WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/querying-wmi)