# VerifierIsPerUserSettingsEnabled function

## Description

Determines whether Application Verifier can use per-user settings.

## Return value

If per-user settings are enabled, the function returns **TRUE**. Otherwise, it returns **FALSE**.

## Remarks

Application Verifier settings are stored in the following registry key **HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Image File Execution Options** for native applications and **HKEY_LOCAL_MACHINE\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Image File Execution Options** for applications running under WOW64. Only administrators can write to these keys.

Starting with Windows Vista, Application Verifier settings can be stored in **HKEY_CURRENT_USER**. To enable the use of the per-user settings, the administrator must create a REG_DWORD value named **ImageExecutionOptions** in the **HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager** key, set the low-order bit, and reboot the computer. To disable the use of the per-user settings, the administrator must either clear the bit or delete the registry value and reboot the computer.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to load Verifier.dll and call the [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to get the address of this function.