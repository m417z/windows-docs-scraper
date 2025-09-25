# BG_JOB_PROXY_USAGE enumeration

## Description

Defines constants that specify which proxy to use for file transfers. You can define different proxy settings for each job.

## Constants

### `BG_JOB_PROXY_USAGE_PRECONFIG:0`

Use the proxy and proxy bypass list settings defined by each user to transfer files. Settings are user-defined from Control Panel, Internet Options, Connections, Local Area Network (LAN) settings (or Dial-up settings, depending on the network connection).

### `BG_JOB_PROXY_USAGE_NO_PROXY`

Do not use a proxy to transfer files. Use this option when you transfer files within a LAN.

### `BG_JOB_PROXY_USAGE_OVERRIDE`

Use the application's proxy and proxy bypass list to transfer files. Use this option when you can't trust that the system settings are correct. Also use this option when you want to transfer files using a special account, such as LocalSystem, to which the system settings do not apply.

### `BG_JOB_PROXY_USAGE_AUTODETECT`

Automatically detect proxy settings. BITS detects proxy settings for each file in the job.

**BITS 1.5 and earlier:** **BG_JOB_PROXY_USAGE_AUTODETECT** is not available.

## See also

* [IBackgroundCopyJob::GetProxySettings method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getproxysettings)
* [IBackgroundCopyJob::SetProxySettings method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setproxysettings)