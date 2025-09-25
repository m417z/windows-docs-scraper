# SLGetApplicationInformation function

## Description

Gets information about the specified application.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

### `pApplicationId` [in]

Type: **const SLID***

A pointer to the application ID.

### `pwszValueName` [in]

Type: **PCWSTR**

| Value | Meaning |
| --- | --- |
| **SL_INFO_KEY_IS_KMS**<br><br>L"IsKeyManagementService" | Indicates whether the machine has a Key Management Service (KMS) enabled. |
| **SL_INFO_KEY_KMS_CURRENT_COUNT**<br><br>L"KeyManagementServiceCurrentCount" | The number of volume clients on a KMS host that are currently active. |
| **SL_INFO_KEY_KMS_REQUIRED_CLIENT_COUNT**<br><br>L"KeyManagementServiceRequiredClientCount" | The minimum number of VL clients required to connect to a KMS host for enabling activation. |
| **SL_INFO_KEY_KMS_UNLICENSED_REQUESTS**<br><br>L"KeyManagementServiceUnlicensedRequests" | The number of KMS requests from VL clients with License Status=Unlicensed. |
| **SL_INFO_KEY_KMS_LICENSED_REQUESTS**<br><br>L"KeyManagementServiceLicensedRequests" | The number of KMS requests from VL clients with License Status=Licensed. |
| **SL_INFO_KEY_KMS_OOB_GRACE_REQUESTS**<br><br>L"KeyManagementServiceOOBGraceRequests" | The number of KMS requests from VL clients with License Status=OOB Grace. |
| **SL_INFO_KEY_KMS_OOT_GRACE_REQUESTS**<br><br>L"KeyManagementServiceOOTGraceRequests" | The number of KMS requests from VL clients with License Status=OOT Grace. |
| **SL_INFO_KEY_KMS_NON_GENUINE_GRACE_REQUESTS**<br><br>L"KeyManagementServiceNonGenuineGraceRequests" | The number of KMS requests from VL clients with License Status=Non-Genuine Grace. |
| **SL_INFO_KEY_KMS_NOTIFICATION_REQUESTS**<br><br>L"KeyManagementServiceNotificationRequests" | The number of KMS requests from VL clients with License Status=Notification. |
| **SL_INFO_KEY_KMS_TOTAL_REQUESTS**<br><br>L"KeyManagementServiceTotalRequests" | Total number of valid KMS requests. |
| **SL_INFO_KEY_KMS_FAILED_REQUESTS**<br><br>L"KeyManagementServiceFailedRequests" | Total number of failed KMS requests. |

### `peDataType` [out, optional]

Type: **[SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype)***

A pointer to a value of the [SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype) enumeration that specifies the type of data in the ppbValue buffer. The following values are valid.

| Value | Meaning |
| --- | --- |
| **SL_DATA_SZ** | UNICODE string |
| **SL_DATA_DWORD** | DWORD |
| **SL_DATA_BINARY** | Binary blob |

### `pcbValue` [out]

Type: **UINT***

A pointer to the size, in bytes, of the *ppbValue* buffer.

### `ppbValue` [out]

Type: **PBYTE***

If successful, the data is returned in the buffer allocated by the SLC.
When finished using the memory, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The value for the input key was not found. |