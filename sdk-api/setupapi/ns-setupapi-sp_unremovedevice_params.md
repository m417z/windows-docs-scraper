# SP_UNREMOVEDEVICE_PARAMS structure

## Description

An SP_UNREMOVEDEVICE_PARAMS structure corresponds to a DIF_UNREMOVE installation request.

## Members

### `ClassInstallHeader`

An install request header that contains the header size and the DIF code for the request. See [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header).

### `Scope`

A flag that indicates the scope of the unremove operation. This flag must always be set to DI_UNREMOVEDEVICE_CONFIGSPECIFIC.

### `HwProfile`

The hardware profile ID for profile-specific changes. Zero specifies the current hardware profile.

## See also

[DIF_UNREMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-unremove)

[SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiUnremoveDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiunremovedevice)