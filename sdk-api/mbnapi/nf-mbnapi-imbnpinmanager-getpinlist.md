# IMbnPinManager::GetPinList

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets a list of different PIN types supported by the device.

## Parameters

### `pinList` [out, retval]

A pointer to a list of [MBN_PIN_TYPE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_pin_type) values that represent the PIN types supported by the device. When **GetPinList** returns anything other than **S_OK**, *pinList* is **NULL**, otherwise the calling application must free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_PENDING** | The PIN types are not available. The Mobile Broadband service is currently probing the device to get the information. When the PIN types are available, the Mobile Broadband service will call the [OnPinListAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanagerevents-onpinlistavailable) method of [IMbnPinManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanagerevents). |
| **E_MBN_PIN_REQUIRED** | The device requires that a PIN must be entered for this operation. |
| **E_MBN_SIM_NOT_INSERTED** | The SIM is not inserted. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |

## Remarks

On the recoverable errors **E_MBN_PIN_REQUIRED**, **E_MBN_SIM_NOT_INSERTED**, and **E_MBN_BAD_SIM**, the Mobile Broadband service will attempt to retrieve this information from the device when the error condition is over. While it is retrieving this information **GetPinList** call will return **E_PENDING**. Once the retrieval operation is complete, the Mobile Broadband service will call the [OnPinListAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanagerevents-onpinlistavailable) method of [IMbnPinManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanagerevents).

## See also

[IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager)