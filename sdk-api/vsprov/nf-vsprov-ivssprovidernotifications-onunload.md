# IVssProviderNotifications::OnUnload

## Description

The **OnUnload** method
notifies the provider to prepare to be unloaded.

## Parameters

### `bForceUnload` [in]

If **TRUE**, the provider must prepare to be released.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| ****S_OK****<br><br>0x00000000L | There are no pending operations and the provider is ready to be released. |
| **S_FALSE**<br><br>0x00000001L | The provider should not be unloaded. This value can only be returned if *bForceUnload* is **FALSE**. |

## Remarks

If *bForceUnload* is **TRUE**, the return value must be
**S_OK**.

## See also

[IVssProviderNotifications](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssprovidernotifications)

[OnLoad](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivssprovidernotifications-onload)