# WTS_SERVER_INFOA structure

## Description

Contains information about a specific Remote Desktop Services server.

## Members

### `pServerName`

Name of the server.

## See also

[WTSEnumerateServers](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumerateserversa)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTS_SERVER_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).