# COMPATIBILITY_CONTEXT_ELEMENT structure

## Description

The **COMPATIBILITY_CONTEXT_ELEMENT** structure is used by the [QueryActCtxW](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-activation_context_compatibility_information) function as part of the [ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-activation_context_compatibility_information) structure.

## Members

### `Id`

This is a **GUID** that specifies a version of Windows.

| Value | Meaning |
| --- | --- |
| {e2011457-1546-43c5-a5fe-008deee3d3f0} | Windows Vista |
| {35138b9a-5d96-4fbd-8e2d-a2440225f93a} | Windows 7 |

### `Type`

A value of the [ACTCTX_COMPATIBILITY_ELEMENT_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-actctx_compatibility_element_type) enumeration that describes the compatibility elements in the application manifest.