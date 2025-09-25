# SetupDiGetDeviceInfoListDetailW function

## Description

The **SetupDiGetDeviceInfoListDetail** function retrieves information associated with a device information set including the class GUID, remote computer handle, and remote computer name.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for which to retrieve information.

### `DeviceInfoSetDetailData` [out]

A pointer to a caller-initialized [SP_DEVINFO_LIST_DETAIL_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_list_detail_data_a) structure that receives the device information set information. For more information about this structure, see the following **Remarks** section.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the parameters are valid, **SetupDiGetDeviceInfoListDetail** sets values in the *DeviceInfoSetDetailData* structure (except for the **cbSize** field) and returns status NO_ERROR.

A caller of **SetupDiGetDeviceInfoListDetail** must set *DeviceInfoSetDetailData.***cbSize** to **sizeof**(SP_DEVINFO_LIST_DETAIL_DATA) or the function will fail and the call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INVALID_USER_BUFFER.

If **SetupDiGetDeviceInfoListDetail** completes successfully, *DeviceInfoSetDetailData.***ClassGuid** contains the class GUID associated with the device information set or a GUID_NULL structure.

If **SetupDiGetDeviceInfoListDetail** completes successfully and the device information set is for a remote system, *DeviceInfoSetDetailData.***RemoteMachineHandle** contains the ConfigMgr32 system handle for accessing the remote system and *DeviceInfoSetDetailData.***RemoteMachineName** contains the name of the remote system. If there is a remote handle for the device information set, it must be used when calling **CM_***Xxx***_Ex** functions because the DevInst handles are relative to the remote handle.

If the device information set is for the local computer, *DeviceInfoSetDetailData.***RemoteMachineHandle** is **NULL** and *DeviceInfoSetDetailData.***RemoteMachineName** is an empty string.

> [!NOTE]
> The setupapi.h header defines SetupDiGetDeviceInfoListDetail as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiCreateDeviceInfoListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolistexa)

[SetupDiGetClassDevsEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsexa)

[SetupDiGetDeviceInfoListClass](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistclass)