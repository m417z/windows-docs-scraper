# IDeviceSpecificProperty::Get4BRange

## Description

The **Get4BRange** method gets the 4-byte range of the device-specific property value.

## Parameters

### `plMin` [out]

Pointer to a **LONG** variable into which the method writes the minimum property value.

### `plMax` [out]

Pointer to a **LONG** variable into which the method writes the maximum property value.

### `plStepping` [out]

Pointer to a **LONG** variable into which the method writes the stepping value between consecutive property values in the range **plMin* to **plMax*. If the difference between the maximum and minimum property values is *d*, and the range is divided into *n* steps (uniformly sized intervals), then the property can take *n* + 1 discrete values and the size of the step between consecutive values is d / n.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *plMin*, *plMax*, or *plStepping* is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The property value is not a 32-bit signed or unsigned integer. For information about this macro, see the Windows SDK documentation. |

## Remarks

This method reports the range and step size for a property value that is a 32-bit signed or unsigned integer. These two data types are represented by **VARENUM** enumeration constants VT_I4 and VT_UI4, respectively. If the property value is not a 32-bit integer, then the method returns an error status code. For more information about **VARENUM**, see the Windows SDK documentation.

## See also

[IDeviceSpecificProperty Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicespecificproperty)