# DrtUpdateKey function

## Description

The **DrtUpdateKey** function updates the application data associated with a registered key.

## Parameters

### `hKeyRegistration` [in]

The DRT handle returned by the [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey) function specifying a registered key within the DRT instance.

### `pAppData` [in]

The new application data to associate with the key.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | * *pAppData* is **NULL**<br>* The value of **cb** in *pAppData* is less than 0.<br>* The value of **cb** in *pAppData* is more than 5120.<br>* The value of **pb** in *pAppData* is **NULL**. |
| **E_HANDLE** | *hKeyRegistration* is an invalid handle. |
| **E_OUTOFMEMORY** | The system is out of memory. |

## See also

[DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey)

[DrtUnregisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtunregisterkey)