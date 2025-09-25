## Description

Associates a specified identification value with the specified color management module dynamic link library (CMM DLL). When this ID appears in a color profile, Windows can then locate the corresponding CMM so as to create a transform.

## Parameters

### `pMachineName`

Reserved; must currently be set to **NULL**, until non-local registration is supported. This parameter is intended to point to the name of the machine on which a CMM DLL should be registered. A **NULL** pointer indicates the local machine.

### `cmmID`

Specifies the ID signature of the CMM registered with the International Color Consortium (ICC).

### `pCMMdll`

Pointer to the fully qualified path name of the CMM DLL.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)