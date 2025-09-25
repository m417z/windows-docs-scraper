# IDiscMaster2::get__NewEnum

## Description

Retrieves a list of the CD and DVD devices installed on the computer.

## Parameters

### `ppunk` [out]

An **IEnumVariant** interface that you use to enumerate the CD and DVD devices installed on the computer. The items of the enumeration are variants whose type is **VT_BSTR**. Use the **bstrVal** member to retrieve the unique identifier of the device.

## Return value

S_OK is returned when the number of requested elements (*celt*) are returned successfully or the number of returned items (*pceltFetched*) is less than the number of requested elements. The *celt* and *pceltFetched* parameters are defined by **IEnumVariant**.

Other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The enumeration is a snapshot of the devices on the computer at the time of the call and will not reflect devices that are added and removed. To receive notification when a device is added or removed from the computer, implement the [DDiscMaster2Events](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscmaster2events) interface.

To retrieve a single identifier, see the [IDiscMaster2::get_Item](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscmaster2-get_item) property.

The device identifier is guaranteed to be unique and static for a given device as recognized by Windows Plug and Play. You can use the identifier as a key value for saving the user's default burner, and can also be used to cache other device-specific static information (for example, VendorID and ProductID) by an advanced application.

## See also

[IDiscMaster2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscmaster2)

[IDiscMaster2::get_Count](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscmaster2-get_count)