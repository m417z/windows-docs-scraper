# ITsSbProvisioning::PatchVirtualMachines

## Description

Patches a virtual machine asynchronously.

## Parameters

### `JobXmlString` [in]

Defines the job.

### `JobGuid` [in]

A **GUID** that identifies the job.

### `pSink` [in]

The [ITsSbProvisioningPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovisioningpluginnotifysink) object that notifies the RD Connection Broker about the job.

### `pVMPatchInfo` [in, optional]

Patch information.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbProvisioning](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovisioning)