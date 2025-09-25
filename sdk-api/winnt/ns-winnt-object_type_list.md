# OBJECT_TYPE_LIST structure

## Description

The **OBJECT_TYPE_LIST** structure identifies an object type element in a hierarchy of object types. The
[AccessCheckByType](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckbytype) functions use an array of **OBJECT_TYPE_LIST** structures to define a hierarchy of an object and its subobjects, such as property sets and properties.

## Members

### `Level`

Specifies the level of the object type in the hierarchy of an object and its subobjects. Level zero indicates the object itself. Level one indicates a subobject of the object, such as a property set. Level two indicates a subobject of the level one subobject, such as a property. There can be a maximum of five levels numbered zero through four.

Directory service objects use the following level values.

| Value | Meaning |
| --- | --- |
| **ACCESS_OBJECT_GUID** | Indicates the object itself at level zero. |
| **ACCESS_PROPERTY_SET_GUID** | Indicates a property set at level one. |
| **ACCESS_PROPERTY_GUID** | Indicates a property at level two. |

### `Sbz`

Should be zero. Reserved for future use.

### `ObjectType`

A pointer to the GUID for the object or subobject.

## See also

[AccessCheckByType](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckbytype)

[AccessCheckByTypeAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytypeandauditalarma)

[AccessCheckByTypeResultList](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckbytyperesultlist)

[AccessCheckByTypeResultListAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytyperesultlistandauditalarma)