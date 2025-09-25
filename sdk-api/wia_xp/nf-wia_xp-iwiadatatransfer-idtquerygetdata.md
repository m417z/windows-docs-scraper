# IWiaDataTransfer::idtQueryGetData

## Description

The **IWiaDataTransfer::idtQueryGetData** method is used by applications to query a Windows Image Acquisition (WIA) device to determine what types of data formats it supports.

## Parameters

### `pfe` [in]

Type: **[WIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_format_info)***

Pointer to a [WIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_format_info) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns S_OK. Otherwise it returns a value specified in [Error Codes](https://learn.microsoft.com/windows/desktop/wia/-wia-error-codes), or a standard COM error.

## Remarks

This method queries a device to determine the data formats it supports. Prior to a data transfer, an application can fill in the [WIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_format_info) structure with the intended medium and data format information. It then calls **IWiaDataTransfer::idtQueryGetData** and receives a return value of S_OK if the data format and media type are supported by this device.