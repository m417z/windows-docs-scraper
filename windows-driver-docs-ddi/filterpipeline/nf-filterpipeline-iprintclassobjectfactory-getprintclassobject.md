# IPrintClassObjectFactory::GetPrintClassObject

## Description

The **GetPrintClassObject** method creates a print filter-related object for a specified printer by using the IID of the interface object to create.

## Parameters

### `pszPrinterName` [in]

The printer name.

### `riid` [in]

The IID of the interface to create. Filters should use IID_IPrintAsyncNotify to create notification channels.

### `ppNewObject` [out]

The new object that this method creates.

## Return value

**GetPrintClassObject** returns an **HRESULT** value.