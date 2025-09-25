# CM_Get_Device_ID_List_SizeW function

## Description

The **CM_Get_Device_ID_List_Size** function retrieves the buffer size required to hold a list of [device instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for the local machine's [device instances](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `pulLen` [out]

Receives a value representing the required buffer size, in characters.

### `pszFilter` [in, optional]

Caller-supplied pointer to a character string specifying a subset of the machine's device instance identifiers, or **NULL**. See the following description of *ulFlags*.

### `ulFlags` [in]

One of the optional, caller-supplied bit flags that specify search filters. If no flags are specified, the function supplies the buffer size required to hold all instance identifiers for all device instances. For a list of bit flags, see the *ulFlags* description for [CM_Get_Device_ID_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_lista).

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The **CM_Get_Device_ID_List_Size** function should be called to determine the buffer size required by [CM_Get_Device_ID_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_lista).

The size value supplied in the location pointed to by *pulLen* is guaranteed to represent a buffer size large enough to hold all device instance identifier strings and terminating NULLs. The supplied value might actually represent a buffer size that is larger than necessary, so don't assume the value represents the true length of the character strings that [CM_Get_Device_ID_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_lista) will provide.

For information about device instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

> [!NOTE]
> The cfgmgr32.h header defines CM_Get_Device_ID_List_Size as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CM_Get_Device_ID_List_Size_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_size_exw)