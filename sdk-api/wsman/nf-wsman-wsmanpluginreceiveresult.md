# WSManPluginReceiveResult function

## Description

Reports results for the [WSMAN_PLUGIN_RECEIVE](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_receive) plug-in call and is used by most shell plug-ins that return results. After all of the data is received,
the [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) method must be called.

## Parameters

### `requestDetails` [in]

A pointer to a [WSMAN_PLUGIN_REQUEST](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_plugin_request) structure that specifies the resource URI, options, locale, shutdown flag, and handle for the request.

### `flags` [in]

Reserved for future use. Must be set to zero.

### `stream` [in, optional]

Specifies the stream that the data is associated with. Any stream can be used, but the standard streams are STDIN, STDOUT, and STDERR.

### `streamResult` [in, optional]

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that specifies the result object that is returned to the client. The result can be in either binary or XML format.

### `commandState` [in, optional]

Specifies the state of the command. This parameter must be set either to one of the following values or to a value defined by the plug-in.

#### WSMAN_RECEIVE_STATE_NONE

The operation requires no action.

#### WSMAN_RECEIVE_STATE_NORMAL_TERMINATION

The operation was terminated normally.

#### WSMAN_RECEIVE_STATE_ABNORMAL_TERMINATION

The operation was terminated unexpectedly.

#### WSMAN_RECEIVE_STATE_WAITING

The operation is waiting for input.

#### WSMAN_RECEIVE_STATE_INPUT_REQUIRED

The operation requires command-line input.

### `exitCode` [in]

Ignored in all cases except when *commandState* is either **WSMAN_RECEIVE_STATE_NORMAL_TERMINATION** or **WSMAN_RECEIVE_STATE_ABNORMAL_TERMINATION**. Each result can have separate error codes. If the command or stream has failed, the plug-in must call the [WSManPluginOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanpluginoperationcomplete) method.