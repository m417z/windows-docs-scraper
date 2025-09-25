# WSDCreateUdpAddress function

## Description

Creates an [IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress) object.

## Parameters

### `ppAddress` [in]

An [IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress) interface pointer. This parameter cannot be **NULL**.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppAddress* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |