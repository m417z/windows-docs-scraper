# FAX_TIME structure

## Description

The **FAX_TIME** structure represents a time, using individual members for the current hour and minute. The time is expressed in Coordinated Universal Time (UTC).

## Members

### `Hour`

Type: **WORD**

Specifies a 16-bit unsigned integer that is the current hour. Valid values are 0 through 23.

### `Minute`

Type: **WORD**

Specifies a 16-bit unsigned integer that is the current minute. Valid values are 0 through 59.

## Remarks

The [FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa) structure includes a **FAX_TIME** structure to describe the discount period that applies when a fax server is sending fax transmissions.

## See also

[FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa)

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxGetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetconfigurationa)

[FaxSetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetconfigurationa)