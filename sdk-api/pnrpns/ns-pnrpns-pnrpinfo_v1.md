# PNRPINFO_V1 structure

## Description

The **PNRPINFO_V1** structure is pointed to by the **lpBlob** member of the [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/P2PSdk/winsock-nsp-reference-links) structure.

## Members

### `dwSize`

Specifies the size of this structure.

### `lpwszIdentity`

Points to the Unicode string that contains the identity.

### `nMaxResolve`

Specifies the requested number of resolutions.

### `dwTimeout`

Specifies the time, in seconds, to wait for a response.

### `dwLifetime`

Specifies the number of seconds between refresh operations. Must be 86400 (24 * 60 * 60 seconds).

### `enResolveCriteria`

Specifies the criteria used to resolve matches. PNRP can look for the first matching name, or attempt to find a name that is numerically close to the service location. Valid values are specified by [PNRP_RESOLVE_CRITERIA](https://learn.microsoft.com/windows/desktop/api/pnrpdef/ne-pnrpdef-pnrp_resolve_criteria).

### `dwFlags`

Specifies the flags to use for the resolve operation. The valid value is:

| Value | Description |
| --- | --- |
| PNRPINFO_HINT | Indicates that the **saHint** member is used. The hint influences how the service location portion of the PNRP ID is generated; it also influences how names are resolved, and specifies how to select between multiple peer names. |

### `saHint`

Specifies the IPv6 address to use for the location. The **dwFlags** member must be PNRPINFO_HINT.

### `enNameState`

Specifies the state of the registered ID. This value is reserved and must be set to zero (0).

## Remarks

 Starting with Windows Vista, please use the [PNRPINFO_V2](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa371671(v=vs.85)) structure.

## See also

[PNRP and
BLOB](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-blob)

[PNRP and
WSAQUERYSET](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-wsaqueryset)

[PNRPINFO_V2](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa371671(v=vs.85))

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/P2PSdk/winsock-nsp-reference-links)