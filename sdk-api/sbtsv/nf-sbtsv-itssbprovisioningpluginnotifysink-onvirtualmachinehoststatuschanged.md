# ITsSbProvisioningPluginNotifySink::OnVirtualMachineHostStatusChanged

## Description

Notifies Remote Desktop Connection Broker (RD Connection Broker) that the status of the host of a virtual machine is changed.

## Parameters

### `VmHost` [in]

The name of the host.

### `VmHostNotifyStatus` [in]

The new status of the host.

### `ErrorCode` [in]

A standard **HRESULT** error code describing the reason for the status change.

### `ErrorDescr` [in]

A text description of the reason for the change.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbProvisioningPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovisioningpluginnotifysink)