# SP_DETECTDEVICE_PARAMS structure

## Description

An SP_DETECTDEVICE_PARAMS structure corresponds to a DIF_DETECT installation request.

## Members

### `ClassInstallHeader`

An install request header that contains the size of the header and the DIF code for the request. See [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header).

### `DetectProgressNotify`

A callback routine that displays a progress bar for the device detection operation. The callback routine is supplied by the [device installation component](https://learn.microsoft.com/windows-hardware/drivers/install/system-provided-device-installation-components) that sends the [DIF_DETECT](https://learn.microsoft.com/windows-hardware/drivers/install/dif-detect) request. The callback has the following prototype:

```
typedef BOOL (CALLBACK* PDETECT_PROGRESS_NOTIFY)(
    IN PVOID ProgressNotifyParam,
    IN DWORD DetectComplete
    );
```

*ProgressNotifyParam* is an opaque "handle" that identifies the detection operation. This value is supplied by the [device installation component](https://learn.microsoft.com/windows-hardware/drivers/install/system-provided-device-installation-components) that sent the DIF_DETECT request.

*DetectComplete* is a value between 0 and 100 that indicates the percent completion. The class installer increments this value at various stages of its detection activities, to notify the user of its progress.

### `ProgressNotifyParam`

The opaque **ProgressNotifyParam** "handle" that the class installer passes to the progress callback routine.

## See also

[DIF_DETECT](https://learn.microsoft.com/windows-hardware/drivers/install/dif-detect)

[SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)