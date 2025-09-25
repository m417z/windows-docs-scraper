## Description

This function returns the set of XState features that are currently enabled for the current thread.

## Return value

The return value is a bitmask in which each bit represents an XState feature that is currently enabled for the current thread.

## Remarks

This function is related to [GetEnabledXStateFeatures](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getenabledxstatefeatures), which returns the set of XState features enabled in the system.
Prior to the introduction of optional XState features, the set of enabled XState features is the same for every thread in the system because all supported features are always enabled, thus the result returned from GetEnabledXStateFeatures and this function are identical.
With optional XState features, it is possible for optional XState features to be disabled by default for newly created threads and enabled on demand later. Optional XState features that are currently disabled for the current thread will not be returned by this function, but will still be returned by GetEnabledXStateFeatures.

## See also

[GetEnabledXStateFeatures](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getenabledxstatefeatures)

[EnableProcessOptionalXStateFeatures](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enableprocessoptionalxstatefeatures)