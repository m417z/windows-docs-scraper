## Description

Gets the driver property bag.

This property is read-only.

## Parameters

### `ppPropertyBag`

Defines the **IPrinterPropertyBag** parameter *ppPropertyBag*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

The driver property bag uses the following GUID for its property store format ID:

```cpp
DEFINE_GUID(FMTID_PrinterPropertyBag, 0x75f9adca, 0x097d, 0x45c3, 0xa6, 0xe4, 0xba, 0xb2, 0x9e, 0x27, 0x6f, 0x3e);
```

## See also

[IPrinterExtensionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensioncontext)

[IPrinterPropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterpropertybag)