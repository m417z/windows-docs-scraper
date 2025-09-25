# IBackgroundCopyJob4::GetPeerCachingFlags

## Description

Retrieves flags that determine if the files of the job can be cached and served to peers and if BITS can download content for the job from peers.

## Parameters

### `pFlags` [out]

Flags that determine if the files of the job can be cached and served to peers and if BITS can download content for the job from peers. The following flags can be set:

| Value | Meaning |
| --- | --- |
| **BG_JOB_ENABLE_PEERCACHING_CLIENT**<br><br>0x0001 | The job can download content from peers. |
| **BG_JOB_ENABLE_PEERCACHING_SERVER**<br><br>0x0002 | The files of the job can be cached and served to peers. |

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_NOTIMPL** | If other flag values are set. |

## Remarks

BITS can download from peers only if peercaching is enabled both at the computer level and at the job level; this API affects only the job level. For details, see [IBackgroundCopyJob4::SetPeerCachingFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-setpeercachingflags).

## See also

[Group Policies](https://learn.microsoft.com/windows/desktop/Bits/group-policies)

[IBackgroundCopyJob4](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyjob4)

[IBackgroundCopyJob4::SetPeerCachingFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-setpeercachingflags)

[IBitsPeerCacheAdministration::GetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-getconfigurationflags)

[IBitsPeerCacheAdministration::SetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setconfigurationflags)