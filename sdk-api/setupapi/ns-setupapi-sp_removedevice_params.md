# SP_REMOVEDEVICE_PARAMS structure

## Description

An SP_REMOVEDEVICE_PARAMS structure corresponds to the [DIF_REMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-remove) installation request.

## Members

### `ClassInstallHeader`

An install request header that contains the header size and the DIF code for the request. See [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header).

### `Scope`

Flags that indicate the scope of the device removal. Can be one of the following values:

#### DI_REMOVEDEVICE_GLOBAL

Make this change in all hardware profiles. Remove information about the device from the registry.

#### DI_REMOVEDEVICE_CONFIGSPECIFIC

Make this change to only the hardware profile specified by **HwProfile**. this flag only applies to root-enumerated devices. When Windows removes the device from the last hardware profile in which it was configured, Windows performs a global removal.

### `HwProfile`

The hardware profile ID for profile-specific changes. Zero specifies the current hardware profile.

## See also

[DIF_REMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-remove)

[SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiRemoveDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiremovedevice)