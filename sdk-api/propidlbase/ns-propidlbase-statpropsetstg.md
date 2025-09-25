# STATPROPSETSTG structure

## Description

The
**STATPROPSETSTG** structure contains information about a property set. To get this information, call
[IPropertyStorage::Stat](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-stat), which fills in a buffer containing the information describing the current property set. To enumerate the
**STATPROPSETSTG** structures for the property sets in the current property-set storage, call
[IPropertySetStorage::Enum](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-enum) to get a pointer to an enumerator. You can then call the enumeration methods of the
[IEnumSTATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropsetstg) interface on the enumerator. The structure is defined as follows:

## Members

### `fmtid`

FMTID of the current property set, specified when the property set was initially created.

### `clsid`

**CLSID** associated with this property set, specified when the property set was initially created and possibly modified thereafter with
[IPropertyStorage::SetClass](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-setclass). If not set, the value will be **CLSID_NULL**.

### `grfFlags`

Flag values of the property set, as specified in
[IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create).

### `mtime`

Time in Universal Coordinated Time (UTC) when the property set was last modified.

### `ctime`

Time in UTC when this property set was created.

### `atime`

Time in UTC when this property set was last accessed.

### `dwOSVersion`

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[IEnumSTATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropsetstg)

[IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create)

[IPropertyStorage::Stat](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-stat)