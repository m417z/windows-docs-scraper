# FaxExtConfigChange function

## Description

A **FaxExtConfigChange** callback function is a placeholder for a function name defined by the fax extension DLL. The fax extension DLL should not expose this function.

## Parameters

### `dwDeviceId` [in]

Type: **DWORD**

Specifies a **DWORD** value that indicates the device for which the configuration data has changed.

This parameter can be zero, indicating a change in the extension's global configuration data (configuration data that is not associated with a specific device). For more information, see [Storing Global Configuration Data](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-storing-global-configuration-data).

### `lpcwstrDataGUID` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the GUID of the data that has changed; for example, "{b8959fc9-4e77-4ee9-8411-009acb1bbf3e}".

### `lpData` [in]

Type: **LPBYTE**

Pointer to a buffer that contains the new configuration data.

### `dwDataSize` [in]

Type: **DWORD**

Specifies a **DWORD** value that indicates the size, in bytes, of the buffer pointed to by the *lpData* parameter.

## Return value

Type: **HRESULT**

If the function succeeds, the return value is of the type **HRESULT**, and the value is **NOERROR**.

## Remarks

The fax service calls this function after a change in device configuration data occurs. The fax service calls this function only if the fax extension has registered to receive notifications about configuration changes by calling the [FaxExtRegisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextregisterforevents) function.

If an extension registers to receive notifications about changes in configuration data, that extension does not receive notifications about new configuration values it sets itself. You can change a device's configuration data by calling the [FaxExtSetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextsetdata) function.

The fax extension DLL must register the **FaxExtConfigChange** callback function by passing its address to the [FaxExtRegisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextregisterforevents) callback function. The PFAX_EXT_CONFIG_CHANGE data type is a pointer to a **FaxExtConfigChange** function.

## See also

[FaxExtRegisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextregisterforevents)

[FaxExtSetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextsetdata)