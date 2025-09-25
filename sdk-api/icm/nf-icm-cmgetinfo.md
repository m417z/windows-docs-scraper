## Description

Retrieves various information about the color management module (CMM).

Every CMM is required to export this function.

## Parameters

### `dwInfo`

Specifies what information should be retrieved. This parameter can take one of the following constant values.

| Constant | Significance of the function's return value |
| --- | --- |
| **CMM_DESCRIPTION** | A text string that describes the color management module. |
| **CMM_DLL_VERSION** | Version number of the CMM DLL. |
| **CMM_DRIVER_LEVEL** | Driver compatibility information. |
| **CMM_IDENT** | The CMM identification signature registered with the International Color Consortium (ICC). |
| **CMM_LOGOICON** | The logo icon for this CMM. |
| **CMM_VERSION** | Version of Windows supported. |
| **CMM_WIN_VERSION** | Backward compatibility with Windows 95. |

## Return value

If this function succeeds, the return value is the same nonzero value that was passed in through the *dwInfo* parameter. If the function fails, the return value is zero.

## Remarks

The **CMGetInfo** function can be called by applications directly to obtain information about the CMM. Applications should not call other CMM functions directly. To obtain CMM information, get the path to the CMM from the registry. Invoke the Windows API function [GetModuleHandle](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea) and pass the file name of the CMM as the value of its parameter. Call the **CMGetInfo** function and pass it the constant CMM\_DESCRIPTION as the value of its parameter. Call the [LoadString](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadstringa) function. Pass the module handle as the first parameter, and the return value of the **CMGetInfo** function as the value of the second parameter.

CMMs that do not run on Windows 95 should return 0x0050000 for CMM\_WIN\_VERSION.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)