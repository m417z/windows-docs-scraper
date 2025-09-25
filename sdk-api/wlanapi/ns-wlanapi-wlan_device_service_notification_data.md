## Description

A structure that represents a device service notification.

## Members

### `DeviceService`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The **GUID** identifying the device service for this notification.

### `dwOpCode`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The opcode that identifies the operation under the device service for this notification.

### `dwDataSize`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size, in bytes, of the *DataBlob* member. The maximum value of *dwDataSize* may be restricted by the type of data that is stored in the **WLAN_DEVICE_SERVICE_NOTIFICATION_DATA** structure.

### `DataBlob`

Type: **[BYTE](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)\[1\]**

A pointer to an array containing **BYTES**s, representing the data blob. This is the data that is received from the independent hardware vendor (IHV) driver, and is passed on to the client as an unformatted byte array blob.

## Remarks

## See also