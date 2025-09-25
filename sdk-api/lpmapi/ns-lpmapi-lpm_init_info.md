# LPM_INIT_INFO structure

## Description

The
**LPM_INIT_INFO** structure contains local policy module initialization information.

## Members

### `PcmVersionNumber`

Version of the policy control module

### `ResultTimeLimit`

Time limit, in seconds, that the policy control module waits to receive results before timing out.

### `ConfiguredLpmCount`

Number of configured local policy modules.

### `AllocMemory`

Memory allocation function used to initialize memory for local policy modules, in the form of a [PALLOCMEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-pallocmem) function.

### `FreeMemory`

Memory freeing function used to free memory allocated for the local policy module. See [PFREEMEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-pfreemem) for more information.

### `PcmAdmitResultCallback`

Callback function used to admit results. See [cbAdmitResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbadmitresult) for more information.

### `GetRsvpObjectsCallback`

Callback function used to obtain RSVP objects. See [cbGetRsvpObjects](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbgetrsvpobjects) for more information.

## See also

[PALLOCMEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-pallocmem)

[PFREEMEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-pfreemem)

[cbAdmitResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbadmitresult)

[cbGetRsvpObjects](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbgetrsvpobjects)