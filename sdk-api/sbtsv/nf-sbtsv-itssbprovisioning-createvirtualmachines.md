# ITsSbProvisioning::CreateVirtualMachines

## Description

Creates a virtual machine asynchronously.

## Parameters

### `JobXmlString` [in]

Defines the job.

### `JobGuid` [in]

A **GUID** that identifies the job.

### `pSink` [in]

The [ITsSbProvisioningPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovisioningpluginnotifysink) object that notifies the RD Connection Broker about the job.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CancelJob](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbprovisioning-canceljob)

[ITsSbProvisioning](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovisioning)