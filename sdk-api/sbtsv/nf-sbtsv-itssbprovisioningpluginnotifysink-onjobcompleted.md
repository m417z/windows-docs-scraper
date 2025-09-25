# ITsSbProvisioningPluginNotifySink::OnJobCompleted

## Description

Notifies Remote Desktop Connection Broker (RD Connection Broker) that the job is complete.

## Parameters

### `ResultCode` [in]

The **HRESULT** returned by the job.

### `ResultDescription` [in]

A text description of the *ResultCode*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbProvisioningPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovisioningpluginnotifysink)