# WSMAN_PLUGIN_REQUEST structure

## Description

Specifies information for a plug-in request. A pointer to a **WSMAN_PLUGIN_REQUEST** structure is passed to all operation
entry points within the plug-in. All result notification methods use this
pointer to match the result with the request. All information in the structure will stay valid until the plug-in calls [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) on the operation.

## Members

### `senderDetails`

A pointer to a [WSMAN_SENDER_DETAILS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_sender_details) structure that specifies details about the client that initiated the request.

### `locale`

Specifies the locale that the user requested results to be in. If the requested locale is not available, the following options are available:

* The system locale is used.
* The request is rejected with an invalid locale error.

Any call into the plug-in will have the locale on the thread set to the locale that is specified in this member. If the plug-in has other threads working on the request, the plug-in will need to set the locale accordingly on each thread that it uses.

### `resourceUri`

Specifies the [resource URI](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) for this operation.

### `operationInfo`

A pointer to a [WSMAN_OPERATION_INFO](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_operation_info) structure that contains extra information about the operation. Some of the information in this structure will be **NULL** because not all of the parameters are relevant to all operations.

### `shutdownNotification`

If the operation is canceled, the **shutdownNotification** member is set to **TRUE**.

### `shutdownNotificationHandle`

If the operation is canceled, **shutdownNotification** is signaled.

### `dataLocale`

## Remarks

Operations must signal the callback for the operation to indicate it has been shut down. Operations are canceled in a hierarchical way to ensure that all follow-on operations are canceled before the top-level operations. A plug-in has two ways of handling the cancellation of an operation. First, the plug-in can check the **shutdownNotification** Boolean value
if it iterates through a set of results. Second, if the plug-in is more
asynchronous in nature, the **shutdownNotificationHandle** can be used when queuing asynchronous notification threads.