# COMMCONFIG structure

## Description

Contains information about the configuration state of a communications device.

## Members

### `dwSize`

The size of the structure, in bytes. The caller must set this member to `sizeof(COMMCONFIG)`.

### `wVersion`

The version number of the structure. This parameter can be 1. The version of the provider-specific structure should be included in the **wcProviderData** member.

### `wReserved`

Reserved; do not use.

### `dcb`

The device-control block ([DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb)) structure for RS-232 serial devices. A
**DCB** structure is always present regardless of the port driver subtype specified in the device's
[COMMPROP](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commprop) structure.

### `dwProviderSubType`

The type of communications provider, and thus the format of the provider-specific data. For a list of communications provider types, see the description of the
[COMMPROP](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commprop) structure.

### `dwProviderOffset`

The offset of the provider-specific data relative to the beginning of the structure, in bytes. This member is zero if there is no provider-specific data.

### `dwProviderSize`

The size of the provider-specific data, in bytes.

### `wcProviderData`

Optional provider-specific data. This member can be of any size or can be omitted. Because the
**COMMCONFIG** structure may be expanded in the future, applications should use the **dwProviderOffset** member to determine the location of this member.

## Remarks

If the provider subtype is PST_RS232 or PST_PARALLELPORT, the **wcProviderData** member is omitted. If the provider subtype is PST_MODEM, the **wcProviderData** member contains a
[MODEMSETTINGS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemsettings) structure.

## See also

[COMMPROP](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commprop)

[DCB](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-dcb)

[GetCommProperties](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommproperties)

[MODEMSETTINGS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemsettings)