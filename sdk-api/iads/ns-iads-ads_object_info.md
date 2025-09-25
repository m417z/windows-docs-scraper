# ADS_OBJECT_INFO structure

## Description

The **ADS_OBJECT_INFO** structure specifies the data, including the identity and location, of a directory service object.

## Members

### `pszRDN`

The null-terminated Unicode string that contains the relative distinguished name of the directory service object.

### `pszObjectDN`

The null-terminated Unicode string that contains the distinguished name of the directory service object.

### `pszParentDN`

The null-terminated Unicode string that contains the distinguished name of the parent object.

### `pszSchemaDN`

The null-terminated Unicode string that contains the distinguished name of the schema class of the object.

### `pszClassName`

The null-terminated Unicode string that contains the name of the class of which this object is an instance.

## Remarks

To obtain the object data, non-Automation clients call the [IDirectoryObject::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-getobjectinformation) method, which takes an out parameter, a pointer to an **ADS_OBJECT_INFO** structure allocated in the heap. Automation clients can accomplish the same task by calling [IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo).

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo)

[IDirectoryObject::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-getobjectinformation)