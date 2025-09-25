# IDiscMaster2::get_IsSupportedEnvironment

## Description

Retrieves a value that determines if the environment contains one or more optical devices and the execution context has permission to access the devices.

## Parameters

### `value`

Is VARIANT_TRUE if the environment contains one or more optical devices and the execution context has permission to access the devices; otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

This method loops through all the strings in [IDiscMaster2](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscmaster2-get_item) and attempts to use each string to initialize a [DiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) object. If any of the recorders on the system succeed the initialization, this method returns **TRUE**.

The environment must contain at least one type-5 optical device.

## See also

[IDiscMaster2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscmaster2)