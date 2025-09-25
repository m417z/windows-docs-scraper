# NCRYPT_ALLOC_PARA structure

## Description

The **NCRYPT_ALLOC_PARA** structure enables you to specify custom functions that can be used to allocate and free data. This structure is used in the following functions:

* [NCryptGetProtectionDescriptorInfo](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptgetprotectiondescriptorinfo)
* [NCryptProtectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptprotectsecret)
* [NCryptUnprotectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptunprotectsecret)

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pfnAlloc`

Address of a custom function that can allocate memory.

### `pfnFree`

Address of a function that can free memory allocated by the function specified by the **pfnAlloc** member.

## See also

[NCryptGetProtectionDescriptorInfo](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptgetprotectiondescriptorinfo)

[NCryptProtectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptprotectsecret)

[NCryptUnprotectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptunprotectsecret)