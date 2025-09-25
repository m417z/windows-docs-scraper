# SP_DEVINFO_LIST_DETAIL_DATA_W structure

## Description

An SP_DEVINFO_LIST_DETAIL_DATA structure contains information about a device information set, such as its associated setup class GUID (if it has an associated setup class).

## Members

### `cbSize`

The size, in bytes, of the SP_DEVINFO_LIST_DETAIL_DATA structure.

### `ClassGuid`

The setup class GUID that is associated with the device information set or GUID_NULL if there is no associated setup class.

### `RemoteMachineHandle`

If the device information set is for a remote computer, this member is a configuration manager machine handle for the remote computer. If the device information set is for the local computer, this member is **NULL**.

This is typically the parameter that components use to access the remote computer. The **RemoteMachineName** contains a string, in case the component requires the name of the remote computer.

### `RemoteMachineName`

A NULL-terminated string that contains the name of the remote computer. If the device information set is for the local computer, this member is an empty string.

## See also

[SetupDiGetDeviceInfoListDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistdetaila)

## Remarks

> [!NOTE]
> The setupapi.h header defines SP_DEVINFO_LIST_DETAIL_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).