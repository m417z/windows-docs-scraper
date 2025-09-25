# ITpmVirtualSmartCardManagerStatusCallback::ReportError

## Description

Reports any errors from the requested operation.

## Parameters

### `Error` [in]

Error code of the current error from the possible errors listed in the [TPMVSCMGR_ERROR](https://learn.microsoft.com/windows/win32/api/tpmvscmgr/ne-tpmvscmgr-tpmvscmgr_error) enumeration.

## Return value

If the method succeeds, it returns **S_OK**.

If the method fails, it returns a Win32 error code. The requested operation on the TPM virtual smart card manager server may be interrupted.

## See also

[ITpmVirtualSmartCardManagerStatusCallback](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nn-tpmvscmgr-itpmvirtualsmartcardmanagerstatuscallback)