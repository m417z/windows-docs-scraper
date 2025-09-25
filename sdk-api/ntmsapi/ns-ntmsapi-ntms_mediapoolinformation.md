# NTMS_MEDIAPOOLINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_MEDIAPOOLINFORMATION** structure defines the properties specific to a media pool object.

## Members

### `PoolType`

NTMS supports the following media pool types.

| Value | Meaning |
| --- | --- |
| **NTMS_POOLTYPE_UNKNOWN** | Unknown pool type. |
| **NTMS_POOLTYPE_SCRATCH** | Media that is available to other applications. |
| **NTMS_POOLTYPE_FOREIGN** | Media that has been written to and does not contain a recognizable on-media identifier label-type or label ID. |
| **NTMS_POOLTYPE_IMPORT** | Media that has been written to, has a recognizable on-media identifier label type but an unrecognizable label ID. |
| **NTMS_POOLTYPE_APPLICATION** | Media pool created by an application. One or more application media pools can be created per system. |

### `MediaType`

Single media type that makes up each media pool.

### `Parent`

Parent media pool or **NULL**.

### `AllocationPolicy`

Bit field indicating action at allocation time. This member is writable. This can be the following value.

| Value | Meaning |
| --- | --- |
| **NTMS_ALLOCATE_FROMSCRATCH** | Draw media from free if none is available in the pool. The default is not to draw from free. |

### `DeallocationPolicy`

Bit field indicating action at deallocation time. This member is writable. This can be the following value.

| Value | Meaning |
| --- | --- |
| **NTMS_DEALLOCATE_TOSCRATCH** | Return media to free when available. The default is not to return to free. |

### `dwMaxAllocates`

Number of times the medium can be allocated and deallocated. This member is writable.

### `dwNumberOfPhysicalMedia`

Number of physical media in this media pool.

### `dwNumberOfLogicalMedia`

Number of logical media in this media pool.

### `dwNumberOfMediaPools`

Number of media pools in this media pool.

## Remarks

The
**NTMS_MEDIAPOOLINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)