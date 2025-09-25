# SP_SELECTDEVICE_PARAMS_W structure

## Description

An SP_SELECTDEVICE_PARAMS structure corresponds to a [DIF_SELECTDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-selectdevice) installation request.

## Members

### `ClassInstallHeader`

An install request header that contains the header size and the DIF code for the request. See [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header).

### `Title`

Buffer that contains an installer-provided window title for driver-selection windows. Windows uses this title for the window title for the Select Device dialogs.

### `Instructions`

Buffer that contains an installer-provided select-device instructions.

### `ListLabel`

Buffer that contains an installer-provided label for the list of drivers from which the user can select.

### `SubTitle`

Buffer that contains an installer-provided subtitle used in select-device wizards. This string is not used in select dialogs.

#### - Reserved

Reserved. For internal use only.

## Remarks

If an installer sets fields in this structure to be used during driver selection, the installer must also set the DI_USECI_SELECTSTRINGS flag in the SP_DEVINSTALL_PARAMS.

The following screen shot shows a sample Select Device dialog box and identifies the strings an installer can supply.

![Screen shot of a Select a Device Driver dialog box](https://learn.microsoft.com/windows/win32/api/setupapi/images/select-dialog.png)

> [!NOTE]
> The setupapi.h header defines SP_SELECTDEVICE_PARAMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DIF_SELECTDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-selectdevice)

[SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiSelectDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiselectdevice)