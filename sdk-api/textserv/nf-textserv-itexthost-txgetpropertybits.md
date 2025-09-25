# ITextHost::TxGetPropertyBits

## Description

Requests the bit property settings for the text host.

## Parameters

### `dwMask` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask of properties in which the caller is interested. For the possible bit values, see
*dwBits* in [OnTxPropertyBitsChange](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxpropertybitschange).

### `pdwBits` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The current settings for the properties specified by
*dwMask*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is **S_OK**.

## Remarks

This call is valid at any time, for any combination of requested property bits.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)