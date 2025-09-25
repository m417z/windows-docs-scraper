# SP_TROUBLESHOOTER_PARAMS_W structure

## Description

An SP_TROUBLESHOOTER_PARAMS structure corresponds to a [DIF_TROUBLESHOOTER](https://learn.microsoft.com/windows-hardware/drivers/install/dif-troubleshooter) installation request.

## Members

### `ClassInstallHeader`

An install request header that contains the header size and the DIF code for the request. See [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header).

### `ChmFile`

Optionally specifies a string buffer that contains the path of a CHM file. The CHM file contains HTML help topics with troubleshooting information. The path must be fully qualified if the file is not in default system help directory (%SystemRoot%\help).

### `HtmlTroubleShooter`

Optionally specifies a string buffer that contains the path of a topic in the **ChmFile**. This parameter identifies the page of the **ChmFile** that Windows should display first.

## Remarks

An installer fills in this structure in response to a DIF_TROUBLESHOOTER request.

> [!NOTE]
> The setupapi.h header defines SP_TROUBLESHOOTER_PARAMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DIF_TROUBLESHOOTER](https://learn.microsoft.com/windows-hardware/drivers/install/dif-troubleshooter)

[SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)