# IMMCVersionInfo::GetMMCVersion

## Description

The
**GetMMCVersion** method retrieves version information for the MMC application.

## Parameters

### `pVersionMajor` [out]

The version major number. For example, if **pVersionMajor* returns 2, then MMC version 2.x is running.

### `pVersionMinor` [out]

The version minor number. For example, if **pVersionMinor* returns 0, then MMC version x.0 is running.

## Return value

If successful, the return value is S_OK. Other return values indicate an error code.

## Remarks

The
[IMMCVersionInfo](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-immcversioninfo) interface is introduced in MMC 2.0. For instructions on how to determine the MMC version if MMC 1.x is installed, see
[Detecting the MMC Version Number](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/detecting-the-mmc-version-number).

#### Examples

```cpp
IMMCVersionInfo * pVersionInfo = NULL;
HRESULT   hr;

// Create an object of the MMCVersionInfo class.
hr = CoCreateInstance(CLSID_MMCVersionInfo,
                      NULL,
                      CLSCTX_INPROC_SERVER,
                      IID_IMMCVersionInfo,
                      (void**)&pVersionInfo);
if (S_OK != hr)
{
    // Error encountered.
    // If the system does not support MMCVersionInfo, report it.
    // This would occur if the system was running MMC 1.x.
    if (REGDB_E_CLASSNOTREG == hr)
        OutputDebugString(_T("MMCVersionInfo is not registered\n"));
    else
        // Another error was encountered.
        OutputDebugString(_T("Failed call to CoCreateInstance\n"));
}
else
{
    // Call the GetMMCVersion method.
    long lMajor, lMinor;
    hr = pVersionInfo->GetMMCVersion(&lMajor,
                                     &lMinor);
    if (S_OK != hr)
        OutputDebugString(_T("Failed call to GetMMCVersion\n"));
    else
    {
        OutputDebugString(_T("Success in GetMMCVersion\n"));
        // Use major and minor version information as required.
        // ...
    }
}
// Free the interface pointer.
if (NULL != pVersionInfo)
{
    pVersionInfo->Release();
    pVersionInfo = NULL;
}
```