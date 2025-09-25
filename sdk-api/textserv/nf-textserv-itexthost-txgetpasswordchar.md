# ITextHost::TxGetPasswordChar

## Description

Requests the text host's password character.

## Parameters

### `pch` [out]

Type: **[TCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The password character.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the password character is enabled.

Return S_FALSE if the password character is not enabled. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

The password character is only shown if the TXTBIT_USEPASSWORD bit is enabled in the text services object. If the password character changes, re-enable the TXTBIT_USEPASSWORD bit through [OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange).

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)