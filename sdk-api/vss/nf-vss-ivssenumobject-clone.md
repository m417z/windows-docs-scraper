# IVssEnumObject::Clone

## Description

The **Clone** method creates a copy of the
specified list of enumerated elements by creating a copy of the
[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) enumerator object.

## Parameters

### `ppenum` [in, out]

Doubly indirect pointer to an [IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)
enumerator object. Set the value of this parameter to **NULL** before calling this
method.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_FAIL** | There is an internal error in the enumerator. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **E_POINTER** | One of the required pointer parameters is NULL. |

## Remarks

The cloned enumerator object will refer to the same list of
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) structures.

The caller must call the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method of the
returned interface pointer to deallocate the system resources held by the
[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) enumerator object pointed to by
the *ppEnum* parameter.

## See also

[IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query)

[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)

[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop)