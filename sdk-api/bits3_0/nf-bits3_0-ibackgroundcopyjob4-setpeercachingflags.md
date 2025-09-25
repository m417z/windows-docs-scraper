# IBackgroundCopyJob4::SetPeerCachingFlags

## Description

Sets flags that determine if the files of the job can be cached and served to peers and if the job can download content from peers.

## Parameters

### `Flags` [in]

Flags that determine if the files of the job can be cached and served to peers and if the job can download content from peers. The following flags can be set:

| Value | Meaning |
| --- | --- |
| **BG_JOB_ENABLE_PEERCACHING_CLIENT**<br><br>0x0001 | The job can download content from peers.<br><br>The job will not download from a peer unless both the client computer and the job allow Background Intelligent Transfer Service (BITS) to download files from a peer. To enable the client computer to download files from a peer, set the [EnablePeerCaching](https://learn.microsoft.com/windows/desktop/Bits/group-policies) group policy or call the [IBitsPeerCacheAdministration::SetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setconfigurationflags) method and set the BG_ENABLE_PEERCACHING_CLIENT flag.<br><br>If one of the following conditions exists, BITS will stop the download and reschedule the job to begin transferring from either a peer or the origin server, depending on the value for the job and the cache:<br><br>* This value for the cache is **TRUE** and the value for the job toggles between **TRUE** and **FALSE**.<br>* This value for the job property is **TRUE** and the value for the cache toggles between **TRUE** and **FALSE**.<br><br>The download will then resume from where it left off before BITS stopped the job.**BITS 4.0:** This flag is deprecated. |
| **BG_JOB_ENABLE_PEERCACHING_SERVER**<br><br>0x0002 | The files of the job can be cached and served to peers.<br><br>BITS will not cache the files and serve them to peers unless both the client computer and job allow BITS to cache and serve the files. To allow BITS to cache and serve the files on the client computer, set the [EnablePeerCaching](https://learn.microsoft.com/windows/desktop/Bits/group-policies) group policy or call the [IBitsPeerCacheAdministration::SetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setconfigurationflags) method and set the BG_ENABLE_PEERCACHING_SERVER flag.**BITS 4.0:** This flag is deprecated. |
| **BG_JOB_DISABLE_BRANCH_CACHE**<br><br>0x0004 | BITS will not use Windows BranchCache for transfer jobs. This setting does not affect the use of Windows BranchCache by applications other than BITS. |

## Return value

The method returns the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

Setting these flags has meaning only if the peer caching has been enabled by either setting the [EnablePeerCaching](https://learn.microsoft.com/windows/desktop/Bits/group-policies) group policy or calling the [IBitsPeerCacheAdministration::SetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setconfigurationflags).

## See also

[IBackgroundCopyJob4](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyjob4)

[IBackgroundCopyJob4::GetPeerCachingFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-getpeercachingflags)

[IBitsPeerCacheAdministration::SetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-setconfigurationflags)