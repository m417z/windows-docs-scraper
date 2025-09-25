# IEnumWIA_FORMAT_INFO::Next

## Description

The **IEnumWIA_FORMAT_INFO::Next** method returns an array of [WIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_format_info) structures.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of elements requested.

### `rgelt` [out]

Type: **[WIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_format_info)***

Receives the address of the array of [WIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_format_info) structures.

### `pceltFetched` [in, out]

Type: **ULONG***

On output, receives the address of a **ULONG** that contains the number of [WIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_format_info) structures actually returned in the *rgelt* parameter.

## Return value

Type: **HRESULT**

If the enumeration is continuing, this method returns S_OK and sets the value pointed to by *pceltFetched* to the number of capabilities returned. If the enumeration is complete, it returns S_FALSE and sets the value pointed to by *pceltFetched* to zero. If the method fails, it returns a standard COM error.