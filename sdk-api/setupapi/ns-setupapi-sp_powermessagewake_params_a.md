# SP_POWERMESSAGEWAKE_PARAMS_A structure

## Description

An SP_POWERMESSAGEWAKE_PARAMS structure corresponds to a [DIF_POWERMESSAGEWAKE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-powermessagewake) installation request.

## Members

### `ClassInstallHeader`

An install request header that contains the header size and the DIF code for the request. See [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header).

### `PowerMessageWake`

Buffer that contains a string of custom text. Windows displays this text on the power management page of the device properties display in Device Manager.

## Remarks

Windows only sends the DIF_POWERMESSAGEWAKE request if the drivers for the device support power management.

> [!NOTE]
> The setupapi.h header defines SP_POWERMESSAGEWAKE_PARAMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DIF_POWERMESSAGEWAKE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-powermessagewake)

[SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header)