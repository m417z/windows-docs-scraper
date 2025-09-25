# ImmDisableTextFrameService function

## Description

[**ImmDisableTextFrameService** is no longer available for use as of Windows Vista. Instead, use [ImmDisableIME](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immdisableime).
]

Disables the text service for the specified thread. For details, see [Text Services Framework](https://learn.microsoft.com/windows/desktop/TSF/text-services-framework) (TSF).

## Parameters

### `idThread` [in]

Identifier of the thread for which to disable the text service. The thread must be in the same process as the application. The application sets this parameter to 0 to disable the service for the current thread. The application sets the parameter to –1 to disable the service for all threads in the current process.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

An application calls this function if it has a thread that is incompatible with TSF.

Note that TSF functionality is provided to applications that are not specifically written to use TSF, Input Method Manager (IMM32), or Active Input Method Manager (AIMM 1.2). Although an application can be written to use TSF, IMM32, and AIMM 1.2, there can be specific controls within the application that do not use these technologies. TSF support is provided to these specific controls as well. This TSF feature is available beginning with Windows XP when all of these dynamic-link libraries (DLLs) are loaded: system modules User32.dll, Imm32.dll, and Win32k.sys, and TSF modules Msctf.dll and Msimtf.dll.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)