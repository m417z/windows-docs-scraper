# ITpmVirtualSmartCardManagerStatusCallback::ReportProgress

## Description

Reports the progress of the current operation.

## Parameters

### `Status` [in]

Status code of the current operation from the possible status states listed in the [TPMVSCMGR_STATUS](https://learn.microsoft.com/windows/win32/api/tpmvscmgr/ne-tpmvscmgr-tpmvscmgr_status) enumeration.

## Return value

If the method succeeds, it returns **S_OK**.

If the method fails, it returns a Win32 error code. The requested operation on the TPM virtual smart card manager server may be interrupted.

## See also

[ITpmVirtualSmartCardManagerStatusCallback](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nn-tpmvscmgr-itpmvirtualsmartcardmanagerstatuscallback)