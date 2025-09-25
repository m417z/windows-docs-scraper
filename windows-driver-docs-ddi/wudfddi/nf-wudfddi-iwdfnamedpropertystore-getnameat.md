# IWDFNamedPropertyStore::GetNameAt

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetNameAt** method retrieves the name of a property.

## Parameters

### `iProp` [in]

The zero-based index of the property that **GetNameAt** retrieves the name from.

### `ppwszName` [out]

A pointer to a variable that receives a pointer to a **NULL**-terminated string that contains the name of the property. The caller needs to release the returned buffer using delete[].

## Return value

**GetNameAt** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

For more information, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

## See also

[IWDFNamedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore)