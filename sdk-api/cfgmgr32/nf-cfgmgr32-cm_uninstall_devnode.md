# CM_Uninstall_DevNode function

## Description

The **CM_Uninstall_DevNode** function removes all persistent state associated with a device instance.

## Parameters

### `dnDevInst` [in]

Device instance handle that is bound to the local machine.

### `ulFlags` [in]

Reserved. Must be set to zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

This function uninstalls the device without sending an **IRP_MN_QUERY_REMOVE_DEVICE** request or calling class installers or co-installers. If your application will run only on a [Target Platform](https://learn.microsoft.com/windows-hardware/drivers/develop/windows-10-editions-for-universal-drivers) of Desktop, instead of calling **CM_Uninstall_DevNode**, the application should uninstall the device by calling [SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller) with the [DIF_REMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-remove) code, or by calling [DiUninstallDevice](https://learn.microsoft.com/windows/desktop/api/newdev/nf-newdev-diuninstalldevice).

Use the following sequence to call this function:

1. Check if [CM_Get_DevNode_Status](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_devnode_status) returns success. This means that the device is present.
2. If the device is present, call [CM_Query_And_Remove_SubTree](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_query_and_remove_subtreew).
3. Call **CM_Uninstall_DevNode**.

## See also

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)