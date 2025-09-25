# ITpmVirtualSmartCardManager::DestroyVirtualSmartCard

## Description

Destroys the TPM virtual smart card that has the given instance ID.

## Parameters

### `pszInstanceId` [in]

Instance identifier of the TPM virtual smart card that is returned from a successful [CreateVirtualSmartCard](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nf-tpmvscmgr-itpmvirtualsmartcardmanager-createvirtualsmartcard) method call.

### `pStatusCallback` [in, optional]

Pointer to a [ITpmVirtualSmartCardManagerStatusCallback](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nn-tpmvscmgr-itpmvirtualsmartcardmanagerstatuscallback) interface. The TPM virtual smart card manager uses this callback interface to communicate the progress and errors during creation of the virtual smart card. If the *pStatusCallback* parameter is **NULL**, no progress is reported to the client before the operation completes.

### `pfNeedReboot` [out]

Pointer to a Boolean value to receive whether the requested operation needs to reboot the client computer.

## Return value

If the method succeeds, it returns **S_OK**.

If the method fails, it returns a Win32 error code.

## See also

[ITpmVirtualSmartCardManager](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nn-tpmvscmgr-itpmvirtualsmartcardmanager)