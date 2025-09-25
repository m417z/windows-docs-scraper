# IMFSensorActivityReport::GetProcessActivity

## Description

Gets an [IMFSensorProcessActivity](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprocessactivity) object representing the current process activity of a sensor.

## Parameters

### `Index` [in]

The index of the [IMFSensorProcessActivity](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprocessactivity) to retrieve. This value must be less than the value returned by [GetProcessCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensoractivityreport-getprocesscount).

### `ppProcessActivity` [in]

 A pointer to the [IMFSensorProcessActivity](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprocessactivity) associated with the specified index.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppProcessActivity* parameter is null. |

## See also

[IMFSensorActivityReport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensoractivityreport)