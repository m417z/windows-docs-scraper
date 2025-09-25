# MFShutdown function

## Description

Shuts down the Microsoft Media Foundation platform. Call this function once for every call to [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup). Do not call this function from work queue threads.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**MFShutdown** should be called during should be called during app uninitialization and not from static destructors during process exit.

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Initializing Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/initializing-media-foundation)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)