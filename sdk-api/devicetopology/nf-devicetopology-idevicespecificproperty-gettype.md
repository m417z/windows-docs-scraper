# IDeviceSpecificProperty::GetType

## Description

The **GetType** method gets the data type of the device-specific property value.

## Parameters

### `pVType` [out]

Pointer to a **VARTYPE** variable into which the method writes a **VARTYPE** enumeration value that indicates the data type of the device-specific property value. For more information about **VARTYPE** and **VARTYPE**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pVType* is **NULL**. |

## See also

[IDeviceSpecificProperty Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicespecificproperty)