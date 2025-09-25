# DSOBJECT structure

## Description

The **DSOBJECT** structure contains directory object data. An array of this structure is provided in the **aObjects** member of the [DSOBJECTNAMES](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobjectnames) structure.

## Members

### `dwFlags`

Contains a set of flags that provide object data. This can be zero or a combination of one, or more, of the following values.

#### DSOBJECT_ISCONTAINER

The object is a container.

#### DSOBJECT_READONLYPAGES

When displaying properties for this object, the user interface must be read-only.

### `dwProviderFlags`

Contains a set of flags that provide data about the object provider. This can be zero or a combination of one or more of the following values.

#### DSPROVIDER_ADVANCED

The user interface for this object should be shown in an advanced mode.

#### DSPROVIDER_UNUSED_0

Not used.

#### DSPROVIDER_UNUSED_1

Not used.

#### DSPROVIDER_UNUSED_2

Not used.

#### DSPROVIDER_UNUSED_3

Not used.

### `offsetName`

Contains the offset, in bytes, from the start of the [DSOBJECTNAMES](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobjectnames) structure to a NULL-terminated, Unicode string that contains the ADSPath of the object.

The following code example shows how to use this member.

```cpp
pwszName = (LPWSTR)((LPBYTE)pdsObjNames +
    pdsObjNames->aObjects[i].offsetName);

```

### `offsetClass`

Contains the offset, in bytes, from the start of the [DSOBJECTNAMES](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobjectnames) structure to a NULL-terminated, Unicode string that contains the class name of the object. Contains zero if the class name is unknown.

The following code example shows how to use this member.

```cpp
pwszClass = (LPWSTR)((LPBYTE)pdsObjNames +
    pdsObjNames->aObjects[i].offsetClass);

```

## See also

[DSOBJECTNAMES](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobjectnames)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)