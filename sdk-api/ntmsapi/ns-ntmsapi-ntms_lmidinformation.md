# NTMS_LMIDINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_LMIDINFORMATION** structure defines the properties specific to a logical media object.

## Members

### `MediaPool`

Unique identifier of the media pool that contains the logical media.

### `dwNumberOfPartitions`

Number of sides in the media object.

## Remarks

The
**NTMS_LMIDINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)