## Description

Sets the HTTP custom headers for this job to be write-only. Write-only headers cannot be read by BITS methods such as the [IBackgroundCopyJobHttpOptions::GetCustomHeaders method](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-getcustomheaders).

## Return value

The return value is always **S_OK**.

## Remarks

Use this API when your BITS custom headers must include security information (such as an API token) that you don't want to be readable by other programs running on the same computer. The BITS process, of course, can still read these headers, and send them over the HTTP connection. Once the headers are set to write-only, that cannot be unset.

## See also