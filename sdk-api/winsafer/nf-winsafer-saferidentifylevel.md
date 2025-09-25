# SaferIdentifyLevel function

## Description

The **SaferIdentifyLevel** function retrieves information about a level.

## Parameters

### `dwNumProperties` [in]

Number of
[SAFER_CODE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_code_properties_v2) structures in the *pCodeproperties* parameter.

### `pCodeProperties` [in, optional]

Array of [SAFER_CODE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_code_properties_v2) structures. Each structure contains a code file to be checked and the criteria used to check the file.

### `pLevelHandle` [out]

The returned SAFER_LEVEL_HANDLE. When you have finished using the handle, close it by calling the [SaferCloseLevel](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-safercloselevel) function.

### `lpReserved`

Reserved for future use. Should be set to **NULL**.

Beginning with Windows 8 and Windows Server 2012 SRP_POLICY_APPX is defined as Windows Store app.

## Return value

**TRUE** if a SAFER_LEVEL_HANDLE was opened; otherwise, **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).