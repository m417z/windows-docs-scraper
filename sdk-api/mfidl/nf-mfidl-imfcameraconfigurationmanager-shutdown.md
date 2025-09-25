## Description

Shuts down the camera configuration manager.

## Remarks

After calling **Shutdown**, subsequent calls to [IMFCameraConfigurationManager::LoadDefaults](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraconfigurationmanager-loaddefaults) or [IMFCameraConfigurationManager::SaveDefaults](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraconfigurationmanager-savedefaults) will result in an MF_E_SHUTDOWN error.

## See also