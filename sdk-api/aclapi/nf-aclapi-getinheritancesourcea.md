# GetInheritanceSourceA function

## Description

This version of this function is not supported. The wide character version of this function, [GetInheritanceSourceW](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getinheritancesourcew), is supported.

## Parameters

### `pObjectName` [in]

A pointer to the name of the object that uses the ACL to be checked.

### `ObjectType` [in]

The type of object indicated by *pObjectName*. The possible values are SE_FILE_OBJECT, SE_REGISTRY_KEY, SE_DS_OBJECT, and SE_DS_OBJECT_ALL.

### `SecurityInfo` [in]

The type of ACL used with the object. The possible values are DACL_SECURITY_INFORMATION or SACL_SECURITY_INFORMATION.

### `Container` [in]

**TRUE** if the object is a container object or **FALSE** if the object is a leaf object. Note that the only leaf object is SE_FILE_OBJECT.

### `pObjectClassGuids` [in, optional]

Optional list of GUIDs that identify the object types or names associated with *pObjectName*. This may be **NULL** if the object manager only supports one object class or has no GUID associated with the object class.

### `GuidCount` [in]

Number of GUIDs pointed to by *pObjectClassGuids*.

### `pAcl` [in]

The ACL for the object.

### `pfnArray` [in, optional]

Reserved. Set this parameter to **NULL**.

### `pGenericMapping` [in]

The mapping of generic rights to specific rights for the object.

### `pInheritArray` [out]

A pointer to an array of [INHERITED_FROM](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-inherited_froma) structures that the **GetInheritanceSource** function fills with the inheritance information. The caller must allocate enough memory for an entry for each ACE in the ACL.

## Return value

 If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## Remarks

The **GetInheritanceSource** function allocates memory for the names returned in the [INHERITED_FROM](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-inherited_froma) structure. When the function has finished using this memory, the calling program must free it by calling
[FreeInheritedFromArray](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-freeinheritedfromarray). Note that the caller must provide memory for the array itself. If the caller allocated the memory, the caller must free that memory after calling **FreeInheritedFromArray**.

This function does not handle race conditions. If your thread calls this function at the approximate time that another thread changes the object's [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), then this function could fail.

> [!NOTE]
> The aclapi.h header defines GetInheritanceSource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FreeInheritedFromArray](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-freeinheritedfromarray)