# IBitsPeerCacheAdministration::SetConfigurationFlags

## Description

Sets the configuration flags that determine if the computer can serve content to peers and can download content from peers.

## Parameters

### `Flags` [in]

Flags that determine if the computer can serve content to peers and can download content from peers. The following flags can be set:

| Value | Meaning |
| --- | --- |
| **BG_ENABLE_PEERCACHING_CLIENT**<br><br>0x0001 | The computer can download content from peers.<br><br>BITS will not download files from a peer unless both the client computer and the job permit BITS to download files from a peer. To permits the job to download files from a peer, call the [IBackgroundCopyJob4::SetPeerCachingFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-setpeercachingflags) method and set the BG_JOB_ENABLE_PEERCACHING_CLIENT flag.<br><br>Note that changing this value can affect all jobs on the computer. If one of the following conditions exists, BITS will stop the download and reschedule the job to begin transferring from either a peer or the origin server, depending on the value for the job and the cache:<br><br>* This value for the cache is **TRUE** and the value for the job toggles between **TRUE** and **FALSE**.<br>* This value for the job property is **TRUE** and the value for the cache toggles between **TRUE** and **FALSE**.<br><br>The download will then resume from where it left off before BITS stopped the job. |
| **BG_ENABLE_PEERCACHING_SERVER**<br><br>0x0002 | The computer can serve content to peers.<br><br>BITS will not cache the files and serve them to peers unless both the client computer and job permit BITS to cache and serve files. To permit the job to cache files for a job, call the [IBackgroundCopyJob4::SetPeerCachingFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-setpeercachingflags) method and set the BG_JOB_ENABLE_PEERCACHING_SERVER flag. |

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **BG_S_OVERRIDDEN_BY_POLICY** | The configuration preference has been saved successfully, but the preference will not be used because a configured Group Policy setting overrides the preference. <br><br>The method returns this value if the value set is different from the group policy value. If the values are the same, the method returns S_OK. |

## Remarks

This value is used only if the EnablePeerCaching group policy is not set.

A job determines if it downloads content from a peer or serves its content to peers. For details, see the [IBackgroundCopyJob4::SetPeerCachingFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-setpeercachingflags) method.

## See also

[IBackgroundCopyJob4::SetPeerCachingFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyjob4-setpeercachingflags)

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::GetConfigurationFlags](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-getconfigurationflags)