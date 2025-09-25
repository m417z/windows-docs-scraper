# RND_ADVERTISING_SCOPE enumeration

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

Members of the
**RND_ADVERTISING_SCOPE** enumeration specify how widely a conference announcement is distributed. Values correspond to the advertising scope property on the
[ITDirectoryObjectConference](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectconference) interface.

## Constants

### `RAS_LOCAL:1`

Advertising scope is local.

### `RAS_SITE:2`

Advertising scope is site.

### `RAS_REGION:3`

Advertising scope is country or region.

### `RAS_WORLD:4`

Advertising scope is the world.

## Remarks

Mapping between scope string value, enum value, and
[time to live](https://learn.microsoft.com/windows/win32/tapi/t-tapgloss) (TTL) based on SDP Internet draft.

| Scope string value | RND_ADVERTISING_SCOPE | TTL |
| --- | --- | --- |
| Local | AS_LOCAL | 1 |
| Site | AS_SITE | 15 |
| Region | AS_REGION | 63 |
| World | AS_WORLD | 127 |

## See also

[ITDirectoryObjectConference](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobjectconference)

[get_AdvertisingScope](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectconference-get_advertisingscope)

[put_AdvertisingScope](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobjectconference-put_advertisingscope)