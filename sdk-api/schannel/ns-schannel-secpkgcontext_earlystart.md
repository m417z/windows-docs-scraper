# SecPkgContext_EarlyStart structure

## Description

The **SecPkgContext_EarlyStart** structure contains information about whether to attempt to use the False Start feature in a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

See the [Building a faster and more secure web](https://learn.microsoft.com/windows/desktop/winmsg/windows) blog post for information on this feature.

## Members

### `dwEarlyStartFlags`

Determines whether to attempt client-side False Start. Set the value to **ENABLE_TLS_CLIENT_EARLY_START** (1) to use False Start.