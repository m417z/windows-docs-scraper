# WSMAN_PLUGIN_AUTHORIZE_OPERATION callback function

## Description

Authorizes a specific operation.

The DLL entry point name for this method must be **WSManPluginAuthzOperation**.

## Parameters

### `pluginContext` [in]

Specifies the context that was returned by a call to [WSManPluginStartup](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_startup). This parameter represents a specific application initialization of a WinRM plug-in.

### `senderDetails` [in]

A pointer to the [WSMAN_SENDER_DETAILS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_sender_details) structure that specifies the identification information of the user.

### `flags` [in]

Reserved for future use. Must be set to zero.

### `operation` [in]

Represents the operation that is being performed. This parameter can be one of the following values:

#### Get

WSManOperationGet

#### Put

WSManOperationPut

#### Create

WSManOperationCreate

#### Delete

WSManOperationDelete

#### Enumerate

WSManOperationEnumerate

#### Subscribe

WSManOperationSubscribe

#### Shell

WSManOperationShell

#### Command

WSManOperationCommand

#### Invoke

WSManOperationInvoke

### `action` [in]

Specifies the action of the request received. This parameter can be one of the following values:

#### Get

`http://schemas.xmlsoap.org/ws/2004/09/transfer/Get`

#### Put

`http://schemas.xmlsoap.org/ws/2004/09/transfer/Put`

#### Create

`http://schemas.xmlsoap.org/ws/2004/09/transfer/Create`

**Note** Shell creation will appear as Create.

#### Delete

`http://schemas.xmlsoap.org/ws/2004/09/transfer/Delete`

#### Enumerate

`http://schemas.xmlsoap.org/ws/2004/09/enumeration/Enumerate`

#### Subscribe

`http://schemas.xmlsoap.org/ws/2004/08/eventing/Subscribe`

#### Command

`http://schemas.microsoft.com/wbem/wsman/1/windows/shell/Command`

#### Invoke

This operation will have a custom string.

### `resourceUri` [in]

Specifies the [resource URI](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) of the inbound operation.

## Remarks

The plug-in must call [WSManPluginAuthzOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginauthzoperationcomplete) to report either that the user was successfully authorized to perform the operation with **NO_ERROR** or that the user was not authorized with **ERROR_ACCESS_DENIED**. All other errors report a failure to the client, but no specific information is reported.