# IMFAttributes::GetCount

## Description

Retrieves the number of attributes that are set on this object.

## Parameters

### `pcItems` [out]

Receives the number of attributes. This parameter must not be **NULL**. If this parameter is **NULL**, an access violation occurs.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To enumerate all of the attributes, call [IMFAttributes::GetItemByIndex](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getitembyindex) for each index value.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)