# IFsrmAccessDeniedRemediationClient::Show

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAdr](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmadr) and
[MSFT_FSRMADRSettings](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmadrsettings) classes.]

Displays the Access Denied Remediation (ADR) client dialog.

This method was introduced for applications that are already using the FSRM interfaces. Where possible it is
recommended to use the [MSFT_FSRMAdr](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmadr) and
[MSFT_FSRMADRSettings](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmadrsettings) WMI classes instead.

## Parameters

### `parentWnd` [in]

Handle to the window that will be the parent of the dialog that will be displayed.

### `accessPath` [in]

Path of the file being accessed.

### `errorType` [in]

The client error type as enumerated by the
[AdrClientErrorType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-adrclienterrortype) enumeration.

### `flags` [in]

Reserved. Set to 0.

### `windowTitle` [in]

Optional text to display as the title of the dialog window that is opened.

### `windowMessage` [in]

Optional text to display above the instructions in the dialog window that is opened.

### `result` [out, retval]

Address of a value that will receive a **HRESULT** containing the result of the
operation.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFsrmAccessDeniedRemediationClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaccessdeniedremediationclient)

[MSFT_FSRMADRSettings](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmadrsettings)

[MSFT_FSRMAdr](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmadr)