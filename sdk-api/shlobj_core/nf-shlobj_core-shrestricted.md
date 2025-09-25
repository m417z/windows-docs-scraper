# SHRestricted function

## Description

[**SHRestricted** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Determines whether a specified administrator policy is in effect. In many cases, applications need to modify certain behaviors to comply with the policies enacted by system administrators.

## Parameters

### `rest`

Type: **[RESTRICTIONS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-restrictions)**

Specifies one of the flags described in the [RESTRICTIONS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-restrictions) enumerated type.

## Return value

Type: **DWORD**

Returns nonzero if the specified restriction is in effect, or zero otherwise.