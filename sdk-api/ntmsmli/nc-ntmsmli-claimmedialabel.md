# CLAIMMEDIALABEL callback function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
*ClaimMediaLabel* callback function determines whether a specified media label was created by the media's associated application.

## Parameters

### `pBuffer` [in]

Pointer to a buffer that contains the media label.

### `nBufferSize` [in]

Size of the buffer, in bytes.

### `pLabelInfo` [out]

Pointer to a
[MediaLabelInfo](https://learn.microsoft.com/windows/desktop/api/ntmsmli/ns-ntmsmli-medialabelinfo) structure. The media label library fills in this structure if the library recognizes the media label.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **NO_ERROR** | The media label library filled in the [MediaLabelInfo](https://learn.microsoft.com/windows/desktop/api/ntmsmli/ns-ntmsmli-medialabelinfo) structure. |
| **ERROR_BAD_FORMAT** | The media label library does not recognize the media label. |

## Remarks

When a media label library uses the
*ClaimMediaLabel* function to identify the media label as one created by its associated application, the media label library must fill in the
[MediaLabelInfo](https://learn.microsoft.com/windows/desktop/api/ntmsmli/ns-ntmsmli-medialabelinfo) structure and return NO_ERROR. If the media label library does not recognize the media label, it returns ERROR_BAD_FORMAT.

## See also

[Media Label Library Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[MediaLabelInfo](https://learn.microsoft.com/windows/desktop/api/ntmsmli/ns-ntmsmli-medialabelinfo)