# SP_PROPCHANGE_PARAMS structure

## Description

An SP_PROPCHANGE_PARAMS structure corresponds to a [DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange) installation request.

## Members

### `ClassInstallHeader`

An install request header that contains the header size and the DIF code for the request. See [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header).

### `StateChange`

State change action. Can be one of the following values:

#### DICS_ENABLE

The device is being enabled.

For this state change, Windows enables the device if the **DICS_FLAG_GLOBAL** flag is specified.

If the **DICS_FLAG_CONFIGSPECIFIC** flag is specified and the current hardware profile is specified then Windows enables the device. If the **DICS_FLAG_CONFIGSPECIFIC** is specified and not the current hardware profile then Windows sets some flags in the registry and does not change the device's state. Windows will change the device state when the specified profile becomes the current profile.

#### DICS_DISABLE

The device is being disabled.

For this state change, Windows disables the device if the **DICS_FLAG_GLOBAL** flag is specified.

If the **DICS_FLAG_CONFIGSPECIFIC** flag is specified and the current hardware profile is specified then Windows disables the device. If the **DICS_FLAG_CONFIGSPECIFIC** is specified and not the current hardware profile then Windows sets some flags in the registry and does not change the device's state.

#### DICS_PROPCHANGE

The properties of the device have changed.

For this state change, Windows ignores the **Scope** information as long it is a valid value, and stops and restarts the device.

#### DICS_START

The device is being started (if the request is for the currently active hardware profile).

**DICS_START** must be **DICS_FLAG_CONFIGSPECIFIC**. You cannot perform that change globally.

Windows only starts the device if the current hardware profile is specified. Otherwise, Windows sets a registry flag and does not change the state of the device.

#### DICS_STOP

The device is being stopped. The driver stack will be unloaded and the CSCONFIGFLAG_DO_NOT_START flag will be set for the device.

**DICS_STOP** must be **DICS_FLAG_CONFIGSPECIFIC**. You cannot perform that change globally.

Windows only stops the device if the current hardware profile is specified. Otherwise, Windows sets a registry flag and does not change the state of the device.

Components should not specify DICS_STOP or DICS_START. Instead, they should use DICS_PROPCHANGE to stop and restart a device to cause changes in the device's configuration to take effect.

### `Scope`

Flags that specify the scope of a device property change. Can be one of the following:

#### DICS_FLAG_GLOBAL

Make the change in all hardware profiles.

#### DICS_FLAG_CONFIGSPECIFIC

Make the change in the specified profile only.

The following flag is obsolete:

#### DICS_FLAG_CONFIGGENERAL

### `HwProfile`

Supplies the hardware profile ID for profile-specific changes. Zero specifies the current hardware profile.

## See also

[DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange)

[SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiChangeState](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdichangestate)