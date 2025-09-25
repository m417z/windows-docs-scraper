# MI_Instance_SetNameSpace function

## Description

Sets the namespace name of the specified instance.

## Parameters

### `self` [in, out]

Instance whose namespace name is to be set.

### `nameSpace`

A null-terminated string that represents the new namespace name.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Namespace names must conform to the following examples:

* root
* root/cimv2
* aaa/bbb/ccc