# ADS_ATTR_INFO structure

## Description

The **ADS_ATTR_INFO** structure is used to contain one or more attribute values for use with the [IDirectoryObject::CreateDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-createdsobject),
[IDirectoryObject::GetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-getobjectattributes), or
[IDirectoryObject::SetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-setobjectattributes) method.

## Members

### `pszAttrName`

The null-terminated Unicode string that contains the attribute name.

### `dwControlCode`

Contains one of the [ADSI Attribute Modification Types](https://learn.microsoft.com/windows/desktop/ADSI/adsi-attribute-modification-types) values that determines the type of operation to be performed on the attribute value.

### `dwADsType`

A value from the [ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum) enumeration that indicates the data type of the attribute.

### `pADsValues`

Pointer to an array of [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structures that contain values for the attribute.

### `dwNumValues`

Size of the **pADsValues** array.

## Remarks

In ADSI, attributes and properties are used interchangeably. Set attributes, when creating a directory service object, using the [IDirectoryObject::CreateDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-createdsobject) method. The [IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject) interface also supports the [IDirectoryObject::GetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-getobjectattributes) and [IDirectoryObject::SetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-setobjectattributes) methods for retrieving and modifying the attributes of the object in a directory.

Memory for the array of [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structures is not allocated with this structure.

The value of the **dwControlCode** member is ignored when the structure is used as an OUT parameter.

## See also

[ADSI Attribute Modification Types](https://learn.microsoft.com/windows/desktop/ADSI/adsi-attribute-modification-types)

[ADSI Constants](https://learn.microsoft.com/windows/desktop/ADSI/adsi-constants)

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum)

[IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject)

[IDirectoryObject::CreateDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-createdsobject)

[IDirectoryObject::GetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-getobjectattributes)

[IDirectoryObject::SetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-setobjectattributes)