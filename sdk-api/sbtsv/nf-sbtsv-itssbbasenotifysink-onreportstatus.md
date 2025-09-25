# ITsSbBaseNotifySink::OnReportStatus

## Description

Sends status messages to the Remote Desktop Connection (RDC) client regarding the processing of a client
connection.

## Parameters

### `messageType` [in]

The message type. This parameter must be one of the following values.

#### CLIENT_MESSAGE_CONNECTION_STATUS

A status message.

#### CLIENT_MESSAGE_CONNECTION_ERROR

An error message.

### `messageID` [in]

The message ID. This parameter must be one of the following values.

#### TS_STATUS_VM_LOADING

The virtual machine is loading.

#### TS_STATUS_VM_WAKING

The virtual machine is waking.

#### TS_STATUS_VM_BOOTING

The virtual machine is starting.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method allows plug-ins to send more specific status and error messages to the RDC client, overriding the
default status and error messages that Remote Desktop Connection Broker (RD Connection Broker) sends to the client.

The following error codes are defined by RD Connection Broker for use by plug-ins.

## See also

[ITsSbBaseNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbbasenotifysink)