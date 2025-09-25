# IVssEnumObject::Next

## Description

The
**Next** method returns the specified number of objects from the specified list of enumerated objects.

## Parameters

### `celt` [in]

The number of elements to be read from the list of enumerated objects into the *rgelt* buffer.

### `rgelt` [out]

The address of a caller-allocated buffer that receives *celt*[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) structures that contain the returned objects. This parameter is required and cannot be NULL.

### `pceltFetched` [out]

The number of elements that were returned in the *rgelt* buffer.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **S_FALSE** | The number of returned items is less than the number requested. |
| **E_FAIL** | There is an internal error in the enumerator. |
| **E_POINTER** | One of the required pointer parameters is NULL. |

## Remarks

When requesting the return of more than one
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) object, a return value of S_FALSE indicates that the end of the enumeration list has been reached. If more objects were requested than remained in the list,
**Next** will return all the remaining objects, set the *pceltFetched* parameter to a nonzero value, and return S_FALSE.

The output *rgelt* parameter must point to an allocated array containing *celt*
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) structures, and cannot be NULL.

It is the caller's responsibility to free system resources returned by **IVssEnumObject::Next** to the
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) structure pointed to by the *rgelt* parameter.

The callers must use
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) for every string value in the
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) or
[VSS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_provider_prop) object in the returned
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) structure.

In the case of
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop), this can be done manually, or the utility function
[VssFreeSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-vssfreesnapshotproperties) can be used.

## See also

[IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query)

[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)

[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop)