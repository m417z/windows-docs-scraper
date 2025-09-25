# IAssemblyName::GetName

## Description

The **GetName** method returns the name portion of the assembly name.

## Parameters

### `lpcwBuffer` [in, out]

When calling this method, set this parameter to the size of the buffer specified by *pwzName*. The specify the size in characters and include the null terminator. When the method returns, the value of *lpcwBuffer* is the size of the name returned.

### `pwzName` [out]

Pointer to the string value that receives the name.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## Remarks

This method is equivalent to using the [GetProperty](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblyname-getproperty) method with the *PropertyId* set to the **ASM_NAME_NAME** option of [ASM_NAME](https://learn.microsoft.com/windows/win32/api/winsxs/ne-winsxs-asm_name). In case ASM_NAME_NAME is not set, the size of the buffer returned by *lpcwBuffer* is 0, and the content of *pwzName* is undefined.

## See also

[IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname)