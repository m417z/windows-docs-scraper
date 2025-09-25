# XMLoadXDec4 function

## Description

Loads an [XMXDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdec4) into an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type).

## Parameters

### `pSource` [in]

Address of the [XMXDEC4](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/ns-directxpackedvector-xmxdec4) structure to load.

## Return value

Returns an [XMVECTOR](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) loaded with the data from the *pSource* parameter.

## Remarks

The following pseudocode demonstrates the operation of the function.

```
XMVECTOR vectorOut;

uint32_t Element;
static const uint32_t SignExtend[] = {0x00000000, 0xFFFFFC00};

Element = pSource->v & 0x3FF;
vectorOut.x = (float)(int16_t)(Element | SignExtend[Element >> 9]);
Element = (pSource->v >> 10) & 0x3FF;
vectorOut.y = (float)(int16_t)(Element | SignExtend[Element >> 9]);
Element = (pSource->v >> 20) & 0x3FF;
vectorOut.z = (float)(int16_t)(Element | SignExtend[Element >> 9]);
vectorOut.w = (float)(pSource->v >> 30);

return vectorOut;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Vector Load Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-load)