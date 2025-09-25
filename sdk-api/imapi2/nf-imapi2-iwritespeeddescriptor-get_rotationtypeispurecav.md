# IWriteSpeedDescriptor::get_RotationTypeIsPureCAV

## Description

Retrieves the supported rotational-speed control used by the recorder for the current media.

## Parameters

### `value` [out]

Is VARIANT_TRUE if constant angular velocity (CAV) rotational-speed control is in use. Otherwise, VARIANT_FALSE to indicate that another rotational-speed control that the recorder supports is in use.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

Rotational-speed control types include the following:

* CLV (Constant Linear Velocity). The disc is written at a constant speed. Standard rotational control.
* CAV (Constant Angular Velocity). The disc is written at a constantly increasing speed.
* ZCAV (Zone Constant Linear Velocity). The disc is divided into zones. After each zone, the write speed increases. This is an impure form of CAV.
* PCAV (Partial Constant Angular Velocity). The disc speed increases up to a specified velocity. Once reached, the disc spins at the specified velocity for the duration of the disc writing.

## See also

[IWriteSpeedDescriptor](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwritespeeddescriptor)