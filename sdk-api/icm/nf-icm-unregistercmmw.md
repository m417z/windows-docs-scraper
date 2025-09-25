## Description

Dissociates a specified ID value from a given color management module dynamic-link library (CMM DLL).

## Parameters

### `pMachineName`

Reserved; must currently be set to **NULL**, until non-local registration is supported. This parameter is intended to point to the name of the computer on which a CMM DLLs registration should be removed. A **NULL** pointer indicates the local computer.

### `cmmID`

Specifies the ID value identifying the CMM whose registration is to be removed. This is the signature of the CMM registered with the International Color Consortium (ICC).

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

If the profile for creating a transform later specifies this ID, the Windows default CMM will be used rather than this CMM DLL.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)