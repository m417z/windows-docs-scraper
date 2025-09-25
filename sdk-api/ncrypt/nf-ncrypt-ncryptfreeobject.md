# NCryptFreeObject function

## Description

The **NCryptFreeObject** function frees a CNG key storage object.

## Parameters

### `hObject` [in]

The handle of the object to free. This can be either a provider handle (**NCRYPT_PROV_HANDLE**) or a key handle (**NCRYPT_KEY_HANDLE**).

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_HANDLE** | The handle in the *hObject* parameter is not valid. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.

## See also

[NCryptOpenStorageProvider](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenstorageprovider)