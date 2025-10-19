# IVssProviderNotifications::OnLoad

## Description

The **OnLoad** method
notifies a provider that it was loaded.

## Parameters

### `pCallback` [in]

This parameter is reserved.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. If this is returned, the error must be described in an entry in the application event log, giving the user information on how to resolve the problem. |

## See also

[IVssProviderNotifications](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssprovidernotifications)

[OnUnload](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivssprovidernotifications-onunload)