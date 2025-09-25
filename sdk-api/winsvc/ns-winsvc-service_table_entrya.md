# SERVICE_TABLE_ENTRYA structure

## Description

Specifies the
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function for a service that can run in the calling process. It is used by the
[StartServiceCtrlDispatcher](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera) function.

## Members

### `lpServiceName`

The name of a service to be run in this service process.

If the service is installed with the SERVICE_WIN32_OWN_PROCESS service type, this member is ignored, but cannot be NULL. This member can be an empty string ("").

If the service is installed with the SERVICE_WIN32_SHARE_PROCESS service type, this member specifies the name of the service that uses the
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function pointed to by the **lpServiceProc** member.

### `lpServiceProc`

A pointer to a
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function.

## See also

[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona)

[StartServiceCtrlDispatcher](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera)

## Remarks

> [!NOTE]
> The winsvc.h header defines SERVICE_TABLE_ENTRY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).