# BuildTrusteeWithObjectsAndSidA function

## Description

The **BuildTrusteeWithObjectsAndSid** function initializes a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure with the object-specific [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) information and initializes the remaining members of the structure to default values. The caller also specifies the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that represents the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the trustee.

## Parameters

### `pTrustee` [in, out]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure to initialize. The **BuildTrusteeWithObjectsAndSid** function does not allocate any memory. If this parameter is **NULL** or a pointer that is not valid, the results are undefined.

### `pObjSid` [in, optional]

A pointer to an
[OBJECTS_AND_SID](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_sid) structure that contains information about the trustee and the securable object.

### `pObjectGuid` [in, optional]

A pointer to a [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that describes the ObjectType GUID to be added to the
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

### `pInheritedObjectGuid` [in, optional]

A pointer to a [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that describes the InheritedObjectType GUID to be added to the [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

### `pSid` [in, optional]

A pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that identifies the trustee.

## Remarks

This function does not allocate memory for the
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) and
[OBJECTS_AND_SID](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_sid) structures.

For more information about object-specific ACEs, see
[Object-specific ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/object-specific-aces).

> [!NOTE]
> The aclapi.h header defines BuildTrusteeWithObjectsAndSid as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[BuildTrusteeWithName](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithnamea)

[BuildTrusteeWithObjectsAndName](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithobjectsandnamea)

[BuildTrusteeWithSid](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithsida)

[OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a)

[Object-specific ACEs](https://learn.microsoft.com/windows/desktop/SecAuthZ/object-specific-aces)

[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)