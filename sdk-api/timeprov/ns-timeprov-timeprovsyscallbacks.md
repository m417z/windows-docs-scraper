# TimeProvSysCallbacks structure

## Description

Contains pointers to functions for use by the time provider.

## Members

### `dwSize`

The size of the structure, in bytes.

### `pfnGetTimeSysInfo`

A pointer to the
[GetTimeSysInfoFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-gettimesysinfofunc) function.

### `pfnLogTimeProvEvent`

A pointer to the
[LogTimeProvEventFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-logtimeproveventfunc) function.

### `pfnAlertSamplesAvail`

A pointer to the
[AlertSamplesAvailFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-alertsamplesavailfunc) function.

### `pfnSetProviderStatus`

A pointer to the
[SetProviderStatusFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-setproviderstatusfunc) function.

## See also

[AlertSamplesAvailFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-alertsamplesavailfunc)

[GetTimeSysInfoFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-gettimesysinfofunc)

[LogTimeProvEventFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-logtimeproveventfunc)

[SetProviderStatusFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-setproviderstatusfunc)

[TimeProvOpen](https://learn.microsoft.com/windows/desktop/api/timeprov/nf-timeprov-timeprovopen)