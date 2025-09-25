## Description

Allows you to select the preferred color management module (CMM) to use.

## Parameters

### `dwCMMType`

Specifies the signature of the desired CMM as registered with the International Color Consortium (ICC).

**Windows 2000 only:** Setting this parameter to **NULL** causes the WCS system to select the default CMM.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

For **SelectCMM** to succeed, the specified CMM must be registered with the system.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)