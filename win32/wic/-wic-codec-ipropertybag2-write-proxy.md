# IPropertyBag2\_Write\_Proxy function

Windows Imaging Component (WIC) proxy function for IPropertyBag2::Write.

## Parameters

*THIS\_PTR* \[in\]

Type: **[IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85))\***

PARAMDESC

*cProperties* \[in\]

Type: **ULONG**

*ppropBag* \[in\]

Type: **[PROPBAG2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768188(v=vs.85))\***

*pvarValue* \[in\]

Type: **VARIANT\***

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Windowscodecs.dll; <br>Wincodec.lib |

