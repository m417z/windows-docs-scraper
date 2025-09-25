# _IFaxServerNotify2::OnDeviceStatusChange

## Description

The fax service calls the **IFaxServerNotify2::OnDeviceStatusChange** method when there is a change to a fax device status.

## Parameters

### `pFaxServer`

Type: **[IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2)***

A [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) object.

### `lDeviceId`

Type: **long**

Long value that contains the ID of the device for which the status has changed.

### `bPoweredOff`

Type: **VARIANT_BOOL**

Boolean value. If this parameter is equal to **TRUE**, the fax device is currently offline and unavailable for sending and receiving faxes. If this parameter is equal to **FALSE**, the fax device is online and available.

### `bSending`

Type: **VARIANT_BOOL**

Boolean value. If this parameter is equal to **TRUE**, the fax device is sending faxes. If this parameter is equal to **FALSE**, the fax device is not sending faxes.

### `bReceiving`

Type: **VARIANT_BOOL**

Boolean value. If this parameter is equal to **TRUE**, the fax device is receiving faxes. If this parameter is equal to **FALSE**, the fax device is not receiving faxes.

### `bRinging`

Type: **VARIANT_BOOL**

Boolean value. If this parameter is equal to **TRUE**, the fax device is ringing. If this parameter is equal to **FALSE**, the fax device is not ringing.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure. For an example, see [Registering for Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registering-for-fax-events).

## See also

[IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2)