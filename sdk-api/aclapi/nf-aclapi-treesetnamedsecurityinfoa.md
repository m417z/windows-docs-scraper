# TreeSetNamedSecurityInfoA function

## Description

This version of this function is not supported. The wide character version of this function, [TreeSetNamedSecurityInfoW](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-treesetnamedsecurityinfow), is supported.

## Parameters

### `pObjectName` [in]

 Pointer to a **null**-terminated string that specifies the name of the root node object for the objects that are to receive updated security information. Supported objects are registry keys and file objects. For descriptions of the string formats for the different object types, see
[SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type).

### `ObjectType` [in]

A value of the [SE_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-se_object_type) enumeration that indicates the type of object named by the *pObjectName* parameter. The supported values are SE_REGISTRY_KEY and SE_FILE_OBJECT, for registry keys and file objects, respectively.

### `SecurityInfo` [in]

A set of
bit flags that indicate the type of security information to set. This parameter can be a combination of the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) bit flags.

### `pOwner` [in, optional]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that identifies the owner of the object. The SID must be one that can be assigned as the owner SID of a security descriptor. The *SecurityInfo* parameter must include the OWNER_SECURITY_INFORMATION flag. To set the owner, the caller must have WRITE_OWNER access to each object, including the root object. If you are not setting the owner SID, this parameter can be **NULL**.

### `pGroup` [in, optional]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that identifies the primary group of the object. The *SecurityInfo* parameter must include the GROUP_SECURITY_INFORMATION flag. To set the group, the caller must have WRITE_OWNER access to each object, including the root object. If you are not setting the primary group SID, this parameter can be **NULL**.

### `pDacl` [in, optional]

A pointer to an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) structure that represents the new DACL for the objects being reset. The *SecurityInfo* parameter must include the DACL_SECURITY_INFORMATION flag. The caller must have READ_CONTROL and WRITE_DAC access to each object, including the root object. If you are not setting the DACL, this parameter can be **NULL**.

### `pSacl` [in, optional]

A pointer to an ACL structure that represents the new SACL for the objects being reset. The *SecurityInfo* parameter must include any of the following flags: SACL_SECURITY_INFORMATION, LABEL_SECURITY_INFORMATION, ATTRIBUTE_SECURITY_INFORMATION, SCOPE_SECURITY_INFORMATION, or BACKUP_SECURITY_INFORMATION. If setting SACL_SECURITY_INFORMATION or SCOPE_SECURITY_INFORMATION, the caller must have the SE_SECURITY_NAME privilege enabled. If you are not setting the SACL, this parameter can be **NULL**.

### `dwAction` [in]

Specifies the behavior of this function. This must be set to one of the following values, defined in AccCtrl.h.

| Value | Meaning |
| --- | --- |
| **TREE_SEC_INFO_SET**<br><br>0x00000001 | The security information is set on the object specified by the *pObjectName* parameter and the tree of child objects of that object. If ACLs are specified in either the *pDacl* or *pSacl* parameters, the security descriptors are associated with the object. The security descriptors are propagated to the tree of child objects based on their inheritance properties. |
| **TREE_SEC_INFO_RESET**<br><br>0x00000002 | The security information is reset on the object specified by the *pObjectName* parameter and the tree of child objects of that object. Any existing security information is removed from all objects on the tree.<br><br>If any object in the tree does not grant appropriate permissions to the caller to modify the security descriptor on the object, then the propagation of security information on that particular node of the tree and its objects is skipped. The operation continues on the rest of the tree under the object specified by the *pObjectName* parameter. |
| **TREE_SEC_INFO_RESET_KEEP_EXPLICIT**<br><br>0x00000003 | The security information is reset on the object specified by the *pObjectName* parameter and the tree of child objects of that object. Any existing inherited security information is removed from all objects on the tree. Security information that was explicitly set on objects in the tree is unchanged. <br><br>If any object in the tree does not grant appropriate permissions to the caller to modify the security descriptor on the object, then the propagation of security information on that particular node of the tree and its objects is skipped. The operation continues on the rest of the tree under the object specified by the *pObjectName* parameter. |

### `fnProgress` [in]

A pointer to the function used to track the progress of the **TreeSetNamedSecurityInfo** function. The prototype of the progress function is:

```cpp
#include <windows.h>
#include <Aclapi.h>
#pragma comment(lib, "Advapi32.lib")

typedef VOID (*FN_PROGRESS) (
  IN LPWSTR pObjectName,              // Name of object just processed
  IN DWORD Status,                    // Status of operation on object
  IN OUT PPROG_INVOKE_SETTING
                      pInvokeSetting, // When to set
  IN PVOID Args,                      // Caller specific data
  IN BOOL SecuritySet                 // Whether security was set
);

```

The progress function provides the caller with progress and error information when nodes are processed. The caller specifies the progress function in *fnProgress*, and during the tree operation, **TreeSetNamedSecurityInfo** passes the name of the last object processed, the error status of that operation, and the current PROG_INVOKE_SETTING value. The caller can change the PROG_INVOKE_SETTING value by using *pInvokeSetting*.

If no progress function is to be used, set this parameter to **NULL**.

### `ProgressInvokeSetting` [in]

A value of the [PROG_INVOKE_SETTING](https://learn.microsoft.com/windows/win32/api/accctrl/ne-accctrl-prog_invoke_setting) enumeration that specifies the initial setting for the progress function.

### `Args` [in, optional]

A pointer to a **VOID** for progress function arguments specified by the caller.

## Return value

If the function succeeds, the function returns **ERROR_SUCCESS**.

If the function fails, it returns an error code defined in WinError.h.

## Remarks

Setting a **NULL** owner, group, DACL, or SACL is not supported by this function.

If the caller does not contain the proper privileges and permissions to support the requested owner, group, DACL, and SACL updates, then none of the updates is performed.

This function provides the same functionality as the [SetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setnamedsecurityinfoa) function when the value of the *dwAction* parameter is set to **TREE_SEC_INFO_SET**, the value of the *ProgressInvokeSetting* parameter is set to **ProgressInvokePrePostError**, and the function pointed to by the *fnProgress* parameter sets the value of its *pInvokeSetting* parameter to **ProgressInvokePrePostError**.

This function is similar to the [TreeResetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-treeresetnamedsecurityinfoa) function:

* If the *dwAction* parameter of **TreeSetNamedSecurityInfo** is set to TREE_SEC_INFO_RESET_KEEP_EXPLICIT, then the function is equivalent to [TreeResetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-treeresetnamedsecurityinfoa) with the *KeepExplicit* parameter set to **TRUE**.
* If the *dwAction* parameter of **TreeSetNamedSecurityInfo** is set to TREE_SEC_INFO_RESET, then the function is equivalent to [TreeResetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-treeresetnamedsecurityinfoa) with the *KeepExplicit* parameter set to **FALSE**.

> [!NOTE]
> The aclapi.h header defines TreeSetNamedSecurityInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).