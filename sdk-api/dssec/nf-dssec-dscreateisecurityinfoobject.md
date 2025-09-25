# DSCreateISecurityInfoObject function

## Description

The **DSCreateISecurityInfoObject** function creates an instance of the [ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) interface associated with the specified directory service (DS) object.

## Parameters

### `pwszObjectPath` [in]

The full path of the DS object for which to create an instance of the [ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) interface.

### `pwszObjectClass` [in]

The class of the object specified by the *pwszObjectPath* parameter.

### `dwFlags` [in]

Flags used for the security property page associated with the new instance of the [ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) interface. This parameter can be any combination of the following flags.

| Value | Meaning |
| --- | --- |
| **DSSI_READ_ONLY**<br><br>0x00000001 | The security properties are read-only. |
| **DSSI_NO_ACCESS_CHECK**<br><br>0x00000002 | No access check is performed. |
| **DSSI_NO_EDIT_SACL**<br><br>0x00000004 | The [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) property is read-only. |
| **DSSI_NO_EDIT_OWNER**<br><br>0x00000008 | The object owner property is read-only. |
| **DSSI_IS_ROOT**<br><br>0x00000010 | The object is a root object. |
| **DSSI_NO_FILTER**<br><br>0x00000020 | Do not apply any filters. |
| **DSSI_NO_READONLY_MESSAGE**<br><br>0x00000040 | Suppress read-only popup messages. |

### `ppSI` [out]

A pointer to the instance of the [ISecurityInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation) interface this function creates.

### `pfnReadSD` [in, optional]

A pointer to a function used to read the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the object. This value can be **NULL**. If *pfnReadSD* is not **NULL**, **DSCreateISecurityInfoObject** calls the function referenced by *pfnReadSD* to retrieve the security descriptor of the object.

### `pfnWriteSD` [in, optional]

A pointer to a function used to write the security descriptor of the object. This value can be **NULL**. If *pfnWriteSD* is not **NULL**, **DSCreateISecurityInfoObject** calls the function referenced by *pfnWriteSD* to write the security descriptor of the object.

### `lpContext` [in]

Context to pass to the functions identified by the *pfnReadSD* and *pfnWriteSD* parameters.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).