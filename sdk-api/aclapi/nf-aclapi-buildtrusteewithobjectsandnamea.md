# BuildTrusteeWithObjectsAndNameA function

## Description

The **BuildTrusteeWithObjectsAndName** function initializes a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure with the object-specific [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) information and initializes the remaining members of the structure to default values. The caller also specifies the name of the trustee.

## Parameters

### `pTrustee` [in, out]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that will be initialized by this function. If the value of this parameter is **NULL** or a pointer that is not valid, the results are undefined.

### `pObjName` [in, optional]

A pointer to an
[OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a) structure that contains information about the trustee and the securable object.

### `ObjectType` [in, optional]

A pointer to an
[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type) enumeration that contains information about the type of securable object.

### `ObjectTypeName` [in, optional]

A pointer to a string that specifies the name that corresponds to the ObjectType GUID to be added to the
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure returned in the *pTrustee* parameter. This function determines the ObjectType GUID that corresponds to this name.

### `InheritedObjectTypeName` [in, optional]

A pointer to a string that specifies the name that corresponds to the InheritedObjectType GUID to be added to the [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure returned in the *pTrustee* parameter. This function determines the InheritedObjectType GUID that corresponds to this name.

### `Name` [in, optional]

A pointer to a string that specifies the name used to identify the trustee.

## Remarks

This function does not allocate memory for the
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) and
[OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a) structures.

For more information about object-specific ACEs, see [Object-specific ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/object-specific-aces).

> [!NOTE]
> The aclapi.h header defines BuildTrusteeWithObjectsAndName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[BuildTrusteeWithName](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithnamea)

[BuildTrusteeWithObjectsAndSid](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithobjectsandsida)

[BuildTrusteeWithSid](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithsida)

[OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a)

[Object-specific ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/object-specific-aces)

[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)