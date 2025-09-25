# CmGetCallbackVersion function

## Description

The **CmGetCallbackVersion** routine retrieves the major and minor version numbers for the current version of the configuration manager's registry callback feature.

## Parameters

### `Major` [out, optional]

A pointer to a location that receives the major version number.

### `Minor` [out, optional]

A pointer to a location that receives the minor version number.

## Remarks

The **CmGetCallbackVersion** routine is available starting with Windows Vista.

For Windows Vista, the major version number is 1 and the minor version number is 0.

Starting with Windows 7, the major version number is 1 and the minor version number is 1.

Version 1.1 contains two changes from version 1.0.

First, in version 1.0, if multiple registry filter drivers are active on the computer at the same time, the **REG_POST_*XXX*_KEY_INFORMATION** structure passed to a driver's registry callback routine during the post-notification phase for a create-key or open-key operation might contain a non-NULL **Object** member, even though the operation failed and the **Status** member contains an error status. In version 1.1, the **Object** member is always NULL if the **Status** member is set to an error status value to indicate that the operation failed.

Second, in version 1.0, an uncaught exception in a registry callback routine is quietly accepted by the operating system. In version 1.1, this exception causes the computer to bug check.

For more information on the differences between versions, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[REG_POST_CREATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_create_key_information)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)