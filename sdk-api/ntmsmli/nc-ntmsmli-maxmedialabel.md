# MAXMEDIALABEL callback function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
*MaxMediaLabel* callback function determines the maximum size of the media label for the applications supported by the media label library.

## Parameters

### `pMaxSize` [out]

Pointer to a buffer that receives the maximum size of the buffer sent to the
[ClaimMediaLabel](https://learn.microsoft.com/windows/desktop/api/ntmsmli/nc-ntmsmli-claimmedialabel) function.

## Return value

This function returns the following value.

| Value | Meaning |
| --- | --- |
| **NO_ERROR** | The function was successful. |

## Remarks

When the media format of the media specified in the
*MaxMediaLabel* function does not have a theoretical size limit, the application should return the size of the largest media label the application can possibly generate.

## See also

[Media Label Library Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)