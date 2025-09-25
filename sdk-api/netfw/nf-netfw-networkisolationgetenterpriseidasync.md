# NetworkIsolationGetEnterpriseIdAsync function

## Description

Gets the Enterprise ID based on Network Isolation endpoints in the context of the Windows Information Protection (WIP) or the Microsoft Defender Application Guard (MDAG) scenarios. If neither WIP nor MDAG are on, the API returns NULL, unless the flag **NETISO_GEID_FORCE_TO_CHECK** is passed. The Enterprise ID can be any string different from NULL or “*”.

Example of NetworkIsolationGetEnterpriseIdAsync usage: https://github.com/microsoft/EnterpriseStateClassify

## Parameters

### `wszServerName` [in]

The name of the Enterprise Data Protection Server.

### `dwFlags` [in]

A bitmask value of control flags which specify the context of the API call. May contain one or more of the following flags.

| Value | Meaning |
| ------ | ------ |
| **NETISO_GEID_DEFAULT**<br>0x00 | Default API behavior.<br>Returns the Enterprise ID for Enterprise resources.<br>Returns NULL for Personal resources.<br>For Neutral resources, returns Enterprise ID if it is called from an Enterprise context, or returns NULL if it is called from a Personal context. |
| **NETISO_GEID_FOR_WDAG**<br>0x01 | Used in the context of the Microsoft Defender Application Guard (MDAG) scenario. |
| **NETISO_GEID_FOR_NEUTRAL_AWARE**<br>0x02 | Used by applications that are aware of neutral resources.<br>For Neutral resources the API will return L”*”.<br>For Enterprise resources the API will return the Enterprise ID.<br>For Personal resources the API will return NULL. |
| **NETISO_GEID_FORCE_TO_CHECK**<br>0x04 | Forces API to check the resource even in cases when neither Windows Information Protection nor MDAG are enabled. |

### `context` [in, optional]

Optional context pointer.

### `callback` [in]

Function pointer that will be invoked when a notification is ready for delivery.

### `hOperation` [out]

The handle for the Enterprise Data Protection Server endpoints.

## Return value

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## Remarks

> [!NOTE]
> Windows Defender Application Guard (WDAG) is now Microsoft Defender Application Guard (MDAG). The WDAG name is deprecated, but it is still used in some APIs.