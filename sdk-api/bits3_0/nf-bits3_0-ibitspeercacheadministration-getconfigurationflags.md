# IBitsPeerCacheAdministration::GetConfigurationFlags

## Description

Gets the configuration flags that determine if the computer serves content to peers and can download content from peers.

## Parameters

### `pFlags` [out]

Flags that determine if the computer serves content to peers and can download content from peers. The following flags can be set:

| Value | Meaning |
| --- | --- |
| **BG_ENABLE_PEERCACHING_CLIENT**<br><br>0x0001 | The computer can download content from peers. |
| **BG_ENABLE_PEERCACHING_SERVER**<br><br>0x0002 | The computer can serve content to peers. |

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

BITS can download from peers only if peercaching is enabled both at the computer level and at the job level; this API affects only the computer level. For details, see [IBitsPeerCacheAdministration::SetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setconfigurationflags).

Peer caching could have been enabled by Group Policy or by calling the [IBitsPeerCacheAdministration::SetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setconfigurationflags) method.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::SetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setconfigurationflags)