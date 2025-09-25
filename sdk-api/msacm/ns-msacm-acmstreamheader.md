# ACMSTREAMHEADER structure

## Description

The **ACMSTREAMHEADER** structure defines the header used to identify an ACM conversion source and destination buffer pair for a conversion stream.

## Members

### `cbStruct`

Size, in bytes, of the **ACMSTREAMHEADER** structure. This member must be initialized before the application calls any ACM stream functions using this structure. The size specified in this member must be large enough to contain the base **ACMSTREAMHEADER** structure.

### `fdwStatus`

Flags giving information about the conversion buffers. This member must be initialized to zero before the application calls the [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader) function and should not be modified by the application while the stream header remains prepared.

| Name | Description |
| --- | --- |
| **ACMSTREAMHEADER_STATUSF_DONE** | Set by the ACM or driver to indicate that it is finished with the conversion and is returning the buffers to the application. |
| **ACMSTREAMHEADER_STATUSF_INQUEUE** | Set by the ACM or driver to indicate that the buffers are queued for conversion. |
| **ACMSTREAMHEADER_STATUSF_PREPARED** | Set by the ACM to indicate that the buffers have been prepared by using the [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader) function. |

### `dwUser`

User data. This can be any instance data specified by the application.

### `pbSrc`

Pointer to the source buffer. This pointer must always refer to the same location while the stream header remains prepared. If an application needs to change the source location, it must unprepare the header and reprepare it with the alternate location.

### `cbSrcLength`

Length, in bytes, of the source buffer pointed to by **pbSrc**. When the header is prepared, this member must specify the maximum size that will be used in the source buffer. Conversions can be performed on source lengths less than or equal to the original prepared size. However, this member must be reset to the original size when an application unprepares the header.

### `cbSrcLengthUsed`

Amount of data, in bytes, used for the conversion. This member is not valid until the conversion is complete. This value can be less than or equal to **cbSrcLength**. An application must use the **cbSrcLengthUsed** member when advancing to the next piece of source data for the conversion stream.

### `dwSrcUser`

User data. This can be any instance data specified by the application.

### `pbDst`

Pointer to the destination buffer. This pointer must always refer to the same location while the stream header remains prepared. If an application needs to change the destination location, it must unprepare the header and reprepare it with the alternate location.

### `cbDstLength`

Length, in bytes, of the destination buffer pointed to by **pbDst**. When the header is prepared, this member must specify the maximum size that will be used in the destination buffer.

### `cbDstLengthUsed`

Amount of data, in bytes, returned by a conversion. This member is not valid until the conversion is complete. This value can be less than or equal to **cbDstLength**. An application must use the **cbDstLengthUsed** member when advancing to the next destination location for the conversion stream.

### `dwDstUser`

User data. This can be any instance data specified by the application.

### `dwReservedDriver`

Reserved; do not use. This member requires no initialization by the application and should never be modified while the header remains prepared.

## Remarks

Before an **ACMSTREAMHEADER** structure can be used for a conversion, it must be prepared by using the [acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader) function. When an application is finished with an **ACMSTREAMHEADER** structure, it must call the [acmStreamUnprepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamunprepareheader) function before freeing the source and destination buffers.

## See also

Audio Compression Manager

[Audio Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-structures)

[acmStreamPrepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamprepareheader)

[acmStreamUnprepareHeader](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmstreamunprepareheader)