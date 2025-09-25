# SP_CLASSINSTALL_HEADER structure

## Description

An SP_CLASSINSTALL_HEADER is the first member of any class install parameters structure. It contains the device installation request code that defines the format of the rest of the install parameters structure.

## Members

### `cbSize`

The size, in bytes, of the SP_CLASSINSTALL_HEADER structure.

### `InstallFunction`

The device installation request (DIF code) for the class install parameters structure.

DIF codes have the format DIF_*XXX* and are defined in *Setupapi.h*. See [Device Installation Function Codes](https://learn.microsoft.com/windows-hardware/drivers/install/handling-dif-codes) for a complete description of DIF codes.

## Remarks

When a component allocates a class install parameters structure, it typically initializes the header fields of the structure. Such a component sets the **InstallFunction** member to the DIF code for the installation request and sets **cbSize** to the size of the SP_CLASSINSTALL_HEADER structure. For example:

```
SP_REMOVEDEVICE_PARAMS RemoveDeviceParams;
RemoveDeviceParams.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
RemoveDeviceParams.ClassInstallHeader.InstallFunction = DIF_REMOVE;
```

A component must set the **InstallFunction** member before passing a class install parameters structure to [SetupDiSetClassInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassinstallparamsa).

However, a component does not have to set this field when passing class install parameters to [SetupDiGetClassInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassinstallparamsa). This function sets the **InstallFunction** member in the structure it passes back to the caller. It sets **InstallFunction** to the DIF_*XXX* code for the currently active device installation request.

## See also

[SP_DETECTDEVICE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_detectdevice_params)

[SP_MOVEDEV_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/install/sp-movedev-params)

[SP_NEWDEVICEWIZARD_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_newdevicewizard_data)

[SP_POWERMESSAGEWAKE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_powermessagewake_params_a)

[SP_PROPCHANGE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_propchange_params)

[SP_REMOVEDEVICE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_removedevice_params)

[SP_SELECTDEVICE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_selectdevice_params_a)

[SP_TROUBLESHOOTER_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_troubleshooter_params_a)

[SP_UNREMOVEDEVICE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_unremovedevice_params)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiGetClassInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassinstallparamsa)

[SetupDiSetClassInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassinstallparamsa)