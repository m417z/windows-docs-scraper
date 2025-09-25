# IMFAttributes::SetDouble

## Description

Associates a **double** value with a key.

## Parameters

### `guidKey` [in]

GUID that identifies the value to set. If this key already exists, the method overwrites the old value.

### `fValue` [in]

New value for this key.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To retrieve the double value, call [IMFAttributes::GetDouble](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getdouble).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)